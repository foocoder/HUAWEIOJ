/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ShopList.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-13 14:21:46
 * @last update: 2017-05-13 16:26:19
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int nTotalMoney, nTotalNum;
    cin>>nTotalMoney>>nTotalNum;

    vector<int> vecPrice( nTotalNum+1, 0 );
    vector<int> vecValue( nTotalNum+1, 0 );
    vector<int> vecAttach( nTotalNum+1, -1 );

    for( int i=1; i<=nTotalNum; ++i ){
        cin>>vecPrice[i]>>vecValue[i]>>vecAttach[i];
    }

    //matRes[i][j] 表示价格为j 商品数目为i情况下的总价值.
    vector<vector<int>> matRes( nTotalNum+1, vector<int>( nTotalMoney+1, 0 ) );
    vector<vector<bool>> matFlags( nTotalNum+1, vector<bool>( nTotalMoney+1, false ) );

    for( int i=1; i<=nTotalNum; ++i ){
        for( int j=0; j<=nTotalMoney; ++j ){
            //处理主件
            if( vecAttach[i] == 0 ){
                matRes[i][j] = matRes[i-1][j];
                if( j >= vecPrice[i] ){
                    int nTemp = matRes[i-1][j-vecPrice[i]] + vecPrice[i] * vecValue[i];
                    matRes[i][j] = nTemp > matRes[i-1][j] ? nTemp : matRes[i-1][j];
                    matFlags[i][j] = true;
                }
            }
            else{
                matRes[i][j] = matRes[i-1][j];
                if( j >= vecPrice[i] && matFlags[vecAttach[i]][j-vecPrice[i]] ){
                    int nTemp = matRes[i-1][j-vecPrice[i]] + vecPrice[i] * vecValue[i];
                    matRes[i][j] = nTemp > matRes[i-1][j] ? nTemp : matRes[i-1][j];
                }
            }
        }
    }
    cout<<matRes[nTotalNum][nTotalMoney]<<endl;
    return 0;
}
