// ---- Program Info Start----
//FileName:     GetSequeOddNum.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-25 09:32:40
// ---- Program Info End  ----

#include <stdio.h>

int main(int argc, char *argv[])
{
    int nNum;
    scanf( "%d", &nNum );
    int nFactor[1000] = {0};
    int nPower = nNum * nNum;
    int nStart;
    if( nPower & 1 ){
        int nTmp = nNum/2;
        nStart = nPower - nTmp*2;
    }
    else{
        nStart = nPower - nNum + 1;
    }
    for( int i=0; i<nNum; ++i ){
        if( i!=nNum-1 )
            printf("%d+", nStart+i*2 );
        else
            printf("%d", nStart+i*2 );
    }


    return 0;
}
