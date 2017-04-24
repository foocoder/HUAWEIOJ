/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        WildCard2.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-24 14:54:05
 * @last update: 2017-04-24 14:58:59
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>

using namespace std;

bool isMatch( const char * s, const char * p ){
    bool star = false;
    const char * str, * ptr;
    for( str = s, ptr = p; *str != '\0'; str++, ptr++ ){
        switch( *ptr ){
            case '?':
                break;
            case '*':
                star = true;
                s = str, p = ptr;
                while( *p == '*' ) p++;
                if( *p == '\0' ) return true;
                str = s-1;
                ptr = p-1;
                break;
            default:
                if( *str!=*ptr ){
                    if( !star ) return false;
                    s++;
                    str = s-1;
                    ptr = p-1;
                }
        }
    }
    while( *ptr == '*' ) ptr++;
    return ( *ptr == '\0' );
}

int main(int argc, char *argv[])
{
    string strPat, strStr;
    cin>>strPat>>strStr;
    if( isMatch( strPat.c_str(), strStr.c_str() ) ){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
