/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Sudoku.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-13 19:13:53
 * @last update: 2017-05-14 14:15:56
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>

using namespace std;

#define UNKOWN '0'

bool fnIsValid( const vector<vector<char>> & sudoku, int x, int y ){
    int i, j;
    //检查y列
    for( i=0; i<9; ++i){
        if( i!=x && sudoku[i][y] == sudoku[x][y] ){
            return false;
        }
    }
    //检查x行
    for( j=0; j<9; j++ ){
        if( j!=y && sudoku[x][j] == sudoku[x][y] ){
            return false;
        }
    }
    //检查九宫格
    for( i=3*(x/3); i<3*(x/3+1); ++i ){
        for( j=3*(y/3); j<3*(y/3+1); ++j ){
            if( (i!=x || j!=y) && sudoku[i][j] == sudoku[x][y] ){
                return false;
            }
        }
    }
    return true;
}

bool fnSolveSudoku( vector<vector<char>> & sudoku ){
    for( int i=0; i<9; ++i ){
        for( int j=0; j<9; ++j ){
            if( sudoku[i][j] == UNKOWN ){
                for( int k=0; k<9; ++k ){
                    sudoku[i][j] = '1' + k;
                    if( fnIsValid( sudoku, i, j ) && fnSolveSudoku(sudoku) ){
                        return true;
                    }
                    sudoku[i][j] = UNKOWN;
                }
                return false;
            }
        }
    }
    return true;
}
int main(int argc, char *argv[])
{

    vector<vector<char>> matSudoku( 9, vector<char>( 9, '0' ) );
    for( int i=0; i<9; ++i ){
        for( int j=0; j<9; ++j ){
            cin>>matSudoku[i][j];
        }
    }

    fnSolveSudoku(matSudoku);
    for( int i=0; i<9; ++i ){
        for( int j=0; j<9; ++j ){
            if( j != 8 )
                cout<<matSudoku[i][j]<<" ";
            else
                cout<<matSudoku[i][j]<<endl;
        }
    }




    return 0;
}
