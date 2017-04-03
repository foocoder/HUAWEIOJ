/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        MovePoint.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-03 21:05:35
 * @last update: 2017-04-03 21:35:12
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>
#include <cstdlib>
#include <cctype>

#define MAX_STR_LEN 100
/* #define ISUP(letter) ( (letter) == 'W' ) */
/* #define ISDOWN(letter) ( (letter) == 'S' ) */
/* #define ISLEFT(letter) ( (letter) == 'A' ) */
/* #define ISRIGHT(letter) ( (letter) == 'D' ) */
/* #define ISDIRECTION(letter) ( ISUP(letter) || ISDOWN(letter) || ISLEFT(letter) || ISRIGHT(letter) ) */

void fnMovePoint( char * pStrStart, char * pStrEnd, int & nX, int & nY ){
    if( pStrEnd-pStrStart<2 ) return;
    /* if( !ISDIRECTION( *pStrStart ) ) return; */
    char cDirection = * pStrStart;
    int nDis = 0;
    for( char * pStr=pStrStart+1; pStr<pStrEnd; pStr++ ){
        if( !isdigit(*pStr) ) return;
        nDis = nDis * 10 + ( *pStr - '0' );
    }
    switch( cDirection ){
        case 'A':
            nX -= nDis;
            break;
        case 'D':
            nX += nDis;
            break;
        case 'S':
            nY -= nDis;
            break;
        case 'W':
            nY += nDis;
            break;
        default:
            return;
    }
    return;

}
int main(int argc, char *argv[])
{
    char cMovingArr[ MAX_STR_LEN ] = { 0 };
    scanf( "%[^\n]", cMovingArr );
    int nStart = 0, nCount = 0;
    int nX = 0, nY = 0;

    char * pStr = cMovingArr;
    char cIndex;

    while( (cIndex = *pStr++) != '\0' ){
        if( cIndex == ';' ){
            fnMovePoint( cMovingArr+nStart, cMovingArr+nCount, nX, nY );
            nStart = nCount+1;
        }
        nCount++;
    }
    printf( "%d,%d", nX, nY );
    return 0;
}
