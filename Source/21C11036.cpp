/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/

#include <iostream>
#include <ctime>
#include<chrono>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int calculateAge(int yearborn)
{
    auto curTime = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t (curTime);
    stringstream ss(ctime(&currentTime));
    string tmp;
    vector<string> element;
    while(getline(ss,tmp,' '))
    {
        element.push_back(tmp);
    }
    int res = stoi(element[4]) - yearborn;
    return res;
}

char uppercase (char c)
{
    if ('a' <= c && c <= 'z')
    {
        c = c - ('a'-'A');
    }
    return c;
}

vector <int> withdraw (int m, vector<int> denomination)
{
    vector <int> res;
    int vecSz = denomination.size();
    for (int i = 0; i < vecSz; i++)
    {
        int tmp = (int) (m/denomination[i]);
        res.push_back(tmp);
        m -= denomination[i]*tmp;
    }
    return res;
}

int main()
{   
    // --- Task 1: Input Year Born => Output: Age
    cout << "1. Input the year that you was borned: ";
    int n;
    cin >> n;
    cout << "=> Your age is: " << calculateAge(n) << endl;

    // --- Task 2: Input Charater => Output: Uppercase
    cout << "2. Input a charater: ";
    char c;
    cin >> c;
    cout << "=> Uppercase: " << uppercase (c) << endl;

    // --- Task 3: Input Amount Withdraw => Output: Quantity for each denomination 
    cout <<"3. How much you want withdraw from ATM: ";
    int m;
    cin >> m;
    vector <int> denomination {500000, 200000,100000, 50000, 20000, 10000};
    vector <int> res = withdraw(m, denomination);
    int resSz = res.size();
    cout << "=> " << m << " = ";
    for (int i = 0; i < resSz; i++)
    {
        if (i != resSz - 1)
            cout << denomination[i] << " x " <<res[i] << " + ";
        else
            cout << denomination[i] << " x " <<res[i] << endl;
    }
    return 0;
}