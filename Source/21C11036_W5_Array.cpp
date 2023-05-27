/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/
#include<iostream>
#include<math.h>
using namespace std;
#define N 50
#define MaxRow 20
#define MaxCol 30

void arrIntInput(int a[N], int& n);
void arrIntOutput(int a[N], int& n);
void sumEvenElements(int a[N], int& n);
void multiOddPosition(int a[N], int& n);
void arr2DIntInput(int b[][MaxCol], int& m, int& n);
void arr2DOutput(int a[][MaxCol], int m, int n);
void rotateMatrix(int m, int n, int mat[][MaxCol]);

void arrIntInput(int a[N], int& n)
{
    while(1)
    {
        cout << "Nhap so phan tu can dung: ";
        cin>>n;
        if(n<0||n>N)
            cout<<"Vui long nhap lai \n";
        else
            break;
    }
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap a[" <<i<<"]: ";
        cin>>a[i];
    }
}

void arrIntOutput(int a[N], int& n)
{
    for(int i=0; i < n; i++)
        cout << a[i] << "\t";
}

void sumEvenElements(int a[N], int& n)
{
    int Sum=0;
    for (int i=0; i<n; i++)
        if(a[i]%2==0)
            Sum+=a[i];
    cout << "\nTong cac phan tu chan: " << Sum;
}

void multiOddPosition(int a[N], int& n)
{
    int res = 1;
    for (int i=1; i< n; i++)
        if(i%2 != 0)
            res*=a[i];
    cout << "\nTich cac phan tu o vi tri le: "<< res;
}

void arr2DIntInput(int b[][MaxCol], int& m, int& n)
{
    cout << "\nNhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    for (int i=0; i<m;i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << "Nhap a[" << i << "][" <<j<<"]: ";
            cin >> b[i][j];
        }
    }
}

void arr2DOutput(int a[][MaxCol], int m, int n)
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }
}

void rotateMatrix(int row, int col, int mat[][MaxCol])
{
    int firstEle = mat[0][0];
    for (int i=0; i<col-1; i++)
    {
        mat[0][i]= mat[0][i+1]; 
    }
    for (int i=0; i<row-1; i++)
    {
        mat[i][col-1] =  mat[i+1][col-1];
    }
    for (int i=col-1; i>0; i--)
    {
        mat[row-1][i]=mat[row-1][i-1];
    }
    for (int i=row-1; i>1; i--)
    {
        mat[i][0]=mat[i-1][0];
    }
    mat[1][0]=firstEle;
    cout << "Rotate Matrix: \n";
    arr2DOutput(mat, row, col);
}


int main()
{
    cout << "--- BAI TAP 1 ---\n";
    int arr[N], m;
    arrIntInput(arr, m);
    arrIntOutput(arr, m);
    sumEvenElements(arr, m);
    multiOddPosition(arr, m);

    cout << "\n\n--- BAI TAP 2 ---";
    int a[MaxRow][MaxCol], row, col;
    arr2DIntInput(a, row, col);
    arr2DOutput(a, row, col);
    rotateMatrix(row, col, a);

    return 0;
}