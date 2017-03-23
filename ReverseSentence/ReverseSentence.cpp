// ---- Program Info Start----
//FileName:     ReverseSentence.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 17:36:13
// ---- Program Info End  ----

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverseStr( string & str, int start, int end ){
    end --;
    while( start<end ){
        char tmp = str[start];
        str[start++] = str[end];
        str[end--] = tmp;
    }
}

int getToken( const string & str, int start ){
    char a;
    while( ( a = str[start++]) != '\0' && a != ' ' );
    return start-1;
}

void reverseSentence( string & str ){
    int index = 0, end = str.size(), wordEnd;
    reverseStr( str, 0, end );
    while( (wordEnd = getToken(str, index)) != end ){
        reverseStr( str, index, wordEnd );
        index = wordEnd+1;
    }
    reverseStr( str, index, wordEnd );
}

int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    reverseSentence( strLine );
    cout << strLine << endl;
    return 0;
}
