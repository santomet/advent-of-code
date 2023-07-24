#include "aoc2022.h"
#include "utilities.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <sstream>
#include <limits>
#include <map>

#include <QTextStream>
#include <QString>

using namespace std;


AoC2022::AoC2022()
{
    int day_01_1(void);
    int day_01_2(void);

    int day_02_1(void);
    int day_02_2(void);

    int day_03_1(void);
    int day_03_2(void);

    int day_04_1(void);
    int day_04_2(void);

    string day_05_1(void);

    int day_06_1(void);
    int day_06_2(void);

    int day_07_1(void);
}

// Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?
int AoC2022::day_01_1()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_01.txt");
    if (!file.is_open()) return -1;

    string line;
    int max = 0;
    int sum = 0;

    while (getline(file, line)) {
        if (line.empty()) {
            if (max < sum) {
                max = sum;
            }
            sum = 0;
            continue;
        }

        sum += stoi(line);
    }
    file.close();

    return max;
}

// Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
int AoC2022::day_01_2()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_01.txt");
    if (!file.is_open()) return -1;

    string line;
    int sum = 0;

    int max1 = 0;
    int max2 = 0;
    int max3 = 0;

    while (getline(file, line)) {
       if (line.empty()) {
           if (sum > max1) {
                max3 = max2;
                max2 = max1;
                max1 = sum;
           } else if (sum > max2) {
               max3 = max2;
               max2 = sum;
           } else if (sum > max3) {
               max3 = sum;
           }
           sum = 0;
        } else {
            sum += stoi(line);
        }
    }


    file.close();

    return (max1 + max2 + max3);
}


// What would your total score be if everything goes exactly according to your strategy guide?
int AoC2022::day_02_1()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_02.txt");
    if (!file.is_open()) return -1;

    string line, elf_choice, elf_suggestion;
    int score = 0;

    while (getline(file, line)) {
        elf_choice = line.substr(0, 1); // strtok_r(line, " , "); --- didn't work out
        elf_suggestion = line.substr(2, 1);

        // Getting points for shape you selected - 1, 2, 3
        if (!elf_suggestion.compare("X")) {
            score += 1;
        } else if (!elf_suggestion.compare("Y")) {
            score += 2;
        } else if (!elf_suggestion.compare("Z")) {
            score += 3;
        }

        // Getting points for outcome of the round - 0, 3, 6
        if (!elf_suggestion.compare("X") && !elf_choice.compare("A")) { // draw
            score += 3;
        } else if (!elf_suggestion.compare("X") && !elf_choice.compare("B")) {
            continue;
        } else if (!elf_suggestion.compare("X") && !elf_choice.compare("C")) {
            score += 6;
        } else if (!elf_suggestion.compare("Y") && !elf_choice.compare("A")) {
            score += 6;
        } else if (!elf_suggestion.compare("Y") && !elf_choice.compare("B")) { // draw
            score += 3;
        } else if (!elf_suggestion.compare("Y") && !elf_choice.compare("C")) {
            continue;
        } else if (!elf_suggestion.compare("Z") && !elf_choice.compare("A")) {
            continue;
        } else if (!elf_suggestion.compare("Z") && !elf_choice.compare("B")) {
            score += 6;
        } else if (!elf_suggestion.compare("Z") && !elf_choice.compare("C")) { // draw
            score += 3;
        }
    }

    return score;
}

// Following the Elf's instructions for the second column,
//      what would your total score be if everything goes exactly according to your strategy guide?
int AoC2022::day_02_2()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_02.txt");
    if (!file.is_open()) return -1;

    string line, elf_choice, round_end;
    int score = 0;

    while (getline(file, line)) {
        elf_choice = line.substr(0, 1);
        round_end = line.substr(2, 1);

        // X - need to lose
        // Y - need to end up in draw
        // Z - need to win

        // Getting points for shape + points for outcome of the round - 1, 2, 3 + 0, 3, 6
        if (!elf_choice.compare("A") && !round_end.compare("X")) {
            score += 3;
        } else if (!elf_choice.compare("A") && !round_end.compare("Y")) { // draw
            score += 1 + 3;
        } else if (!elf_choice.compare("A") && !round_end.compare("Z")) {
            score += 2 + 6;
        } else if (!elf_choice.compare("B") && !round_end.compare("X")) {
            score += 1;
        } else if (!elf_choice.compare("B") && !round_end.compare("Y")) { // draw
            score += 2 + 3;
        } else if (!elf_choice.compare("B") && !round_end.compare("Z")) {
            score += 3 + 6;
        } else if (!elf_choice.compare("C") && !round_end.compare("X")) {
            score += 2;
        } else if (!elf_choice.compare("C") && !round_end.compare("Y")) { // draw
            score += 3 + 3;
        } else if (!elf_choice.compare("C") && !round_end.compare("Z")) {
            score += 1 + 6;
        }
    }

    return score;
}


