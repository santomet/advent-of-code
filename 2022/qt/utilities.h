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

    // Reads the provided text file and returns all lines as strings.
    vector<string> readAllLinesInFile(const filesystem::path& path);

    // Crashes the program if the assertion is false
    void verifyElseCrash(bool bAssert);

    // Insert 2 items to vector - custom function for Day 4
    void addStartEnd(vector<int> &array, string item1, string item2);

    // Skip some lines in file by the provided line number
    fstream& goToLine(fstream& file, unsigned int num);
}

#endif // UTILITIES_H
