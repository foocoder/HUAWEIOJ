// ---- Program Info Start----
//FileName:     CountASCII2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 18:46:18
// ---- Program Info End  ----

#include <iostream>
#include <string>

using namespace std;

int cAlphetTable [ 128 ] = { 0 };
int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    char cTest;
    cin>>cTest;
    for( auto i:strLine ){
        cAlphetTable[i] ++;
    }
    cout<<cAlphetTable[cTest];
    return 0;
}
