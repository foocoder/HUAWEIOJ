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

bool cAlphetTable [ 128 ] = { 0 };
int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    for( auto i:strLine ){
        cAlphetTable[i] = true;
    }
    int nCount = 0;
    for( int i=0; i<128; ++i ){
        if( cAlphetTable[i] )
            nCount++;
    }
    cout<<nCount;
    return 0;
}
