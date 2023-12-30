#include <iostream>
#include <vector>
#include <string>
#include "useStack.h"
#include "./string/relationFunc.h"
#include "./tree/tree.h"
using namespace std;
int main()
{
    string date = "2019-01-09";
    int year = atoi(date.substr(4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int days = atoi(date.substr(8, 2).c_str());
    cout << year << " " << month << " " << days << endl;
}
