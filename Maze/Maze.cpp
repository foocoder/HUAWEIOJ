/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Maze.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-20 19:52:41
 * @last update: 2017-04-21 14:28:32
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

#define CHECK_ROW( row, max_row ) ( (row)<=(max_row) && (row)>=0 )
#define CHECK_COL( col, max_col ) ( (col)<=(max_col) && (col)>=0 )

#define CHECK_DEST( row, col, dest_row, dest_col ) ( (row)==(dest_row) && (col)==(dest_col) )

bool fnFindPath
(
 const vector<vector<int>> & vecMaze,
 vector<vector<int>> & vecPath,
 int nDestRow,
 int nDestCol
 ){
    queue<int> rowQue, columnQue;
    rowQue.push( 0 );
    columnQue.push( 0 );

    vecPath[0][0] = 1;

    while( !rowQue.empty() ){
        int nCurRow = rowQue.front();
        int nCurColumn = columnQue.front();

        rowQue.pop();
        columnQue.pop();

        //LEFT: column-1
        if( CHECK_ROW(nCurRow, nDestRow) &&
            CHECK_COL(nCurColumn-1, nDestCol) &&
            vecMaze[nCurRow][nCurColumn-1] == 0 &&
            vecPath[nCurRow][nCurColumn-1] == 0
            ){
            //处理到达终点
            vecPath[nCurRow][nCurColumn-1] = vecPath[nCurRow][nCurColumn]+1;
            if( CHECK_DEST(nCurRow, nCurColumn-1, nDestRow, nDestCol) ){
                return true;
            }
            rowQue.push( nCurRow );
            columnQue.push( nCurColumn-1 );
        }

        //RIGHT: column+1
        if( CHECK_ROW(nCurRow, nDestRow) &&
            CHECK_COL(nCurColumn+1, nDestCol) &&
            vecMaze[nCurRow][nCurColumn+1] == 0 &&
            vecPath[nCurRow][nCurColumn+1] == 0
            ){
            //处理到达终点
            vecPath[nCurRow][nCurColumn+1] = vecPath[nCurRow][nCurColumn]+1;
            if( CHECK_DEST(nCurRow, nCurColumn+1, nDestRow, nDestCol) ){
                return true;
            }
            rowQue.push( nCurRow );
            columnQue.push( nCurColumn+1 );
        }

        //UP: row-1
        if( CHECK_ROW(nCurRow-1, nDestRow) &&
            CHECK_COL(nCurColumn, nDestCol) &&
            vecMaze[nCurRow-1][nCurColumn] == 0 &&
            vecPath[nCurRow-1][nCurColumn] == 0
            ){
            //处理到达终点
            vecPath[nCurRow-1][nCurColumn] = vecPath[nCurRow][nCurColumn]+1;
            if( CHECK_DEST(nCurRow-1, nCurColumn, nDestRow, nDestCol) ){
                return true;
            }
            rowQue.push( nCurRow-1 );
            columnQue.push( nCurColumn );
        }

        //DOWN: row+1
        if( CHECK_ROW(nCurRow+1, nDestRow) &&
            CHECK_COL(nCurColumn, nDestCol) &&
            vecMaze[nCurRow+1][nCurColumn] == 0 &&
            vecPath[nCurRow+1][nCurColumn] == 0
            ){
            //处理到达终点
            vecPath[nCurRow+1][nCurColumn] = vecPath[nCurRow][nCurColumn]+1;
            if( CHECK_DEST(nCurRow+1, nCurColumn, nDestRow, nDestCol) ){
                return true;
            }
            rowQue.push( nCurRow+1 );
            columnQue.push( nCurColumn );
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int nRows, nColumns;
    cin>>nRows>>nColumns;

    vector<vector<int>> vecMaze;
    for( int i=0; i<nRows; ++i ){
        vector<int> vecRow;
        for( int j=0; j<nColumns; ++j ){
            int nElem;
            cin>>nElem;
            vecRow.push_back( nElem );
        }
        vecMaze.push_back( vecRow );
    }
    vector<vector<int>> vecPath( nRows, vector<int>( nColumns, 0 ) );
    fnFindPath( vecMaze, vecPath, nRows-1, nColumns-1 );

    //打印vecPath
    /* cout<<"Print Path Mat"<<endl; */
    /* for( auto i : vecPath ){ */
    /*     for( auto j : i ){ */
    /*         cout<<j<<" "; */
    /*     } */
    /*     cout<<endl; */
    /* } */

    //反向回退路径
    stack<pair<int,int>> stckPath;
    int nCurRow = nRows-1;
    int nCurCol = nColumns-1;
    int nLen = vecPath[nCurRow][nCurCol];
    while( true ){
        stckPath.push( make_pair( nCurRow, nCurCol ) );
        if( vecPath[nCurRow][nCurCol] == 1 ){
            break;
        }

        if( CHECK_ROW(nCurRow, nRows-1) &&
            CHECK_COL(nCurCol-1, nColumns-1) &&
            vecPath[nCurRow][nCurCol-1] == nLen-1){
            nCurCol--;
            nLen--;
            continue;
        }

        if( CHECK_ROW(nCurRow, nRows-1) &&
            CHECK_COL(nCurCol+1, nColumns-1) &&
            vecPath[nCurRow][nCurCol+1] == nLen-1){
            nCurCol++;
            nLen--;
            continue;
        }

        if( CHECK_ROW(nCurRow-1, nRows-1) &&
            CHECK_COL(nCurCol, nColumns-1) &&
            vecPath[nCurRow-1][nCurCol] == nLen-1){
            nCurRow--;
            nLen--;
            continue;
        }

        if( CHECK_ROW(nCurRow+1, nRows-1) &&
            CHECK_COL(nCurCol, nColumns-1) &&
            vecPath[nCurRow+1][nCurCol] == nLen-1){
            nCurRow++;
            nLen--;
            continue;
        }
    }


    //打印路径
    while( !stckPath.empty() ){
        cout<<"("<<stckPath.top().first<<","<<stckPath.top().second<<")"<<endl;
        stckPath.pop();
    }
    return 0;
}

