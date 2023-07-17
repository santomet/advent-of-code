#include "aoc2022.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <sstream>
#include <limits>

#include <QTextStream>
#include <QString>

using namespace std;

AoC2022::AoC2022()
{

    int day_01_1(void);
    int day_01_2(void);
    void addMax(vector<int> *top, int new_value);

    int day_02_1(void);
    int day_02_2(void);

    int day_03_1(void);
    int day_03_2(void);

    int day_04_1(void);
    int day_04_2(void);
    vector<string> splitStringToArray(const string& str, char splitter);
    void addStartEnd(vector<int> &array, string item1, string item2);

    string day_05_1(void);
    void parseInputCratesStacks(vector<vector<string>>& crates, string& line);
    void writeOutStack(vector<vector<string>> crates);
    fstream& goToLine(fstream& file, unsigned int num);
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

void AoC2022::addMax(vector<int> *top, int new_value)
{
    int min_index = 0;
    for (int i = 0; i < 3; i++) {
        if (top[i] < top[min_index]) {
           min_index = i;
        }
    }

    if (new_value > top->at(min_index)) {
        // top[min_index] = new_value;
        top->insert(top->begin() + min_index, new_value);
    }
}

// Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
int AoC2022::day_01_2()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_01.txt");
    if (!file.is_open()) return -1;

    // The top three
    vector<int> top(3);

    string line;
    int sum = 0;

    // while (getline(file, line)) {
       // if (line.empty()) {
            // addMax(&top, sum);
            // sum = 0;
            // continue;
        // }

        // sum += stoi(line);
    // }
    // addMax(&top, sum);

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


vector<string> AoC2022::splitStringToArray(const string& str, char splitter)
{
    vector<string> tokens;
    stringstream ss(str);
    string temp;
    // split into new "lines" based on character
    while (getline(ss, temp, splitter)) {
        tokens.push_back(temp);
    }
    return tokens;
}

void AoC2022::addStartEnd(vector<int> &array, string item1, string item2)
{
    array.insert(array.begin(), stoi(item1));
    array.insert(array.begin() + 1, stoi(item2));

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
        vector<string> tokens = splitStringToArray(line, ',');

        for (vector<string>::const_iterator it = tokens.begin(), end_it = tokens.end(); it != end_it; ++it) {
            const string& token = *it;
            vector<string> range = splitStringToArray(token, '-');
            if (check == 1) {
                addStartEnd(part1, range[0], range[1]);
                check++;
                continue;
            }
            addStartEnd(part2, range[0], range[1]);
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
        vector<string> tokens = splitStringToArray(line, ',');

        for (vector<string>::const_iterator it = tokens.begin(), end_it = tokens.end(); it != end_it; ++it) {
            const string& token = *it;
            vector<string> range = splitStringToArray(token, '-');
            if (check == 1) {
                addStartEnd(part1, range[0], range[1]);
                check++;
                continue;
            }
            addStartEnd(part2, range[0], range[1]);
            check = 1;
        }

        if ((part1[0] <= part2[1] && part2[0] <= part1[1])) {
            result++;
        }
    }

    return result;
}


void AoC2022::parseInputCratesStacks(vector<vector<string>>& crates, string& line)
{
    int index = 0;

    while (line.find("[", index) != string::npos) {
        int char_index = line.find("[", index);
        char crate = line[char_index + 1];

        // stacks[(charIndex/4)+1]!!.addFirst(crate)
        crates[(char_index / 4) + 1].insert(crates[index].begin() + index, "");
        crates[(char_index / 4) + 1][index] += crate;

        // // skip over this crate definition, which is 3 characters
        index += 3;
    }
}


void AoC2022::writeOutStack(vector<vector<string>> crates)
{
    QTextStream qout(stdout);
    string pretty;
    // write out the crate stack in pretty format
    for (int i = 0; i < crates.size(); i++) {
        for (int j = 0; j < crates[i].size(); j++) {
            pretty = crates[i][j] == "" ? " " : crates[i][j];
            qout << QString::fromStdString(" " + pretty + " ");
        }
        qout << "\n";
    }
}

fstream& AoC2022::goToLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
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

    writeOutStack(crates);

    goToLine(file, 11);

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


































