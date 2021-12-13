// Q24941
/*
A simple scheme for creating a compressed version of a text file can be used for files which contain no digit characters. The compression scheme requires making a list of the words in the uncompressed file. When a non-alphabetic character is encountered in the uncompressed file, it is copied directly into the compressed file. When a word is encountered in the uncompressed file, it is copied directly into the compressed file only if this is the first occurrence of the word. In that case, the word is put at the front of the list. If it is not the first occurrence, the word is not copied to the compressed file. Instead, its position in the list is copied into the compressed file and the word is moved to the front of the list. The numbering of list positions begins at 1. 

Write a program that takes a compressed file as input and generates a reproduction of the original uncompressed file as output. You can assume that no word contains more than 50 characters and that the original uncompressed file contains no digit characters. 

For the purposes of this problem, a word is defined to be a maximal sequence of upper- and lower-case letters. Words are case-sensitive - the word abc is not the same as the word Abc. For example, 

tabular23  

There is no upper limit on the number of different words in the input file. The end of the input file is signified by the number 0 on a line by itself. The terminating 0 merely indicates the end of the input and should not be part of the output produced by your program.
*/

#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

bool isNumber(string input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]) == false)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    list<string> dictionary;
    string in = "";
    string result;
    int index = 0;
    char c;
    for (c = getchar(); c != '0'; c = getchar())
    {
        if (isdigit(c))
        {
            index *= 10;
            index += c - '0';
            continue;
        }
        else if (index != 0)
        {
            list<string>::iterator it = dictionary.begin();
            std::advance(it, index - 1);
            dictionary.push_front(*it);
            result += *it;
            dictionary.erase(it);

            index = 0;
        }
        else
        {
            if (isalpha(c))
            {
                in += c;
            }
            else if (in.length() > 0)
            {
                dictionary.push_front(in);
                in = "";
            }
        }
        result += c;
    }

    cout << result << endl;

    return 0;
}
