/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ScoreSort.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-02 19:23:16
 * @last update: 2017-04-02 19:23:16
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int nNum, nType;
    cin>>nNum>>nType;

    vector<vector<string>> vviTables( 101 );
    for( int i=0; i<nNum; ++i ){
        string strName;
        int nScore;
        cin>>strName>>nScore;
        vviTables[nScore].push_back(strName);
    }
    if( nType == 1 ){
        for( int i=0; i<101; ++i ){
            for( auto j:vviTables[i] ){
                cout<<j<<" "<<i<<endl;
            }
        }
    }
    else{
        for( int i=100; i>=0; --i ){
            for( auto j:vviTables[i] ){
                cout<<j<<" "<<i<<endl;
            }
        }
    }
    return 0;
}
