// ---- Program Info Start----
//FileName:     count1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-05 10:57:41
// ---- Program Info End  ----

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int iNumber, iCount = 0;
    cin >> iNumber;
    while( iNumber ){
        iNumber = iNumber & (iNumber-1);
        iCount ++;
    }
    cout<<iCount;
    return 0;
}
