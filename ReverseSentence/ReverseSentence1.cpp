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
#include <cctype>

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

string preprocessSentence( const string & str ){
    int nStrSize = str.size();
    string newStr( nStrSize, '\0' );
    int nCount = 0;
    for( auto i : str ){
        if( isalpha(i) ){
            newStr[nCount++] = i;
        }
        else if( newStr[nCount-1] != ' ' ){
            newStr[nCount++] = ' ';
        }
    }
    if( newStr[nCount-1] == ' ' ){
        newStr[nCount-1] = '\0';
    }
    return newStr;
}

int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    string newString = preprocessSentence( strLine );
    reverseSentence( newString );
    cout << newString << endl;
    return 0;
}
