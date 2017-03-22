// ---- Program Info Start----
//FileName:     CountASCII.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-22 15:57:54
// ---- Program Info End  ----

#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define ISBLANK( letter ) ( letter == ' ' )
#define ISDIGIT( letter ) ( (letter>='0') && (letter<='9') )
#define ISUPPER( letter ) ( (letter>='A') && (letter<='Z') )
#define ISLOWER( letter ) ( (letter>='a') && (letter<='z') )

int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );

    int nAlphet [256] = {0};
    for( auto i : strLine ){
        if( ISBLANK( i ) || ISDIGIT( i ) || ISUPPER( i ) || ISLOWER( i ) ){
            nAlphet[i] ++;
        }
    }
    map<int, vector<int>> sortMap;
    for( int i=0; i<256; ++i ){
        if( nAlphet[i] > 0 ){
            sortMap[ nAlphet[i] ].push_back( i );
        }
    }

    map<int, vector<int>>::reverse_iterator rIter=sortMap.rbegin();
    while( rIter != sortMap.rend() ){
        for( auto i : rIter->second ){
            cout<<(char)i;
        }
        rIter++;
    }

    return 0;
}
