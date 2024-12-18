#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool CheckBrackets(const string& path) 
{
    ifstream file(path);
    if (!file.is_open()) 
    {
        cout << "Error: Failed to open file " << path << endl;
        return false;
    }

    int bracket_count = 0;
    string line;

    while (getline(file, line)) 
    {
        for (char c : line) 
        {
            if (c == '<') 
            {
                bracket_count++;
            }
            else if (c == '>') 
            {
                bracket_count--;
            }
            if (bracket_count < 0) 
            {
                return false;
            }
        }
    }

    file.close();

    if (bracket_count != 0) 
    {
        return false;
    }

    return true;
}

int main()
{
    string path;
    cout << "Enter the path to the file: ";
    getline(cin, path);

    if (CheckBrackets(path)) 
    {
        cout << "File has balanced '<' and '>' brackets!" << endl;
    }
    else 
    {
        cout << "File contains unbalanced '<' and '>' brackets!" << endl;
    }

    return 0;
}
