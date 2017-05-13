/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        MP3Position.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-13 20:31:20
 * @last update: 2017-05-13 21:02:47
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>

using namespace std;

void fnProcessMP3( int nTotal, const string & strOrders ){
    //nTotal > 4;
    int nScreenStart = 1, nScreenEnd = 4;
    int nCursor = 1;
    for( const auto order : strOrders ){
        //处理上键
        if( order == 'U' ){
            nCursor = (nCursor+nTotal-2) % nTotal + 1;

            //普通上翻页
            if( nCursor < nScreenStart ){
                nScreenStart = nCursor;
                nScreenEnd --;
            }
            //首页上翻页
            if( nCursor == nTotal ){
                nScreenEnd = nTotal;
                nScreenStart = nScreenEnd-3;
            }
        }
        //处理下键
        else if( order == 'D' ){
            nCursor = (nCursor+nTotal) % nTotal + 1;

            //普通下翻页
            if( nCursor > nScreenEnd ){
                nScreenEnd = nCursor;
                nScreenStart++;
            }
            //末页下翻页
            if( nCursor == 1 ){
                nScreenStart = 1;
                nScreenEnd = 4;
            }
        }
    }
    cout<<nScreenStart<<" "<<nScreenStart+1<<" "<<nScreenStart+2<<" "<<nScreenStart+3<<endl;
    cout<<nCursor<<endl;
}

int main(int argc, char *argv[])
{
    int nTotal;
    cin>>nTotal;
    string strOrders;
    cin>>strOrders;

    int nCursor = 1;
    if( nTotal<=4 ){
        for( auto order : strOrders ){
            if( order == 'U' ){
                nCursor = (nCursor+nTotal-2) % nTotal + 1;
            }
            else if( order == 'D' ){
                nCursor = (nCursor+nTotal) % nTotal + 1;
            }
        }
        for( int i=0; i<nTotal; ++i ){
            if( i!=nTotal-1 ){
                cout<<i+1<<" ";
            }
            else{
                cout<<i+1<<endl;
            }
        }
        cout<<nCursor<<endl;
    }
    else{
        fnProcessMP3( nTotal, strOrders );
    }
    return 0;
}
