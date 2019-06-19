#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;


int main()
{
    string str;
    vector<string> strs;
    while(cin >> str)
    {
        strs.push_back(str);
    }

    vector<string>::iterator it;
    for(it = strs.begin(); it != strs.end(); ++it)
    {
        str = *it;
        int upcase_cnt = 0;
        bool fg[100];
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[i] >=65 && str[i] <= 90)
            {
                fg[i] = false;
                upcase_cnt++;
            }
            else
            {
                fg[i] = true;
            }
        }

        if(upcase_cnt > str.length()/2)
        {
            for(int i = 0; i < str.length(); ++i)
            {
                if(fg[i])
                {
                    str[i] -= 32;
                }
            }
        }
        else
        {
            for(int i = 0; i < str.length(); ++i)
            {
                if(!fg[i])
                {
                    str[i] += 32;
                }
            }
        }

        cout << str << endl;
    }

    return 0;
}







