#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;


bool HaveVirus(string str)
{
    if(str.length() >= 5)
    {
        for(int i = 0; i < str.length() - 4; ++i)
        {
            if(str[i] == 'v' &&
               str[i + 1] == 'i' &&
               str[i + 2] == 'r' &&
               str[i + 3] == 'u' &&
               str[i + 4] == 's')
            {
                return true;
            }
        }
    }

    return false;
}

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

        if(str.length() < 5)
        {
            cout << 0 << endl;
            return 0;
        }

        int virus_cnt = 0;
        for(int i = 0; i < str.length() - 4; ++i)
        {
            for(int j = i + 4; j < str.length(); ++j)
            {
                string ts = string(j - i + 1, 'a');
                for(int k = 0; k <= j - i; ++k)
                {
                    ts[k] = str[k + i];
                }
                if(HaveVirus(ts))
                {
                    virus_cnt += 1;
                }
            }
        }
        cout << virus_cnt << endl;
    }

    return 0;
}







