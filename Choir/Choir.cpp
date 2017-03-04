// ---- Program Info Start----
//FileName:     Choir.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-02-19 15:26:50
// ---- Program Info End  ----

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    // 130 150 160 186 186 197 200 200
    string strLine;
    while( getline(cin, strLine)){
        istringstream ssLine( strLine );
        int iNum;
        ssLine>>iNum;
        vector<int> vNumbers( iNum );
        for( int i=0; i<iNum; ++i){
            ssLine >> vNumbers[i];
        }
        sort( vNumbers.begin(), vNumbers.end());
    }

    return 0;
}
