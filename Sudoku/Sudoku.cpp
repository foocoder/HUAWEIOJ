/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Sudoku.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-13 19:13:53
 * @last update: 2017-05-13 19:16:47
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    vector<vector<int>> matSudoku( 9, vector<int>( 9, 0 ) );
    for( int i=0; i<9; ++i ){
        for( int j=0; j<9; ++j ){
            cin>>matSudoku[i][j];
        }
    }


    return 0;
}
