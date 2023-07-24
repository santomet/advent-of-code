#include "utilities.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

#include <QTextStream>
#include <QString>

namespace Utilities {

    vector<string> splitString(const string& str, char splitter)
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

    vector<string> ReadAllLinesInFile(const filesystem::path& path)
    {
        auto lines = vector<string>{};
        if (!filesystem::exists(path))
        {
            return lines;
        }

        auto fileStream = ifstream{ path };
        auto currentLine = string{};
        while (getline(fileStream, currentLine))
        {
            lines.emplace_back(currentLine);
        }

        return lines;
    }

    void addStartEnd(vector<int> &array, string item1, string item2)
    {
        array.insert(array.begin(), stoi(item1));
        array.insert(array.begin() + 1, stoi(item2));

    }

    void parseInputCratesStacks(vector<vector<string>>& crates, string& line)
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

    void writeOutStack(vector<vector<string>> crates)
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

    fstream& goToLine(fstream& file, unsigned int num){
        file.seekg(ios::beg);
        for(int i=0; i < num - 1; ++i){
            file.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        return file;
    }

}
