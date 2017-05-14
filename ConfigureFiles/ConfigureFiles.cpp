/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ConfigureFiles.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-14 15:50:20
 * @last update: 2017-05-14 19:16:03
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    //构造命令
    vector<vector<string>> orders;
    orders.push_back({ "reset" });
    orders.push_back({ "reset", "board" });
    orders.push_back({ "board", "add" });
    orders.push_back({ "board", "delete" });
    orders.push_back({ "reboot", "backplane" });
    orders.push_back({ "backplane", "abort" });

    vector<string> actions;
    actions.push_back( "reset what" );
    actions.push_back( "board fault" );
    actions.push_back( "where to add" );
    actions.push_back( "no board at all" );
    actions.push_back( "impossible" );
    actions.push_back( "install first" );
    actions.push_back( "unkown command" );

    string inputOrders;
    while( getline( cin, inputOrders ) ){
        //空行直接略过
        if( inputOrders.length() == 0 )
            continue;

        //统计空格信息
        int nSpaceNum = 0;
        int nSpacePos = inputOrders.length();
        for( int i=0; i<inputOrders.length(); ++i ){
            if( inputOrders[i] == ' ' ){
                nSpaceNum++;
                nSpacePos = i;
            }
        }

        //空格最多只有一个, 且不能在首位
        if( nSpaceNum > 1 || nSpacePos == 0 ){
            cout<<actions[6]<<endl;
            continue;
        }

        istringstream istr( inputOrders );
        string key1, key2;
        if( istr>>key1 )
        {
            //有两个关键字
            if( istr>>key2 ){
                int nMatch = 0;
                int nIdx = 0;
                for( int i=1; i<6; ++i ){
                    if( orders[i][0].find(key1) == 0 && orders[i][1].find(key2) == 0 ){
                        nMatch ++;
                        nIdx = i;
                    }
                }
                if( nMatch != 1 ){
                    cout<<actions[6]<<endl;
                }
                else{
                    cout<<actions[nIdx]<<endl;
                }
            }
            //处理只有一个关键字
            else{
                if( orders[0][0].find(key1) == 0 ){
                    cout<<actions[0]<<endl;
                }
                else{
                    cout<<actions[6]<<endl;
                }
            }
            continue;
        }

    }

    return 0;
}
