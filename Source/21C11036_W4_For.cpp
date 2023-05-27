/*
IDE: Visual Studio Code
Name: Nguyen Thi Ngoc Tram
Student ID: 21C11036
*/

#include <iostream>
#include <math.h>
using namespace std;
#define _Extream -1

unsigned long Tinh(unsigned long L, unsigned long R, double P, unsigned long thuNhap)
{
    unsigned long kq=0;
    if(thuNhap<L) return kq;
    else{
        if(thuNhap<R||R == _Extream) kq=(thuNhap-L)*P;
        else kq=(R-L)*P;
    }
    return kq;
}
unsigned long TinhThue(unsigned long thuNhap)
{
    unsigned long L1=4000000, L2=6000000, L3=9000000, L4=14000000, L5 = 24000000, L6=44000000, L7=84000000;
    double P1=0, P2=0.05, P3=0.1, P4=0.15, P5=0.2, P6=0.25, P7=0.3, P8=0.35;
    unsigned long TienThue = Tinh(0, L1, P1, thuNhap)+
                Tinh(L1, L2, P2, thuNhap)+
                Tinh(L2, L3, P3, thuNhap)+
                Tinh(L3, L4, P4, thuNhap)+
                Tinh(L4, L5, P5, thuNhap)+
                Tinh(L5, L6, P6, thuNhap)+
                Tinh(L6, L7, P7, thuNhap)+
                Tinh(L7, _Extream, P8, thuNhap);
    return TienThue;
}
int main()
{
    cout << "Nhap thu nhap: ";
    unsigned long thuNhap;
    cin >> thuNhap;
    cout << "Thue can tra: " << TinhThue(thuNhap);
    return 0;
}