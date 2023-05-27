/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/

#include <iostream>
#include <math.h>
using namespace std;


int sum1(int n)
{
    int S = 0;
    for (int i=1; i<=n; i++)
    {
        S+=i;
    }
    return S;
}

// Sum of fractions
float sum2(int n)
{
    float S = 0;
    for (float i=1; i<=n; i++)
    {
        S+=1/i;
    }
    return S;
}

// Sum of factorials
int sum3(int n)
{
    int S = 0;
    for (int i=1; i<=n; i++)
    {
        int tmp = 1;
        for (int j = 1; j<=i; j++)
        {
            tmp *=j;
        }
        S+=tmp;
    }
    return S;
}

// Sum of exponential
float exponential(float x, int n)
{
    float t=1;
    for(int i=1; i<=n; i++)
    {
        t*=x;
    }
    return t;
}


float sum4 (float x, int n)
{
    float S = 0;
    for (int i=1; i<=n; i++)
    {
        S+=exponential(x,i);
    }
    return S;
}

// Sum of square root loop
float sum5 (int n)
{
    float S = 0;
    for (int i=1; i<=n; i++)
    {
        S=sqrt(2+S);
    }
    return S;
}

// count number of digits in n
int count_digit(int n)
{
    int cnt = 0;
    while(n!=0)
    {
        cnt++;
        n=n/10;
    }
    return cnt;
}

// multiplication of digits in n
int multipli_digits(int n)
{
    int multiply = 1;
    while(n!=0)
    {
        multiply *= n%10;
        n=n/10;
    }
    return multiply;
}

int main()
{
    
    int n;
    cout << "1. Input n to calculate Sum: ";
    cin >> n;
    cout << "S(" <<n<<") = " << sum1 (n) <<endl;

    cout << "\n2. Input n to calculate Sum of fractions: ";
    cin >> n;
    cout << "S2(" <<n<<") = " << sum2(n) <<endl;

    cout << "\n3. Input n to calculate Sum of factorials: ";
    cin >> n;
    cout << "S3(" <<n<<") = " << sum3(n) <<endl;

    cout << "\n4. Input x and n to calculate Sum of exponential: ";
    float x;
    cin >> x >> n;
    cout << "S4(" <<n<<") = " << sum4(x, n) <<endl;

    cout << "\n5. Input n to calculate Sum of square root loop: ";
    cin >> n;
    cout << "S5(" <<n<<") = " << sum5(n) <<endl;

    cout << "\n6. Input n to count number of digits in n: ";
    cin >> n;
    cout << "count_digit(" <<n<<") = " << count_digit(n) <<endl;

    cout << "\n7. Input n to calculate multiplication of digits in n: ";
    cin >> n;
    cout << "multipli_digits(" <<n<<") = " << multipli_digits(n) <<endl;
}