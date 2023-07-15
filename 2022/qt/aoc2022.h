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
private:
    void addMax(vector<int> *top, int new_value);
    vector<string> splitStringToArray(const string& str, char splitter);
    void addStartEnd(vector<int> &array, string item1, string item2);

};

#endif // AOC2022_H
