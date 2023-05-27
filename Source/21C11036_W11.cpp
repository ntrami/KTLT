/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

int headSize = sizeof(int);

int memSize(int nItem)
{
    return headSize + nItem*sizeof(float);
}

float* data_addr(void* origin)
{
    return (float*)((char*)origin + headSize);
}

void* origin_addr(void* aData)
{
    if (aData != NULL)
        return (char*)aData-headSize;
    return NULL;
}


void set_nItem(float* aData, int nItem)
{
    *((int*)origin_addr(aData)) = nItem;
}

float* floatArrResize(float* aData, int nItem)
{
    int sz = memSize(nItem);
    float* anew = NULL;
    void* originAddr = NULL;
    if(aData != NULL)
        originAddr = origin_addr(aData);
    anew = (float*) realloc(originAddr, sz);
    if(anew != NULL)
    {
        if(aData == NULL)
        {
            memset(anew, 0, sz);
        }
        aData = data_addr(anew);
        set_nItem(aData, nItem);
    }
    return aData;
}

int get_nItem(float* aData)
{
    return *((int*)origin_addr(aData));
}

int floatArrSize(float* aData)
{
    if(aData != NULL)
    {
        return get_nItem(aData);
    }
    return 0;
}

int floatArrPushback(float** aData, float x)
{
    int n = floatArrSize(*aData);
    float* anew = floatArrResize(*aData, n+1);
    if(anew != NULL)
    {
        anew[n] = x;
        *aData = anew;
        return 1;
    }
    return 0;
}

float* floatArrInput()
{
    float* a = NULL, x=0;
    while (cin>>x)
    {
        floatArrPushback(&a, x);
    }
    cin.clear();
    return a;
}

void floatArrOutput(float* arr)
{
    int n = floatArrSize(arr);
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }
}

void floatArrFree(void* aData)
{
    if(aData != NULL)
    {
        free(origin_addr(aData));
    }
}

int main()
{
    float* B = NULL;
    B = floatArrInput();
    cout << "\nOutput: "; 
    floatArrOutput(B);
    floatArrFree(B);
    return 0;
}
