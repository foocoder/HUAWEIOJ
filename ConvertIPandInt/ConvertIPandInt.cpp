/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ConvertIPandInt.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-04 20:57:16
 * @last update: 2017-04-05 10:29:52
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_STR_LEN 100
#define MASK 0x80000000
int main(int argc, char *argv[])
{
    char cInteger[MAX_STR_LEN] = { 0 };
    int nIPSeg[ 4 ] = { 0 };
    char cIPSegment[MAX_STR_LEN] = { 0 };
    for( int i=0; i<3; ++i ){
        scanf( "%[^.]", cIPSegment );
        getchar(); // 接收字符"."
        nIPSeg[i] = strtoul( cIPSegment, NULL, 10 );
        memset( cIPSegment, 0, sizeof(cIPSegment) );
    }
    scanf( "%d", &nIPSeg[3] );
    unsigned long ulIPAdress = nIPSeg[0] * 256 * 256 * 256 +
                               nIPSeg[1] * 256 * 256 +
                               nIPSeg[2] * 256 +
                               nIPSeg[3];
    printf( "%ld\n", ulIPAdress );

    scanf( "%s", cInteger );

    unsigned long ulInteger = strtoul( cInteger, NULL, 10 );
    int nIP[4] = { 0 };
    for( int i=0; i<4; ++i ){
        unsigned char nVal = 0;
        for( int j=0; j<8; ++j ){
            nVal = (nVal<<1) + ((ulInteger & MASK) >> 31);
            ulInteger <<= 1;
        }
        nIP[i] = nVal;
    }
    printf( "%d.%d.%d.%d", nIP[0], nIP[1], nIP[2], nIP[3] );
    return 0;
}
