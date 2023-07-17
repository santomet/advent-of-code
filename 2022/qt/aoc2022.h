#ifndef AOC2022_H
#define AOC2022_H

#include <iostream>
#include <vector>

using namespace std;

class AoC2022
{
public:
    AoC2022();
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

private:
    void addMax(vector<int> *top, int new_value); // Day 1
    vector<string> splitStringToArray(const string& str, char splitter); // Day 4
    void addStartEnd(vector<int> &array, string item1, string item2); // Day 4
    void parseInputCratesStacks(vector<vector<string>>& crates, string& line); // Day 5
    void writeOutStack(vector<vector<string>> crates); // Day 5
    fstream& goToLine(fstream& file, unsigned int num); // Day 5
};

#endif // AOC2022_H
