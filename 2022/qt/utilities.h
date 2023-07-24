#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

namespace Utilities {

    // Parses the input string into tokens separated by the provided delimiter.
    vector<string> splitString(const string& str, char splitter);

    // Insert 2 items to vector - custom function for Day 4
    void addStartEnd(vector<int> &array, string item1, string item2);

    // another story...
    void parseInputCratesStacks(vector<vector<string>>& crates, string& line);
    void writeOutStack(vector<vector<string>> crates);

    // Skip some lines in file by the provided line number
    fstream& goToLine(fstream& file, unsigned int num);
}

#endif // UTILITIES_H
