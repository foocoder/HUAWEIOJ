/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        CheckPassword.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-02 16:27:17
 * @last update: 2017-04-02 17:18:42
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>
#include <cctype>
#include <cstring>

#define MAX_STR_LEN 100
bool fnCheckSim( char * pLeftStart, char * pRightStart ){
    for( int i=1; i<3; ++i ){
        if( *(pRightStart+i) == '\0' )
            return false;
        if( *(pLeftStart+i) != *(pRightStart+i) )
            return false;
    }
    return true;
}
void fnProcessPasswd( char * cPasswordArr ){
    char * pStr = cPasswordArr;
    char cCharIndex;
    int nLen = 0;
    int nTypeArr [4] = { 0 };
    char cAlphabetTable [128][MAX_STR_LEN];
    int nAlphabetIndex[128] = { 0 };
    memset( cAlphabetTable, -1, sizeof(cAlphabetTable) );
    bool bFlag = false;
    while( (cCharIndex = *pStr++) != '\0' ){
        //获取Type信息
        if( isupper(cCharIndex) ){
            nTypeArr[0] = 1;
        }
        else if( islower(cCharIndex) ){
            nTypeArr[1] = 1;
        }
        else if( isdigit(cCharIndex) ){
            nTypeArr[2] = 1;
        }
        else{
            nTypeArr[3] = 1;
        }
        //获取子串重复信息
        if(!bFlag){
            int * pCount = & nAlphabetIndex[cCharIndex];
            if( !(*pCount) ){
                cAlphabetTable[cCharIndex][(*pCount)++] = nLen;
            }
            else{
                for( int i=0; i<(*pCount) && !bFlag; ++i ){
                    bFlag = fnCheckSim(
                            &cPasswordArr[ cAlphabetTable[cCharIndex][i] ],
                            pStr-1
                            );
                }

            }
        }
        nLen++;
    }
    int nTypeCount = nTypeArr[0]+nTypeArr[1]+nTypeArr[2]+nTypeArr[3];
    if( nTypeCount  >= 3 && nLen > 8 && !bFlag ){
        printf( "OK\n" );
    }
    else{
        printf( "NG\n" );
    }
}
int main(int argc, char *argv[])
{
    char cPasswordArr[ MAX_STR_LEN ] = { 0 };
    while( ~(scanf( "%s", cPasswordArr )) ){
        fnProcessPasswd( cPasswordArr );
        memset( cPasswordArr, 0, sizeof( cPasswordArr ) );
    }
    return 0;
}
