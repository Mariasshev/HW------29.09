#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
using namespace std;


int main() {
    //my path for check: C:\Users\Admin\source\repos\HW ---- 29.09\HW ---- 29.09\index.html
    char path[256];
    cout << "Enter path: ";
    cin.getline(path, sizeof(path));
    ifstream in(path);

    char string;
    int errorCounter = 0;
    int count_open=0;
    int count_close=0;
    if (in.is_open())
    {
        while (!in.eof())
        {
            in.get(string);
            cout << string << ' ';
            if (string == '<') {
                count_open++;
            }
            else if (string == '>') {
                count_close++;
            }
        }
        if (count_close > count_open) {
            int rez = count_close - count_open;
            cout << "Find " << rez << "errors!" << endl;
        }
        else if (count_close < count_open) {
            int rez = count_open - count_close;
            cout << "Find " << rez << " errors!" << endl;
        }
        else{
            cout << "All is correct!" << endl;
        }
        in.close();
    }
    else
    {
        cout << "Could not open the file" << endl;
    }
}