// Find the item type that appears in both compartments of each rucksack.
    // What is the sum of the priorities of those item types?
int AoC2022::day_03_1()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_03.txt");
    if (!file.is_open()) return -1;

    string line, first_compartment, second_compartment;
    int length = 0, priority_sum = 0;

    LOOP:while (getline(file, line)) {
        length = line.length();
        first_compartment = line.substr(0, length / 2);
        second_compartment = line.substr(length / 2, length);

        for (int i = 0; i < first_compartment.length(); i++) {
            for (int j = 0; j < first_compartment.length(); j++) {
                if (first_compartment[i] == second_compartment[j]) {
                   if (islower(first_compartment[i])) {
                       priority_sum += first_compartment[i] - 96;
                       goto LOOP;
                   }

                   priority_sum += first_compartment[i] - 38;
                   goto LOOP;
                }
            }
        }
    }

    return priority_sum;
}

// Find the item type that corresponds to the badges of each three-Elf group.
    // What is the sum of the priorities of those item types?
int AoC2022::day_03_2()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_03.txt");
    if (!file.is_open()) return -1;

    string line1, line2, line3;
    int priority_sum = 0;

    LOOP:while (getline(file, line1) && getline(file, line2) && getline(file, line3)) {

        for (int i = 0; i < line1.length(); i++) {
            for (int j = 0; j < line2.length(); j++) {
                if (line1[i] == line2[j]) {
                    for (int k = 0; k < line3.length(); k++) {
                        if (line1[i] == line3[k]) {
                            if (islower(line1[i])) {
                                priority_sum += line1[i] - 96;
                                goto LOOP;
                            }

                            priority_sum += line1[i] - 38;
                            goto LOOP;
                       }
                   }
                }
            }
        }
    }

    return priority_sum;
}


// In how many assignment pairs does one range fully contain the other?
int AoC2022::day_04_1()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_04.txt");
    if (!file.is_open()) return -1;

    string line;
    int result = 0, check = 1;
    vector<int> part1, part2;

    while (getline(file, line)) {
        vector<string> tokens = Utilities::splitString(line, ',');

        for (vector<string>::const_iterator it = tokens.begin(), end_it = tokens.end(); it != end_it; ++it) {
            const string& token = *it;
            vector<string> range = Utilities::splitString(token, '-');
            if (check == 1) {
                Utilities::addStartEnd(part1, range[0], range[1]);
                check++;
                continue;
            }
            Utilities::addStartEnd(part2, range[0], range[1]);
            check = 1;
        }

        if ((part1[0] <= part2[0] && part1[1] >= part2[1]) || (part2[0] <= part1[0] && part2[1] >= part1[1])) {
            result++;
        }
    }

    return result;
}

// In how many assignment pairs do the ranges overlap?
int AoC2022::day_04_2()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_04.txt");
    if (!file.is_open()) return -1;

    string line;
    int result = 0, check = 1;
    vector<int> part1, part2;

    while (getline(file, line)) {
        vector<string> tokens = Utilities::splitString(line, ',');

        for (vector<string>::const_iterator it = tokens.begin(), end_it = tokens.end(); it != end_it; ++it) {
            const string& token = *it;
            vector<string> range = Utilities::splitString(token, '-');
            if (check == 1) {
                Utilities::addStartEnd(part1, range[0], range[1]);
                check++;
                continue;
            }
            Utilities::addStartEnd(part2, range[0], range[1]);
            check = 1;
        }

        if ((part1[0] <= part2[1] && part2[0] <= part1[1])) {
            result++;
        }
    }

    return result;
}



