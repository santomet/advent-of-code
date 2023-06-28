#include "aoc2022.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

AoC2022::AoC2022()
{

    int day_01(void);
}

int AoC2022::day_01()
{
    ifstream file("/Users/ondrejpazourek/dev/cpp/advent-of-code/2022/qt/data/day_01.txt");
    if (!file.is_open()) return -1;

    string line;
    int max = 0;
    int sum = 0;

    while (getline(file, line)) {
        if (line.length() == 0) { // if blank/empty line than ...
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
