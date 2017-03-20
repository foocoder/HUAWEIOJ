// ---- Program Info Start----
//FileName:     SnakeMatrix.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-20 19:41:40
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define MAX_NUM 100
void fnGetResult( int iNum, int pResult [][MAX_NUM] ){
    int numIndex = 1;
    for( int i=0; i<iNum; ++i ){
        int x = i, y = 0;
        for( ; y<=i; ++y, --x ){
            pResult[x][y] = numIndex ++;
        }
    }

}

int main(int argc, char *argv[])
{
    int iNum;
    int pResult [MAX_NUM][MAX_NUM] = {0};
    scanf( "%d", &iNum );
    fnGetResult( iNum, pResult );
    for( int i=0; i<iNum; ++i ){
        for( int j=0; j<iNum-i; ++j ){
            if( j != iNum - i -1 )
                printf( "%d ", pResult[i][j] );
            else
                printf( "%d", pResult[i][j] );
        }
        printf("\n");
    }
    return 0;
}
