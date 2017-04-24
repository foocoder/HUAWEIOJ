#include <iostream>
#include <cstdio>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

const string bigLetter[]={"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};


const string unitBig[]={"拾","佰","仟"};
const string unit[]={"万","亿","万亿"};
const string unitSmall[]={"分","角"};

string fourMaxBit(const string&);//四位或者四位以下的整数部分转换
string intToChi(const string&);//将整数部分转换成中文大写
string doubleToStr(const double&);//将输入的双精度类型转换成字符串型

int main()
{
    string money;
    double moneyDouble;
    string moneyChi("");
    cin>>moneyDouble;//输入阿拉伯数字
    money=doubleToStr(moneyDouble);//数字转换成字符串

    int len=money.size();
    int flag=1;
    for(int i=0;i<len;i++)
    {
        if('.'==money[i])
        {
            flag=0;
            break;
        }
    }

    if(1==flag)//输入钱数为整数
    {
        moneyChi+=intToChi(money)+"元整";
    }
    else//输入钱数是小数
    {
        string moneyBig;
        string moneySmall;
        int deltaBig,deltaSmall;

        //分别把整数和小数部分提取出来，不含小数点
        for(string::iterator it=money.begin();it!=money.end();it++)
        {
            if(*it=='.')
            {
                deltaBig=it-money.begin();//整数部分位数
                deltaSmall=len-deltaBig-1;//小数部分位数
                break;
            }
        }
        moneyBig=money.substr(0,deltaBig);
        moneySmall=money.substr(deltaBig+1,deltaSmall);

        //转化成中文
        if("0"==moneyBig)
        {
            if(1==deltaSmall && moneySmall[0]!='0')
            {
                moneyChi+=bigLetter[moneySmall[0]-48]+"角";
            }
            else if(2==deltaSmall && moneySmall[0]!='0' && moneySmall[1]!='0')
            {
                moneyChi+=bigLetter[moneySmall[0]-48]+"角"+bigLetter[moneySmall[1]-48]+"分";
            }
            else if(2==deltaSmall && moneySmall[0]!='0' && moneySmall[1]=='0')
            {
                moneyChi+=bigLetter[moneySmall[0]-48]+"角";
            }
            else if(2==deltaSmall && moneySmall[0]=='0' && moneySmall[1]=='0')
            {
                moneyChi+="零元整";
            }
            else if(1==deltaSmall && moneySmall[0]=='0')
            {
                moneyChi+="零元整";
            }
            else
            {
                moneyChi+=bigLetter[moneySmall[1]-48]+"分";
            }
        }
        else
        {
            moneyChi+=intToChi(moneyBig)+"元";
            if(1==deltaSmall)
            {
                moneyChi+=bigLetter[moneySmall[0]-48]+"角";
            }
            else if(2==deltaSmall && moneySmall[0]!='0' && moneySmall[1]!='0')
            {
                moneyChi+=bigLetter[moneySmall[0]-48]+"角"+bigLetter[moneySmall[1]-48]+"分";
            }
            else if(2==deltaSmall && moneySmall[0]!='0' && moneySmall[1]=='0')
            {
                moneyChi+=bigLetter[moneySmall[0]-48]+"角";
            }
            else if(2==deltaSmall && moneySmall[0]=='0' && moneySmall[1]=='0')
            {
                moneyChi+="整";
            }
            else if(1==deltaSmall && moneySmall[0]=='0')
            {
                moneyChi+="整";
            }
            else
            {
                moneyChi+=bigLetter[moneySmall[1]-48]+"分";
            }
        }
    }
    cout<<"人民币"<<moneyChi<<endl;

    return 0;
}

/*
 *函数功能：将双精度转换成字符串
 *输入参数：待转换数值
 *返回值：转换后的字符串
 */
string doubleToStr(const double& a)
{
    char c[100]={'\0'};
    sprintf(c,"%.2f",a);
    return c;
}

/*
 *函数功能：将四位或者四位以下的整数部分转成中文
 *输入参数：待转换的字符串
 *返回值：转换后的中文字符串
 */
string fourMaxBit(const string& str)
{
    string moneyChi;
    int len=str.size();
    int k=0,flag=0;
    if('1'==str[0] && 2==len)
    {
        moneyChi="拾"+(str[1]=='0'?"":bigLetter[str[1]-48]+"");
    }
    else if(4==len && "0000"==str)
    {
        //do nothing
    }
    else if(4==len && "0000"!=str)
    {
        //找到第一个不是零的数
        for(int i=0;i<4;i++)
        {
            if(str[i]!='0')
            {
                k=i;
                break;
            }
        }

        //转换成中文
        for(int i=k;i<4;i++)
        {
            if(str[i]!='0')
            {
                moneyChi+=bigLetter[str[i]-48]+((2-i<0)?"":unitBig[2-i]);
            }
            else
            {
                for(int j=i;j<4;j++)
                {
                    if(str[j]!='0')
                    {
                        i=--j;
                        flag=1;
                        break;
                    }
                }
                if(1==flag)
                {
                    moneyChi+="零";
                }
                flag=0;
            }
        }
    }
    else
    {
        //转换成中文
        for(int i=0;i<len;i++)
        {
            if(str[i]!='0')
            {
                moneyChi+=bigLetter[str[i]-48]+((len-i-2<0)?"":unitBig[len-i-2]);
            }
            else
            {
                for(int j=i;j<len;j++)
                {
                    if(str[j]!='0')
                    {
                        i=--j;
                        flag=1;
                        break;
                    }
                }
                if(1==flag)
                {
                    moneyChi+="零";
                }
                flag=0;
            }
        }
    }
    return moneyChi;
}

/*
 *函数功能：将整数转成中文
 *输入参数：待转换的字符串
 *返回值：转换后的中文字符串
 */
string intToChi(const string& str)
{
    vector<string> strArray;
    string moneyChi("");
    int len=str.size();
    int flag=0;

    //将字串按照大小4拆分装入容器strArray
    int remainder=len%4;
    if(remainder!=0 && len<4)
    {
        strArray.push_back(str.substr(0,remainder));
    }
    else if(remainder==0)
    {
        for(int i=0;i<=len-4;i+=4)
        {
            strArray.push_back(str.substr(i,4));
        }
    }
    else if(remainder!=0 && len>4)
    {
        strArray.push_back(str.substr(0,remainder));
        for(int i=remainder;i<=len-4;i+=4)
        {
            strArray.push_back(str.substr(i,4));
        }
    }

    int lenTemp=strArray.size();

    for(int i=0;i<lenTemp;i++)
    {
        if(strArray[i]=="0000")
        {
            if(i==lenTemp-1)
            {
                //do nothing
            }
            else
            {
                for(int j=i;j<=lenTemp-1;j++)
                {
                    if(strArray[j]!="0000")
                    {
                        i=--j;
                        flag=1;
                        break;
                    }
                }
                if(1==flag)
                {
                    moneyChi+="零";
                }
                flag=0;
            }
        }
        else
            moneyChi+=fourMaxBit(strArray[i])+((lenTemp-i-2<0)?"":unit[lenTemp-i-2]);
    }
    return moneyChi;
}
