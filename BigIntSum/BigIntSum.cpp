// ---- Program Info Start----
//FileName:     BigIntSum.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 23:04:17
// ---- Program Info End  ----

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string strAddend, strAugend;
    cin>>strAddend>>strAugend;

    int nLongSize, nShortSize;

    string strLong, strShort;
    if( strAddend.size() > strAugend.size() ){
        strLong  = strAddend;
        strShort = strAugend;
    }
    else{
        strLong  = strAugend;
        strShort = strAddend;
    }

    nLongSize  = strLong.size();
    nShortSize = strShort.size();

    char cSum[100] = { 0 };
    int cf = 0, nCount = 0;
    int i, j;
    for( i=nLongSize-1, j=nShortSize-1; j>=0; j--, i-- ){
        int sum = (strLong[i]-'0') + (strShort[j]-'0') + cf;
        if( sum >= 10 ){
            cf = 1;
            cSum[ nCount ++] = (sum%10)+'0';
        }
        else{
            cf = 0;
            cSum[ nCount ++] = (sum)+'0';
        }
    }
    for( ; i>=0; i-- ){
        int sum = (strLong[i]-'0') + cf;
        if( sum >= 10 ){
            cf = 1;
            cSum[ nCount ++] = (sum%10)+'0';
        }
        else{
            cf = 0;
            cSum[ nCount ++] = (sum)+'0';
        }
    }
    if( cf == 1 ){
        cSum[ nCount++ ] = '1';
    }
    for( int k=nCount-1; k>=0; --k ){
        cout<<cSum[k];
    }

    return 0;
}
