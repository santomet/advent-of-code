#ifndef AOC2022_H
#define AOC2022_H

#include <iostream>
#include <vector>

using namespace std;

// Day 7
struct elf_file {
    string name;
    int size;
};

// Day 7
struct elf_directory {
    string name;
    struct elf_directory *parent;
    vector<elf_directory *> children;
    vector<elf_file *> files;
};

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
    int day_06_2(void);

    int day_07_1(void);

private:
    void addMax(vector<int> *top, int new_value); // Day 1
    vector<string> splitStringToArray(const string& str, char splitter); // Day 4
    void addStartEnd(vector<int> &array, string item1, string item2); // Day 4
    void parseInputCratesStacks(vector<vector<string>>& crates, string& line); // Day 5
    void writeOutStack(vector<vector<string>> crates); // Day 5
    fstream& goToLine(fstream& file, unsigned int num); // Day 5

    // Day 7
    void print_dir(elf_directory *dir)
    {
        std::cout << dir->name << "\n";
        if (dir->parent != NULL)
        {
            std::cout << "  (dir) .. => " << dir->parent->name << "\n";
        }
        for (elf_directory *child : dir->children) {
            std::cout << "  (dir) " << child->name << "\n";
        }
        for (elf_file *file : dir->files)
        {
            std::cout << "  " << file->size << " " << file->name << "\n";
        }
    }

    // Day 7
    void add_file(elf_directory *dir, elf_file *file) {
        dir->files.push_back(file);
    }

    // Day 7
    elf_directory *make_dir(string name, elf_directory *parent) {
        elf_directory *new_dir = (elf_directory *)malloc(sizeof(elf_directory));
        new_dir->name = name;
        new_dir->parent = parent;
        if (parent != NULL) {
            parent->children.push_back(new_dir);
        }
        return new_dir;
    }

    // Day 7
    elf_file *make_file(string name, int size) {
        elf_file *new_file = (elf_file *)malloc(sizeof(elf_file));
        new_file->name = name;
        new_file->size = size;
        return new_file;
    }
};

#endif // AOC2022_H
