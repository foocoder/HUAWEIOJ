// ---- Program Info Start----
//FileName:     lenOfLastWord.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-02-19 14:17:44
// ---- Program Info End  ----

/* #include <iostream> */
/* #include <sstream> */
/* #include <cstring> */

#include <stdio.h>
#include <string.h>
/* using namespace std; */

char cLine[129];

int main(int argc, char *argv[])
{
    /* string strLine; */
    /* while( getline(cin, strLine) ){ */
    /*     istringstream ssLine ( strLine ); */
    /*     string tmp; */
    /*     int len = 0; */
    /*     while( ssLine >> tmp ){ */
    /*         len = tmp.length(); */
    /*     } */
    /*     cout<<len<<endl; */
    /* } */

    while( ~( scanf( "%[^\n]", cLine) ) ){
        int len = 0;
        int iNum = strlen( cLine )-1;
        while( iNum >=0 ){
            if( cLine[iNum] == ' ' ){
                break;
            }
            len++; iNum--;
        }
        printf( "%d\n", len);
        setbuf( stdin, NULL );
        memset( cLine, 0, 129);
    }
    return 0;
}

