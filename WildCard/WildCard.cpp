/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        WildCard.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-24 14:25:57
 * @last update: 2017-04-24 14:51:04
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string strPattern, strString;
    cin>> strPattern>> strString;
    string strPat;
    for( auto i : strPattern ){
        if( i == '*' ){
            strPat += "[[:alnum:]]*";
        }
        else if( i== '.' ){
            strPat += "\\.";
        }
        else if( i=='?' ){
            strPat += ".";
        }
        else{
            strPat += i;
        }
    }
    regex reg1( strPat );
    bool bIsMatch = regex_match( strString, reg1 );
    if( bIsMatch ){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
