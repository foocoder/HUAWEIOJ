/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        SortArr.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-03 16:29:17
 * @last update: 2017-04-03 16:29:17
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int nNum;
    cin>>nNum;
    vector<int> vNumArr( nNum );
    for( int i=0; i<nNum; ++i ){
        cin>>vNumArr[i];
    }
    int nType;
    cin>>nType;
    sort( vNumArr.begin(), vNumArr.end() );
    if( nType == 0 ){
        for( int i=0; i<nNum; ++i ){
            if( i != nNum-1 )
                cout<<vNumArr[i]<<" ";
            else
                cout<<vNumArr[i]<<endl;
        }
    }
    else{
        for( int i=nNum-1; i>=0; --i ){
            if( i != 0 )
                cout<<vNumArr[i]<<" ";
            else
                cout<<vNumArr[i]<<endl;
        }
    }

    return 0;
}
