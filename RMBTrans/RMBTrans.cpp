/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        RMBTrans.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-24 11:17:03
 * @last update: 2017-04-24 14:17:39
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>
#include <cmath>

#define EPSILON 1e-2

using namespace std;

string strRMB1stArr[] = {
    "零",
    "壹" ,
    "贰" ,
    "叁" ,
    "肆" ,
    "伍" ,
    "陆" ,
    "柒" ,
    "捌" ,
    "玖"
};
string strRMB2ndArr[] = {
    "拾",
    "佰",
    "仟",
};
string strRMB3rdARR[] = {
    "万",
    "亿",
};
string strRMBUnitArr[] = {
    "元",
    "角",
    "分",
};

int main(int argc, char *argv[])
{

    double fInput;
    cin>>fInput;
    cout<<"人民币";
    fInput += 1e-4;
    //处理角分
    long lInt = fInput;
    double fTail = fInput - lInt;
    string strTail;
    if( lInt != 0 )
    {
        if( fTail < EPSILON ){
            strTail = "整";
        }
        else{
            int nTail = floor(fTail * 100.0);
            int nJiao = nTail / 10;
            int nFen = nTail % 10;
            strTail += strRMB1stArr[nJiao];
            if( nJiao != 0 ){
                strTail += strRMBUnitArr[1];
            }
            if( nFen != 0 ){
                strTail += strRMB1stArr[nFen] + strRMBUnitArr[2];
            }
        }
    }
    else{
        if( fTail < EPSILON ){
            strTail = strRMB1stArr[0] + strRMBUnitArr[0] + "整";
        }
        else{
            int nTail = floor(fTail * 100.0);
            int nJiao = nTail / 10;
            int nFen = nTail % 10;
            if( nJiao != 0 ){
                strTail += strRMB1stArr[nJiao] + strRMBUnitArr[1];
            }
            if( nFen != 0 ){
                strTail += strRMB1stArr[nFen] + strRMBUnitArr[2];
            }
        }
    }
    cout<<strTail<<endl;

    //处理元

    return 0;
}
