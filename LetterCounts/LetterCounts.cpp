// ---- Program Info Start----
//FileName:     LetterCounts.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-20 16:07:38
// ---- Program Info End  ----

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;
#define ISDIGIT( letter ) ( (letter>='0') && (letter<='9') )
#define ISBLANK( letter ) ( letter == ' ' )
#define ISLOWERCASE( letter ) ( (letter>='a') && (letter<='z') )
#define ISCAPITAL( letter ) ( (letter>='A') && (letter<='Z') )

vector<int> getLetterCount( const string & strLine ){
    /* int szStrLen = strLine.size() */
    vector<int> viLetterCounts(4, 0);
    for( auto i : strLine ){
        if( ISLOWERCASE(i) || ISCAPITAL(i) ){
            viLetterCounts[0] ++;
        }
        else if( ISBLANK(i) ){
            viLetterCounts[1] ++;
        }
        else if( ISDIGIT(i) ){
            viLetterCounts[2]++;
        }
        else{
            viLetterCounts[3]++;
        }
    }
    return viLetterCounts;

}

int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    vector<int> count = getLetterCount( strLine );
    for( auto i:count ){
        cout<<i<<endl;
    }
    return 0;
}
