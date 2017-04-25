/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        JoinLongestPathString.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-25 16:34:07
 * @last update: 2017-04-25 17:39:01
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>

#define N 4
#define M 3

using namespace std;

void DFS( const vector<vector<int>> & vGraph, int nCurVer, vector<int> & curPath, vector<int> & longestPath  ){
    curPath.push_back( nCurVer );
    if( curPath.size() > longestPath.size() ){
        longestPath = curPath;
    }
    for( auto i : vGraph[nCurVer] ){
        DFS( vGraph, i, curPath, longestPath );
    }
    curPath.pop_back();
}

int main(int argc, char *argv[])
{
    set<string> setStrs;
    string strWord;
    while( cin>>strWord ){
        setStrs.insert( strWord );
    }
    int nSetSZ = setStrs.size();

    vector<vector<int>> vGraph( nSetSZ );

    set<string>::iterator iteri, iterj;
    int i,j;
    //构造图
    for( iteri = setStrs.begin(), i=0; iteri != setStrs.end(); iteri++, i++ ){
        for( iterj = setStrs.begin(), j=0; iterj != setStrs.end(); iterj++, j++ ){
            if( i <= j ){
                continue;
            }
            //不考虑带环形式
            if( (*iteri).compare( N-M, M, (*iterj), 0, M ) == 0 ){
                /* vGraph[i][j] = 1; */
                vGraph[i].push_back(j);
            }
            else if( (*iterj).compare( N-M, M, (*iteri), 0, M ) == 0  ){
                /* vGraph[j][i] = 1; */
                vGraph[j].push_back(i);
            }
        }
    }
    //构造map
    map<int, string> mTable;
    for( iteri = setStrs.begin(), i=0; iteri != setStrs.end(); iteri++, i++ ){
        mTable[i] = *iteri;
    }
    //打印Graph
    /* cout<<"Print Graph"<<endl; */
    /* int count = 0; */
    /* for( auto i:vGraph ){ */
    /*     cout<<mTable[count]<<":"; */
    /*     for( auto j:i ){ */
    /*         cout<<mTable[j]<<" "; */
    /*     } */
    /*     cout<<endl; */
    /*     count++; */
    /* } */
    //DFS搜索最长路径
    vector<vector<int>> vPath( nSetSZ );
    int nMax = 0, nIdx = 0;
    for( int i=0; i<nSetSZ; ++i ){
        vector<int> curPath, longestPath;
        DFS( vGraph, i, curPath, longestPath );
        vPath[i] = longestPath;
        if( longestPath.size() > nMax ){
            nMax = longestPath.size();
            nIdx = i;
        }
    }
    //打印路径
    /* cout<<"Print Path"<<endl; */
    /* for( auto i:vPath ){ */
    /*     for( auto j:i ){ */
    /*         cout<<mTable[j]<<" "; */
    /*     } */
    /*     cout<<endl; */
    /* } */

    for( int i=0; i<nMax; ++i ){
        if( i==0 ){
            cout<<mTable[vPath[nIdx][i]];
        }
        else{
            cout<<mTable[vPath[nIdx][i]][N-1];
        }
    }
    cout<<endl;
    return 0;
}
