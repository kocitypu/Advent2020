#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>


using namespace std;



int main()
{
    string line;
    ifstream plik("dane.txt");
    int pointer = 3;
    int counter=0;

    getline(plik, line);
    while (getline(plik, line))
    {
        if (pointer >= line.length())
        {
            pointer -= line.length();
        }
        if (line[pointer] == '#')
        {
            counter++;
        }
        pointer += 3;
    }

    cout << counter;

    plik.close();

	return 0;
}