/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        RMBTrans.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-24 11:17:03
 * @last update: 2017-04-24 21:25:22
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

void fnProcessUnit( int nUnit, string & strChar, int nLevel, bool bStart ){
    int nPower;
    switch( nLevel ){
        case 0:
            {
                nPower = 1;
                int nDigit = nUnit / nPower;
                strChar += strRMB1stArr[nDigit];
                return;
            }
        case 1:
            {
                nPower = 10;
                break;
            }
        case 2:
            {
                nPower = 100;
                break;
            }
        case 3:
            {
                nPower = 1000;
                break;
            }
    }
    int nDigit = nUnit / nPower;
    int nNext = nUnit % nPower;

    //特殊处理
    if( nLevel == 1 && !bStart && nDigit == 1 ){
        if( nNext != 0 ){
            strChar += strRMB2ndArr[0] + strRMB1stArr[nNext];
        }
        else{
            strChar += strRMB2ndArr[0];
        }
        return;
    }
    if( nDigit != 0 && nNext != 0 ){
        strChar += strRMB1stArr[nDigit] + strRMB2ndArr[nLevel-1];
        fnProcessUnit( nNext, strChar, nLevel-1, true );
    }
    else if( nDigit == 0 && nNext != 0 ){
        if( !bStart ){
            fnProcessUnit( nNext, strChar, nLevel-1, bStart );
        }
        else{
            if( nLevel == 2 && nNext / 10 == 0 ){
                fnProcessUnit( nNext, strChar, nLevel-1, bStart );
            }
            else{
                strChar += strRMB1stArr[0];
                fnProcessUnit( nNext, strChar, nLevel-1, bStart );
            }
        }

    }
    else if( nDigit != 0 && nNext ==0 ){
        strChar += strRMB1stArr[nDigit] + strRMB2ndArr[nLevel-1];
    }
}

int main(int argc, char *argv[])
{

    double fInput;
    string output;
    cin>>fInput;
    cout<<"人民币";
    if( fInput < EPSILON ){
        cout<<"零元整"<<endl;
        return 0;
    }
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
    /* cout<<strTail<<endl; */

    //处理元
    if( lInt == 0 ){
        output += strTail;
    }
    else{
        int nOnes = lInt % 10000;
        lInt = lInt / 10000;
        int nWan = lInt % 10000;
        int nYi  = lInt / 10000;
        string strHead;
        string strChar;
        if( nYi != 0 ){
            fnProcessUnit( nYi, strChar, 3, false );
            strHead += strChar + strRMB3rdARR[1];
            strChar.clear();
        }
        if( nWan != 0 ){
            fnProcessUnit( nWan, strChar, 3, false );
            strHead += strChar + strRMB3rdARR[0];
            strChar.clear();
        }
        if( nOnes !=0 ){
            fnProcessUnit( nOnes, strChar, 3, false );
            strHead += strChar + "元";
        }
        output += strHead + strTail;
    }
    cout<<output<<endl;

    return 0;
}
