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
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <stack>

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
    string day_05_2(void);

    int day_06_1(void);
    int day_06_2(void);

    int day_07_1(void);
    int day_07_2(void);
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
    auto input = Utilities::readAllLinesInFile("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_05.txt");

    // Find the empty line in out input.
    auto blankIndex = -1;
    for (auto i = 0; i < input.size(); ++i) {
        if (input[i].size() == 0) { // blank line
            blankIndex = i;
            break;
        }
    }

    // Setup initial state.
    auto stacks = vector<stack<char>>{};
    const auto& stackLabels = input[blankIndex - 1];
    for (auto i = 0; i < stackLabels.size(); ++i) {
        if (stackLabels[i] == ' ') {
            continue;
        }

        auto currentStack = stack<char>{};
        for (auto lineIndex = blankIndex - 2; lineIndex >= 0; --lineIndex) {
            const auto& line = input[lineIndex];
            const auto& crate = line[i];
            if (crate == ' ') {
                break;
            }

            currentStack.push(crate);
        }
        stacks.emplace_back(currentStack);
    }

    // Process moves.
    for (auto i = blankIndex + 1; i < input.size(); ++i) {
        auto tokens = Utilities::splitString(input[i], ' ');
        auto amount = stoi(tokens[1]);
        auto from = stoi(tokens[3]) - 1;
        auto to = stoi(tokens[5]) - 1;

        for (int i = 1; i <= amount; ++i) {
            auto crate = stacks[from].top();
            stacks[from].pop();
            stacks[to].push(crate);
        }
    }

    // Access the top elements.
    string result = "";
    for (const auto& currentStack : stacks) {
        result += currentStack.top();
    }

    return result;
}

// After the rearrangement procedure completes, what crate ends up on top of each stack?
string AoC2022::day_05_2()
{
    auto input = Utilities::readAllLinesInFile("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_05.txt");

    // Find the empty line in out input.
    auto blankIndex = -1;
    for (auto i = 0; i < input.size(); ++i) {
        if (input[i].size() == 0) { // blank line
            blankIndex = i;
            break;
        }
    }

    // Setup initial state.
    auto stacks = vector<stack<char>>{};
    const auto& stackLabels = input[blankIndex - 1];
    for (auto i = 0; i < stackLabels.size(); ++i) {
        if (stackLabels[i] == ' ') {
            continue;
        }

        auto currentStack = stack<char>{};
        for (auto lineIndex = blankIndex - 2; lineIndex >= 0; --lineIndex) {
            const auto& line = input[lineIndex];
            const auto& crate = line[i];
            if (crate == ' ') {
                break;
            }

            currentStack.push(crate);
        }
        stacks.emplace_back(currentStack);
    }

    // Process moves.
    for (auto i = blankIndex + 1; i < input.size(); ++i) {
        auto tokens = Utilities::splitString(input[i], ' ');
        auto amount = stoi(tokens[1]);
        auto from = stoi(tokens[3]) - 1;
        auto to = stoi(tokens[5]) - 1;

        auto crates = vector<char>{};
        while (amount-- > 0) {
            auto crate = stacks[from].top();
            stacks[from].pop();
            crates.emplace_back(crate);
        }

        reverse(crates.begin(), crates.end());

        for (const auto& crate : crates) {
            stacks[to].push(crate);
        }
    }

    // Access the top elements.
    string result = "";
    for (const auto& currentStack : stacks) {
        result += currentStack.top();
    }

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


// DAY 7
// Find all of the directories with a total size of at most 100000.
    // What is the sum of the total sizes of those directories?
struct ElfFile
{
    string path;
    int size = 0;
};

struct ElfDirectory
{
    string path;
    int size = -1;
    unordered_set<string> child_directories;
    unordered_set<string> child_files;

};

auto all_directories = unordered_map<string, ElfDirectory>{};
auto all_files = unordered_map<string, ElfFile>{};

void readInput7()
{
    auto input = Utilities::readAllLinesInFile("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_07.txt");

    all_directories["/"] = ElfDirectory{"/"};

    auto pwd = vector<string>{{"/"}};

    for (const auto& line : input) {
        auto tokens = Utilities::splitString(line, ' ');
        if (tokens[0] == "$") {
            if (tokens[1] == "ls") {
                continue;
            } else {
                Utilities::verifyElseCrash(tokens[1] == "cd");
                const auto& target = tokens[2];
                if (target == "/") {
                    pwd.clear();
                    pwd.emplace_back("/");
                } else if (target == "..") {
                    pwd.pop_back();
                } else {
                    pwd.emplace_back(pwd.back() + target + "/");
                }
            }
        } else {
            auto& parent = all_directories.at(pwd.back());
            if (tokens[0] == "dir") {
                auto path = pwd.back() + tokens[1] + "/";
                if (all_directories.find(path) == all_directories.end()) {
                    all_directories[path] = ElfDirectory{ path };
                }

                parent.child_directories.insert(path);
            } else {
                auto path = pwd.back() + tokens[1];
                if (all_files.find(path) == all_files.end()) {
                    all_files[path] = ElfFile{ path, stoi(tokens[0]) };
                }

                parent.child_files.insert(path);
            }
        }
    }

}

int CalculateDirectorySize(ElfDirectory& directory) {
    if (directory.size >= 0) {
        return directory.size;
    }

    int totalSizeOfFiles = std::accumulate(directory.child_files.begin(), directory.child_files.end(), 0,
                                           [](int sum, const std::string& path) { return sum + all_files.at(path).size; });

    int totalSizeOfDirectories = 0;
    for (const std::string& path : directory.child_directories) {
        totalSizeOfDirectories += CalculateDirectorySize(all_directories.at(path));
    }

    directory.size = totalSizeOfFiles + totalSizeOfDirectories;
    return directory.size;
}

int AoC2022::day_07_1() {
    readInput7();
    CalculateDirectorySize(all_directories.at("/"));

    auto total_dir_size = std::accumulate(all_directories.begin(), all_directories.end(), 0,
                                        [](int sum, const std::pair<std::string, ElfDirectory>& directoryPair) {
                                            const ElfDirectory& directory = directoryPair.second;
                                            return sum + (directory.size <= 100000 ? directory.size : 0);
                                        });

    return total_dir_size;
}

int AoC2022::day_07_2() {
    // Read the input and calculate the size of directories
    readInput7();
    CalculateDirectorySize(all_directories.at("/"));

    constexpr auto totalSpace = 70000000;
    constexpr auto desiredSpace = 30000000;

    // Calculate unused space in the root directory
    const auto unusedSpace = totalSpace - all_directories.at("/").size;

    // Calculate the size to delete from the directories to meet the desired space
    const auto sizeToDelete = desiredSpace - unusedSpace;

    // Get a vector of directories sorted by size
    vector<ElfDirectory> directoriesSortedBySize;
    for (const auto& entry : all_directories) {
        directoriesSortedBySize.push_back(entry.second);
    }
    sort(directoriesSortedBySize.begin(), directoriesSortedBySize.end(),
              [](const ElfDirectory& a, const ElfDirectory& b) { return a.size < b.size; });

    // Find the directory to delete based on the sizeToDelete
    auto deleted_directory_size = 0;
    for (const auto& directory : directoriesSortedBySize) {
        if (directory.size >= sizeToDelete) {
            deleted_directory_size = directory.size;
            break;
        }
    }

    return deleted_directory_size;
}



















