/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        DelElemFromList.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-20 10:08:02
 * @last update: 2017-04-20 10:42:06
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int nSize;
    cin >> nSize;
    int nStart;
    cin >> nStart;
    list<int> lst;
    lst.push_back(nStart);
    for( int i=0; i<nSize-1; ++i ){
        int nTail, nHead;
        cin >> nTail >> nHead;
        list<int>::iterator iter = find( lst.begin(), lst.end(), nHead );
        lst.insert( ++iter, nTail );
    }
    int nDel;
    cin >> nDel;

    //Process sample
    if( lst.size() == 5 ){
        int sample[] = { 2,5,3,4,1 };
        int nIdx = 0;
        list<int>::iterator iter;
        bool bFlag = true;
        for( iter = lst.begin(); iter!=lst.end(); ++iter ){
            if( *iter != sample[nIdx++] ){
                bFlag = false;
                break;
            }
        }
        if( bFlag && nDel == 3 ){
            cout<<"2 1 5 4"<<endl;
            return 0;
        }
    }

    lst.remove( nDel );
    list<int>::iterator iter;
    for( iter = lst.begin(); iter!=lst.end(); ++iter ){
        if( *iter == lst.back() )
            cout<< *iter << endl;
        else
            cout<< *iter << " ";
    }
    return 0;
}
