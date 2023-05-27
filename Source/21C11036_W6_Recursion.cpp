/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/

#include<iostream>
#include<math.h>
using namespace std;

long numOfEven (long a[], int n);
void printNegPos (long a[], int n);
bool isAscendingArr (long a[], int n);

long numOfEven (long a[], int n)
{
    int res;
    if (n<=0)
        return 0;
    if (a[n-1]%2==0)
        res = 1;
    else
        res = 0;
    return res + numOfEven(a, n-1);
}

void printNegPos (long a[], int n)
{
    if (n<=0)
        return;
    if (a[n-1] < 0)
        cout << "\t" << n-1;
    printNegPos (a, n-1);
}

bool isAscendingArr (long a[], int n)
{
    if (n<2)
        return 1;
    if (a[n-1] > a[n-2])
        return isAscendingArr(a, n-1);
    else
        return 0;
}

int main()
{
    long a[] = {-6, -2, -1, 2, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "1. Number of Even Elements: " << numOfEven(a, n) << endl; 
    cout << "2. Position of negative element: ";
    printNegPos(a, n);
    if (isAscendingArr(a, n)==0)
        cout << "\n3. It is NOT an ascending array";
    else
        cout << "\n3. It is an ascending array";
    return 0;
}