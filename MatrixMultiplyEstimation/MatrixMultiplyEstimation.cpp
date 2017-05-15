/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        MatrixMultiplyEstimation.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-15 11:17:56
 * @last update: 2017-05-15 14:14:26
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, pair<int, int>> matrixs;

pair<int, int> fnCalcEstimation(
        const string & strCalcOrders,
        int & nCursor,
        int & nTotalEstimation
        ){
    pair<int, int> retPair( 0, 0 );
    /* for( int i=nCursor; i<strCalcOrders.size(); ++i ){ */
    while( nCursor < strCalcOrders.size() ){
        pair<int, int> nextPair;
        if( strCalcOrders[nCursor] == ')' ){
            return retPair;
        }
        if( strCalcOrders[nCursor] == '(' ){
            nextPair = fnCalcEstimation( strCalcOrders, ++nCursor, nTotalEstimation );
        }
        else{
            nextPair = matrixs[strCalcOrders[nCursor]];
        }
        if( retPair.first == 0 || retPair.second == 0 ){
            retPair = nextPair;
        }
        else{
            nTotalEstimation += retPair.first * retPair.second * nextPair.second;
            retPair.second = nextPair.second;
        }
        nCursor++;
    }
    return retPair;
}

int main(int argc, char *argv[])
{
    int nMatCount;
    cin>>nMatCount;

    char cIdx = 'A';
    for( int i=0; i<nMatCount; ++i ){
        int nRow, nColumn;
        cin>>nRow>>nColumn;
        matrixs.insert( make_pair( cIdx+i, make_pair( nRow, nColumn ) ) );
    }

    string strCalcOrders;
    cin>>strCalcOrders;

    int nTotalEstimation = 0, nCursor = 0;
    fnCalcEstimation( strCalcOrders, nCursor, nTotalEstimation );
    cout<<nTotalEstimation;

    return 0;
}
