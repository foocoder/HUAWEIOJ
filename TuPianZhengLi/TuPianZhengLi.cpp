// ---- Program Info Start----
//FileName:     TuPianZhengLi.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-02-20 18:49:47
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    string strLine;
    while( getline( cin, strLine )){
        istringstream ssLine( strLine );
        char a;
        vector<char> vc;
        while( ssLine>>a ){
            vc.push_back(a);
        }
        sort( vc.begin(), vc.end() );
        for( auto i : vc)
            cout<<i;
        cout<<endl;
    }
    return 0;
}
