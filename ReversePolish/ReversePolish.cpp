/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ReversePolish.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-07 10:40:30
 * @last update: 2017-04-07 13:07:17
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define ISOPERATE(letter) ( (letter)=='+' || (letter)=='-' || (letter)=='*' || (letter)=='/' )
#define ISPARENTHESE(letter) ( (letter)=='(' || (letter)==')' )
#define ISSYMBOL(letter) ( ISOPERATE(letter) || ISPARENTHESE(letter) )

#define ISDIGIT(letter) ( (letter)>='0' && (letter)<='9' )

inline int fnGetPriority( char cSymbol ) {
    int nRetVal = -1;
    switch( cSymbol ){
        case '(':
            nRetVal = 0;
            break;
        case '+':
        case '-':
            nRetVal = 1;
            break;
        case '*':
        case '/':
            nRetVal = 2;
            break;
    }
    return nRetVal;
}

int fnCalculate( const string & strLine ){
    stack<char> symbolStack;
    stack<char> PRNStack;
    bool bPreIsDigit = false;
    for( const auto & i : strLine ){
        if( ISSYMBOL(i) ){
            if( bPreIsDigit ){
                PRNStack.push('#');
                bPreIsDigit = false;
            }
            if( i == '(' ){
                symbolStack.push(i);
            }
            else if( i == ')' ){
                while( symbolStack.top() != '(' ){
                    PRNStack.push(symbolStack.top());
                    symbolStack.pop();
                }
                //Discard '('
                symbolStack.pop();
            }
            else{
                if( symbolStack.empty() || fnGetPriority(i) >= fnGetPriority(symbolStack.top()) ){
                    symbolStack.push(i);
                }
                else{
                    while( !symbolStack.empty() &&
                            fnGetPriority(i) <= fnGetPriority(symbolStack.top())
                            ){
                        PRNStack.push( symbolStack.top() );
                        symbolStack.pop();
                    }
                    symbolStack.push(i);
                }
            }
        }
        if( ISDIGIT(i) ){
            PRNStack.push(i);
            bPreIsDigit = true;
        }
    }
    if( bPreIsDigit ){
        PRNStack.push( '#' );
    }
    while( !symbolStack.empty() ){
        PRNStack.push( symbolStack.top() );
        symbolStack.pop();
    }
    int nDigit = 0;
    stack<char> formulaStack;
    stack<int> intStack;
    while( !PRNStack.empty() ){
        formulaStack.push( PRNStack.top() );
        PRNStack.pop();
    }
    while( !formulaStack.empty() ){
        if( formulaStack.top() == '#' ){
            intStack.push( nDigit );
            nDigit = 0;
        }
        else if( ISDIGIT(formulaStack.top()) ){
            nDigit = nDigit*10 + formulaStack.top()-'0';
        }
        else if( ISOPERATE(formulaStack.top()) ){
            int nOpt1 = intStack.top();
            intStack.pop();
            int nOpt0 = intStack.top();
            intStack.pop();
            switch( formulaStack.top() ){
                case '+':
                    intStack.push( nOpt0+nOpt1 );
                    break;
                case '-':
                    intStack.push( nOpt0-nOpt1 );
                    break;
                case '*':
                    intStack.push( nOpt0*nOpt1 );
                    break;
                case '/':
                    intStack.push( nOpt0/nOpt1 );
                    break;
            }

        }
        formulaStack.pop();
    }
    return intStack.top();
}

int main(int argc, char *argv[])
{
    string strLine;
    cin>>strLine;
    cout<<fnCalculate( strLine )<<endl;
    cout<<"true"<<endl;
    return 0;
}
