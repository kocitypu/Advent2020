#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>


using namespace std;

int correct=0;

typedef struct line
{
    int min=0;
    int max=0;
    char character;
    string password;
}; 
line all[2000];

int findmin(string str)
{
    int dash;
    string num;
    int result;
    dash = str.find("-");
    num = str.substr(0, dash);
    result = stoi(num);
    return result;
}

int findmax(string str)
{
    int dash;
    string num;
    int result;
    dash = str.find("-");
    num = str.substr(dash+1, str.size()-dash);
    result = stoi(num);
    return result;
}

void check(int n)
{
    if ((all[n].password[(all[n].min)-1] == all[n].character &&
        all[n].password[(all[n].max) - 1] != all[n].character) ||
       (all[n].password[(all[n].min) - 1] != all[n].character &&
        all[n].password[(all[n].max) - 1] == all[n].character))
    {
        correct++;
    }
}

int main()
{
    int n=0;
    int state = 1;
    string line;
    ifstream plik("dane.txt");

    while (plik >> line)
    {
        switch (state)
        {
        case 1:
            all[n].min = findmin(line);
            all[n].max = findmax(line);
            state++;
            break;

        case 2:
            all[n].character = line[0];
            state++;
            break;
        case 3:
            all[n].password = line;
            state = 1;
            check(n);
            n++;
            break;
        }
    }

    cout << correct;

        plik.close();

	return 0;
}