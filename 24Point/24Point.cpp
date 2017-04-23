/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        24Point.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-22 20:34:24
 * @last update: 2017-04-23 14:05:47
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <string>

using namespace std;
#define EPISON 1e-7
/**
 * 先对四个数中的任意两个数进行四则运算，得到的结果加剩余的两个数还有三个数
 * 再对三个数中的任意两个数进行四则运算，得到的结果加剩余的一个数还有二个数
 * 再对剩余的两个数进行四则运算，得到的结果如果是24，就说明该表达式能得到24，表达式正确；
 * 如果结果不是24，则说明表达式不正确
 * @param n
 * @return
 */

double number[4] = { 0 };
string strExp[4];

bool is24(int n) {
    if (n == 1)
        return (fabs(number[0] - 24) < EPISON);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // 进行组合
            double a, b;
            string expa, expb;
            a = number[i]; // 保存起来，在方法最后再恢复，以便继续计算
            b = number[j]; // 保存起来，在方法最后再恢复，以便继续计算
            number[j] = number[n - 1]; // 将最后一个数挪过来
            expa = strExp[i]; // 保存起来，在方法最后再恢复，以便继续计算
            expb = strExp[j]; // 保存起来，在方法最后再恢复，以便继续计算
            strExp[j] = strExp[n - 1]; // 将最后一个式子挪过来j'
            strExp[i] = "(" + expa + "+" + expb + ")"; // 看看加法能否算出,如果能算出，返回true
            number[i] = a + b;
            if (is24(n - 1))
                return true;
            strExp[i] = "(" + expa + "-" + expb + ")"; // 看看减法能否算
            number[i] = a - b;
            if (is24(n - 1))
                return true;
            strExp[i] = "(" + expb + "-" + expa + ")";
            number[i] = b - a;
            if (is24(n - 1))
                return true;
            strExp[i] = "(" + expa + "*" + expb + ")"; // 看看乘法能否算
            number[i] = a * b;
            if (is24(n - 1))
                return true;
            if (b != 0) {
                strExp[i] = "(" + expa + "/" + expb + ")"; // 看看除法能否算
                number[i] = a / b;
                if (is24(n - 1))
                    return true;
            }
            if (a != 0) {
                strExp[i] = "(" + expb + "/" + expa + ")";
                number[i] = b / a;
                if (is24(n - 1))
                    return true;
            }
            //如果以上的加、减、乘、除都不能得到有效的结果，则恢复数据进行下一轮的计算。
            number[i] = a; // 恢复
            number[j] = b;
            strExp[i] = expa;
            strExp[j] = expb;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    string strPocker[4];
    /* map<int, string> rPockMap = { */
    /*     {1 ,"A"   }, */
    /*     {2 ,"2"   }, */
    /*     {3 ,"3"   }, */
    /*     {4 ,"4"   }, */
    /*     {5 ,"5"   }, */
    /*     {6 ,"6"   }, */
    /*     {7 ,"7"   }, */
    /*     {8 ,"8"   }, */
    /*     {9 ,"9"   }, */
    /*     {10,"10"   }, */
    /*     {11,"J"    }, */
    /*     {12,"Q"    }, */
    /*     {13,"K"    }, */
    /* }; */
    map<string, int> pockMap = {
        { "A", 1 },
        { "2", 2 },
        { "3", 3 },
        { "4", 4 },
        { "5", 5 },
        { "6", 6 },
        { "7", 7 },
        { "8", 8 },
        { "9", 9 },
        { "10", 10 },
        { "J", 11 },
        { "Q", 12 },
        { "K", 13 },
    };
    for( int i=0; i<4; ++i ){
        ostringstream ostrs;
        cin>>strPocker[i];
        if( strPocker[i].compare( "joker" ) == 0 || strPocker[i].compare( "JOKER" ) == 0 ){
            cout<<"ERROR"<<endl;
            return 0;
        }
        number[i] = pockMap[strPocker[i]];
        ostrs << number[i];
        strExp[i] = ostrs.str();
    }
    bool bFlag = is24(4);
    if( bFlag ){
        /* cout<<strExp[0]<<endl; */
        for( auto i : strExp[0] ){
            if( i != '(' && i!= ')' ){
                cout<<i;
            }
        }
        cout<<endl;
    }
    else{
        cout<<"NONE"<<endl;
    }
    return 0;
}