// After the rearrangement procedure completes, what crate ends up on top of each stack?
string AoC2022::day_05_1()
{
    fstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_05.txt");
    if (!file.is_open()) return "-1";

    string line, result = "NO RESULT YET";
    // vector<vector<string>> stacks;
    vector<vector<string>> crates {
        {"N", "", "", "C", "", "Z"},
        {"Q", "G", "", "V", "", "S", "", "", "V"},
        {"L", "C", "", "M", "", "T", "", "W", "L"},
        {"S", "H", "", "L", "", "C", "D", "H", "S"},
        {"C", "V", "F", "D", "", "D", "B", "Q", "F"},
        {"Z", "T", "Z", "T", "C", "J", "G", "S", "Q"},
        {"P", "P", "C", "W", "W", "F", "W", "J", "C"},
        {"T", "L", "D", "G", "P", "P", "V", "N", "R"},
    };

    Utilities::writeOutStack(crates);

    Utilities::goToLine(file, 11);

    getline(file, line);
    QTextStream qout(stdout);
    qout << QString::fromStdString(line);

    // read the stacks of crates
    // for (int i = 0; getline(file, line) && i < 8; i++) {
        // parseInputCratesStacks(stack, line);
    // }

    // read the stacks of crates
    // for (int i = 0; getline(file, line) && i < 8; i++) {
        // while (line.find("[", i) != string::npos) {
            // int char_index = line.find("[", i);
            // char crate = line[char_index + 1];
            // QTextStream qout(stdout);
            // qout << crate;

            // // // stacks[(charIndex/4)+1]!!.addFirst(crate)
            // // stacks[(char_index / 4) + 1].insert(stacks[i].begin() + i, "");
            // // // stacks[(char_index / 4) + 1].insert(stacks[i].begin() + i, crate);
            // // stacks[(char_index / 4) + 1][i] += crate;

            // // // skip over this crate definition, which is 3 characters
            // i += 3;
    // }
    // }



    // read the stacks of crates


    // // getline(file, line);
    // QTextStream qout(stdout);
    // qout << QString::fromStdString(stack[0][0]);


    // while (getline(file, line)) {
        // vector<string> instruction = splitStringToArray(line, ' ');

        // for (vector<string>::const_iterator it = instruction.begin(), end_it = instruction.end(); it != end_it; ++it) {
            // const string& token = *it;
            // vector<string> range = splitStringToArray(token, '-');
        // }
    // }

    return result;
}


// How many characters need to be processed before the first start-of-packet marker is detected?
int AoC2022::day_06_1()
{
    fstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_06.txt");
    if (!file.is_open()) return -1;

    string input, part;
    getline(file, input);

    int i = 0, check = 0;

    LOOP:while (i + 4 < input.length()) {
        part = input.substr(i, 4);

        for (int j = 0; j < part.length(); j++) {
            for (int k = 0; k < part.length(); k++) {
                if (part[j] == part[k] && j != k) {
                    i++;
                    check = 0;
                    goto LOOP;
                }
                check++;
                if (check == 16) {
                    return i + 4;
                }
            }
        }
        i++;
        check = 0;
    }

    return 0;
}

// How many characters need to be processed before the first start-of-message marker is detected?
int AoC2022::day_06_2()
{
    fstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_06.txt");
    if (!file.is_open()) return -1;

    string input, part;
    getline(file, input);

    int i = 0, check = 0;

    LOOP:while (i + 14 < input.length()) {
        part = input.substr(i, 14);

        for (int j = 0; j < part.length(); j++) {
            for (int k = 0; k < part.length(); k++) {
                if (part[j] == part[k] && j != k) {
                    i++;
                    check = 0;
                    goto LOOP;
                }
                check++;
                if (check == 196) {
                    return i + 14;
                }
            }
        }
        i++;
        check = 0;
    }

    return 0;
}


// Find all of the directories with a total size of at most 100000.
    // What is the sum of the total sizes of those directories?
int AoC2022::day_07_1() {
    fstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_07.txt");
    if (!file.is_open()) return -1;

    // string line, file_name;
    // elf_directory current;
    // int sum = 0, total_sum = 0, dir_count = 0;
    // vector<string> line_part;
    // vector<elf_directory> sum_array;

    // // root dir
    // elf_directory *root = make_dir("/", NULL);
    // parent_array.push_back(*root);
    // sum_map["/"] = *root;


    // goToLine(file, 2);

    // while(getline(file, line)) {
        // line_part = splitStringToArray(line, ' ');
        // parent_dir = parent_array[dir_count];

        // if (line_part[0] == "$" && line_part[1] == "cd") {
            // if (line.substr(line.length() - 2, 2) == "..") { // TODO
                // dir_count--;
            // } else {
                // dir_count++;
            // }
        // } else if (line.substr(0, 3) == "dir") {
            // sum_map[line.substr(4, line.length() - 5)] = *make_dir(line.substr(4, line.length() - 5), &parent_dir);
        // } else if (isnumber(line[0])) {
            // line_part = splitStringToArray(line, ' ');
            // add_file(&parent_dir, make_file(line_part[1], stoi(line_part[0])));
        // }
    // }
    // print_dir(root);


    return 0;
}






























