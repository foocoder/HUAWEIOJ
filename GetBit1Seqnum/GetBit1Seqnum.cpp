// ---- Program Info Start----
//FileName:     GetBit1Seqnum.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-25 09:56:36
// ---- Program Info End  ----

#include <stdio.h>

int main(int argc, char *argv[])
{
    int nNum;
    scanf( "%d", &nNum );
    int nCount = 0;
    int nMax = 0;
    bool bFlag = false;
    while( nNum ){
        if( nNum & 1 ){
            nCount++;
            if( !bFlag )
                bFlag = true;
        }
        else if( bFlag ){
            bFlag = false;
            nMax = nCount > nMax ? nCount : nMax;
            nCount = 0;
        }
        nNum >>= 1;
    }
    if( bFlag ){
        nMax = nCount > nMax ? nCount : nMax;
    }
    printf( "%d", nMax);
    return 0;
}
