/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/

#include <iostream>
#include <math.h>
using namespace std;

// HÀM CÓ THAM SỐ LÀ HÀM
float SUM(int n, float Element(float i));
float itg(float i);
float fraction(float i);
float factorial(float i);
float squareRoot(float i);

float SUM(int n, float Element(float i))
{
    float S = 0;
    for (int i=1; i<=n; i++)
    {
        S+=Element(i);
    }
    return S;
} 

float itg(float i)
{
    return i;
}

float fraction(float i)
{
    return 1/i;
}

float factorial(float i)
{
    int f = 1;
    for (int j = 1; j<=i; j++)
    {
        f *=j;
    }
    return f;
}

float squareRoot(float i)
{
    return sqrt(2+i);
}

int main()
{
    int n;
    cout << "Input n to calculate Sum: ";
    cin >> n;
    cout << SUM (n, itg) <<endl;
    cout << SUM (n, fraction) << endl;
    cout << SUM (n, factorial) << endl;
    cout << SUM (n, squareRoot) << endl;
}