/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        CalcBallDistance.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-01 21:13:55
 * @last update: 2017-04-01 21:21:00
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>

int main(int argc, char *argv[])
{
    int nStartDis;
    scanf( "%d", &nStartDis );
    double fTotal, fCurrent=nStartDis;
    fTotal = fCurrent;
    for( int i=0; i<4; ++i ){
        fCurrent /= 2;
        fTotal += 2 * fCurrent;
    }
    printf( "%g\n%g", fTotal, fCurrent/2 );

    return 0;
}
