#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
string str;
void display(int index);
int main()
{
    vector< pair<string,string> > vec;
    vec.push_back(pair<string,string>("reset","board"));
    vec.push_back(pair<string,string>("board","add"));
    vec.push_back(pair<string,string>("board","delet"));
    vec.push_back(pair<string,string>("reboot","backplane"));
    vec.push_back(pair<string,string>("backplane","abort"));
    string singlecom = "reset";
    while (getline(cin,str))
    {
        if (str.length()==0)
        {
            continue;
        }

        int spacecount = 0;
        int spacepos = str.length();
        for (int i=0; i<str.length(); ++i)
            if(str[i] == ' ')
            {
                spacecount++;
                spacepos = i;
            }
        if (spacecount>1 || spacepos == 0)
        {
            cout<<"unkown command"<<endl;
            continue;
        }
        if (spacecount == 0)   //一个单词的命令
        {
            string com = str;
            if(singlecom.find(com) == 0)
                cout<<"reset what"<<endl;
            else
                cout<<"unkown command"<<endl;
        }
        else   //两个单词的命令
        {
            string com = str;
            string com1 = com.substr(0,spacepos);
            string com2 = com.substr(spacepos+1);
            int cnt = 0;
            int index;
            for (int k=0; k<vec.size(); k++)
            {
                if(vec[k].first.find(com1) == 0)
                    if(vec[k].second.find(com2) == 0)
                    {
                        cnt++;
                        index = k;
                    }
            }
            if (cnt == 1)
                display(index);
            else
                cout<<"unkown command"<<endl;
        }
    }
    return 0;
}

void display(int index)
{
    if (index == 0)
        cout<<"board fault"<<endl;
    if (index == 1)
        cout<<"where to add"<<endl;
    if (index == 2)
        cout<<"no board at all"<<endl;
    if (index == 3)
        cout<<"impossible"<<endl;
    if (index == 4)
        cout<<"install first"<<endl;
}
