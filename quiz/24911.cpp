/*
24911:Robot Instructions

Time Limit: 3 sec
Description
You have a robot standing on the origin of x axis. The robot will be given some instructions. Your task is to predict its position after executing all the instructions. 

LEFT: move one unit left (decrease p by 1, where p is the position of the robot before moving)
RIGHT: move one unit right (increase p by 1)
SAME AS i: perform the same action as in the i-th instruction. It is guaranteed that i is a positive integer not greater than the number of instructions before this.
Input
The first line contains the number of test cases T (T≤100). Each test case begins with an integer n ( 1≤n≤100), the number of instructions. Each of the following n lines contains an instruction.

Output
For each test case, print the final position of the robot. Note that after processing each test case, the robot should be reset to the origin.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int stringtoint(const string &str)
{
    int numStr = 0;
    for (int i = 0; i < str.length(); i++)
    {
        numStr *= 10;
        numStr += str[i] - '0';
    }
    return numStr;
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    cin.ignore(1, '\n');

    while (T--)
    {
        int p = 0;

        int n;
        cin >> n;
        cin.ignore(1, '\n');
        vector<string> history;

        while (n--)
        {
            string cmd;
            getline(cin, cmd);

            if (cmd.substr(0, 7) == "SAME AS")
            {
                cmd = cmd.substr(8);
                int line = stringtoint(cmd);
                cmd = history[line - 1];
            }
            history.push_back(cmd);

            if (cmd == "LEFT")
            {
                --p;
            }
            else if (cmd == "RIGHT")
            {
                ++p;
            }
        }
        cout << p << endl;
    }

    return 0;
}
