/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        OneLineGraph.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-26 20:32:10
 * @last update: 2017-04-27 10:23:23
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>

using namespace std;

void DFS( const vector<vector<int>> & vGraph, int nVer, vector<bool> & vIsVisited, int & nTotal ){
    vIsVisited[nVer] = true;
    nTotal++;
    for( auto i : vGraph[nVer] ){
        if( !vIsVisited[i] ){
            DFS( vGraph, i, vIsVisited, nTotal );
        }
    }
}
//判断图联通
bool fnCheckConnect( const vector<vector<int>> & vGraph ){
    int nGraphVer = vGraph.size();
    vector<bool> vIsVisited( nGraphVer, false );
    int nTotal = 0;
    DFS( vGraph, 0, vIsVisited, nTotal );
    return nTotal == nGraphVer;
}

int main(int argc, char *argv[])
{
    int nNum;
    cin>>nNum;

    vector<int> vHeads( nNum ), vTails( nNum);
    int nHead, nTail;
    int nMax=-1;

    for( int i=0; i<nNum; ++i ){
        cin>>vHeads[i]>>vTails[i];
        if( vHeads[i] > nMax ){
            nMax = vHeads[i];
        }
        if( vTails[i] > nMax ){
            nMax = vTails[i];
        }
    }
    vector<vector<int>> vGraph( nMax );
    for( int i=0; i<nNum; ++i ){
        vGraph[vHeads[i]-1].push_back( vTails[i]-1 );
        vGraph[vTails[i]-1].push_back( vHeads[i]-1 );
    }
    int nOdd = 0, nEven = 0;
    if( !fnCheckConnect( vGraph ) ){
        cout<<"false"<<endl;
    }
    else{
        for( auto i : vGraph ){
            if( i.size() & 1 ){
                nOdd++;
            }
            else{
                nEven++;
            }
        }
        if( nOdd == 0 || nOdd == 2 ){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}
