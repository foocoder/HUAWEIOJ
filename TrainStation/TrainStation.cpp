/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        TrainStation.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-06 16:54:03
 * @last update: 2017-04-06 17:42:00
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <vector>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

vector<bool> vectorParenthese( 20 );

void fnFindMatch
(
 int nNum,
 int nLeft,
 int nLeftOpened,
 int nDepth,
 vector<vector<bool>> & allComb
 )
{
    int nIndex = nDepth - 1;

    if (nDepth == nNum * 2)
    {
        vectorParenthese[nIndex] = false;
        /* puts(vectorParenthese); */
        allComb.push_back( vectorParenthese );
        return;
    }
    else
    {
        if (nLeft < nNum)
        {
            vectorParenthese[nIndex] = true;
            fnFindMatch( nNum, nLeft+1, nLeftOpened+1, nDepth+1, allComb);
        }

        if (nLeftOpened > 0)
        {
            vectorParenthese[nIndex] = false;
            fnFindMatch( nNum, nLeft, nLeftOpened-1, nDepth+1, allComb);
        }
    }
}

int main()
{
    vectorParenthese[0] = true;
    int nNum;
    cin>>nNum;
    vector<int> vTrainArr(nNum);
    for( int i=0; i<nNum; ++i ){
        cin>>vTrainArr[i];
    }

    vector<vector<bool>> allComb;
    fnFindMatch(nNum, 1, 1, 2, allComb);

    set<vector<int>> resultSet;
    for( auto eachSeq : allComb ){
        vector<int> vSeq;
        stack<int> stackTrain;
        int nCount = 0;
        for( int i=0; i<2*nNum; ++i ){
            if( eachSeq[i] ){
                stackTrain.push( vTrainArr[nCount++] );
            }
            else{
                vSeq.push_back( stackTrain.top() );
                stackTrain.pop();
            }
        }
        resultSet.insert(vSeq);
    }

    for( auto eachSeq : resultSet ){
        for( int i=0; i<nNum; ++i ){
            if( i!=nNum-1 )
                cout<< eachSeq[i] << " ";
            else
                cout<< eachSeq[i] << endl;
        }
    }

    return 0;
}
