#include <iostream>
#include <string>

#define N 15
using namespace std;


int theMostCalories(string array[])
{
    int max = 0;
    int sum = 0;

    for(int i = 0; i < N; i++) {

        if (!array[i].compare("")) {
            if (max < sum) {
                max = sum;
            }
            sum = 0;
            continue;
        }
        sum += stoi(array[i]);
    }

    return max;
}


int main (int argc, char *argv[])
{
    string elf_array[N] = {
        "1000", "2000", "3000", "",
        "4000", "",
        "5000", "6000", "",
        "7000", "8000", "9000", "",
        "10000", ""
    };

    cout << "Description of task:\n"
         << "Find the Elf carrying the most Calories.\n"
         << "How many total Calories is that Elf carrying?\n"
         << "Result: "
         << theMostCalories(elf_array) << endl;


    return 0;
}
