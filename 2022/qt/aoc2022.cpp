#include "aoc2022.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

AoC2022::AoC2022()
{

    int day_01_1(void);
    int day_01_2(void);
    void addMax(vector<int> *top, int new_value);
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
