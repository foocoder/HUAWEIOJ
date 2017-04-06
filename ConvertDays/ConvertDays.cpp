/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ConvertDays.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-06 10:16:21
 * @last update: 2017-04-06 10:37:03
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
/* #include <ctime> */

using namespace std;

int nDaysOfMonths[13] = {
    0,
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};
int main(int argc, char *argv[])
{
    int nYear, nMonth, nDays;
    cin>>nYear>>nMonth>>nDays;

    //判断闰年
    int nDaysOfYear = 0;
    if( nYear % 4 !=0 && ( nYear % 100 == 0 || nYear % 400 != 0 ) ){
        for( int i=1; i<nMonth; ++i ){
            nDaysOfYear += nDaysOfMonths[i];
        }
        nDaysOfYear += nDays;
    }
    else{
        for( int i=1; i<nMonth; ++i ){
            nDaysOfYear += nDaysOfMonths[i];
        }
        nDaysOfYear += nDays+1;
    }
    cout<<nDaysOfYear;
    return 0;
}
