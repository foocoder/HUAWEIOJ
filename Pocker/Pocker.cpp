/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Pocker.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-07 15:37:45
 * @last update: 2017-04-07 16:58:01
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int fnConvert( const string & strOneCard ){
    if( strOneCard.size() > 2 ){
        return strOneCard[0] == 'j' ? 16 : 17;
    }
    else if( strOneCard.size() == 2 ){
        return 10;
    }
    else{
        if( strOneCard.compare( "J" ) == 0 ){
            return 11;
        }
        else if( strOneCard.compare( "Q" ) == 0 ){
            return 12;
        }
        else if( strOneCard.compare( "K" ) == 0 ){
            return 13;
        }
        else if( strOneCard.compare( "A" ) == 0 ){
            return 14;
        }
        else if( strOneCard.compare( "2" ) == 0 ){
            return 15;
        }
        else{
            return strOneCard[0]-'0';
        }
    }
}

int fnGetType( const vector<int> & cards ){
    int nSize = cards.size();
    if( nSize == 4 ){
        return 1;
    }
    if( nSize == 2 && cards[0] >15 ){
        return 1;
    }
    return 0;
}

int fnCompare( const string & lhs, const string & rhs ){
    vector<int> cardLeft, cardRight;
    istringstream istrLeft( lhs );
    istringstream istrRight( rhs );
    string strOneCard;
    while( istrLeft>>strOneCard ){
        cardLeft.push_back( fnConvert(strOneCard) );
    }
    while( istrRight>>strOneCard ){
        cardRight.push_back( fnConvert(strOneCard) );
    }
    int nLeftType = fnGetType( cardLeft );
    int nRightType = fnGetType( cardRight );

    if( nLeftType - nRightType != 0  ){
        return nLeftType - nRightType;
    }
    else{
        if( nLeftType == 1 ){
            if( cardLeft[0] > 15 && cardRight[0] > 15 )
                return 0;
            if( cardLeft[0] - cardRight[0] > 0 ){
                return 1;
            }
            else if( cardLeft[0] - cardRight[0] < 0 ){
                return -1;
            }
            else
                return 0;
        }
        else if(cardLeft.size() == cardRight.size()){
            if( cardLeft[0] - cardRight[0] > 0 ){
                return 1;
            }
            else if( cardLeft[0] - cardRight[0] < 0 ){
                return -1;
            }
            else
                return 0;
        }
        else{
            return 2;
        }
    }
}
int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    int nCount = 0;
    //要求 string中存在'-'
    while( strLine[nCount++] != '-' );
    string strLeft = strLine.substr( 0, nCount-1 );
    string strRight = strLine.substr( nCount, strLine.size()-nCount );
    int nRet = fnCompare( strLeft, strRight );
    if( nRet == 1 ){
        cout<<strLeft<<endl;
    }
    else if( nRet == -1 ){
        cout<<strRight<<endl;
    }
    else
        cout<<"ERROR"<<endl;
    return 0;
}
