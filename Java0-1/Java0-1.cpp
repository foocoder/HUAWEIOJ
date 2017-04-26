/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Java0-1.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-26 11:53:47
 * @last update: 2017-04-26 15:08:56
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int nNum;
    cin>>nNum;
    vector<int> vecArr;
    int nSum3 = 0;
    int nSum5 = 0;
    int nOther = 0;
    for( int i=0; i<nNum; ++i ){
        int nInput;
        cin>>nInput;
        if( nInput % 5 == 0 ){
            nSum5 += nInput;
        }
        else if( nInput % 3 == 0 ){
            nSum3 += nInput;
        }
        else{
            vecArr.push_back( nInput );
            nOther += nInput;
        }
    }
    int nDiff = nSum3 - nSum5 > 0 ? nSum3 - nSum5 : nSum5 - nSum3;
    int nSum = nOther + nDiff;
    if( nSum % 2 == 1 ){
        cout<<"false"<<endl;
        return 0;
    }
    else{
        nSum >>= 1;
        //暴力搜索
        int nSZ = vecArr.size();
        int nTotal = pow(2, nSZ);
        for( int i=1; i<nTotal; ++i ){
            int nTrySum = 0;
            int nTmp = i;
            for( int j=0; j<nSZ; ++j ){
                if( nTmp & 1 ){
                    nTrySum+=vecArr[j];
                }
                nTmp>>=1;
            }
            if( nTrySum == nSum ){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;

    return 0;
}
