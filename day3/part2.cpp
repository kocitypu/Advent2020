#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int count(int r, int d)
{
    ifstream file("dane.txt");
    int pointer = r;
    int counter = 0;
    int skip=d;
    string line;
    file.clear();
    file.seekg(0, file.beg);

    getline(file, line);
    while (getline(file, line))
    {
        
        if (skip > 1)
        {
            skip--;
            continue;
        }

        if (pointer >= line.length())
        {
            pointer -= line.length();
        }
        if (line[pointer] == '#')
        {
            counter++;
        }
        pointer += r;
        skip = d;
    }

    file.close();
    return counter;
}

int main()
{
    unsigned long long result=1;

    result = count(1, 1);
    result *=count(3, 1);
    result *= count(5, 1);
    result *= count(7, 1);
    result *= count(1, 2);
    cout << result << endl;
	return 0;
}