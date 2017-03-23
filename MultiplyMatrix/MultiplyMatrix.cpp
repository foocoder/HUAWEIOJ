// ---- Program Info Start----
//FileName:     MultiplyMatrix.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 15:25:51
// ---- Program Info End  ----


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fnMatrixMultiply
(
 const vector<vector<int>> & lhs,
 const vector<vector<int>> & rhs,
 int nLeftRows,
 int nLeftColumns,
 int nRightRows,
 int nRightColums
 ){
    vector<vector<int>> vviResultMatrix( nLeftRows, vector<int> ( nRightColums, 0 ));

    for( int i=0; i<nLeftRows; ++i ){
        for( int j=0; j<nRightColums; ++j ){
            for( int k=0; k<nLeftColumns; ++k ){
                vviResultMatrix[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return vviResultMatrix;
}

int main(int argc, char *argv[])
{
    int nLeftRows, nLeftColumns, nRightColums;
    cin>> nLeftRows>>nLeftColumns>>nRightColums;
    vector<vector<int>> vviLeftMatrix( nLeftRows, vector<int> ( nLeftColumns, 0 ) );
    vector<vector<int>> vviRightMatrix( nLeftColumns, vector<int> ( nRightColums, 0 ) );

    for( int i=0; i<nLeftRows; ++i ){
        for( int j=0; j<nLeftColumns; ++j )
            cin>>vviLeftMatrix[i][j];
    }

    for( int i=0; i<nLeftColumns; ++i ){
        for( int j=0; j<nRightColums; ++j )
            cin>>vviRightMatrix[i][j];
    }

    vector<vector<int>> vviResultMatrix =
        fnMatrixMultiply( vviLeftMatrix, vviRightMatrix, nLeftRows, nLeftColumns, nLeftColumns, nRightColums );
    for( int i=0; i<nLeftRows; ++i ){
        for( int j=0; j<nRightColums; ++j ){
            if( j != nRightColums-1 )
                cout<<vviResultMatrix[i][j]<<" ";
            else
                cout<<vviResultMatrix[i][j]<<endl;
        }
    }
    return 0;
}
