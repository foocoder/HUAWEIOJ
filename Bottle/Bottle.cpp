/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Bottle.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-01 20:57:32
 * @last update: 2017-04-01 20:57:32
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

// F(0) = 0;
// F(1) = 0;
// F(2) = 1;
// F(3) = 1 + F(1) = 1;
// F(4) = 1 + F(2) = 2;
// F(5) = 1 + F(3) = 2;
// F(6) = 1 + F(4) = 3;
// F(7) = 1 + F(5) = 3;
// F(8) = 1 + F(6) = 4;
// F(9) = 1 + F(7) = 4;
// F(10) = 1 + F(8) = 5;
#include <cstdio>

int main(int argc, char *argv[])
{
    int nNum;
    while( 1 ){
        scanf( "%d", &nNum );
        if( !nNum ) break;
        printf( "%d\n", nNum/2 );
    }
    return 0;
}
