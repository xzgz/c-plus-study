#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> strs;
    string str;
    for(int i = 0; i < n; ++i)
    {
        cin >> str;
        strs.push_back(str);
    }

    vector<string>::iterator it;
    for(it = strs.begin(); it != strs.end(); ++it)
    {
        str = *it;
        int len = str.length();
        long value = str[0] - 48;
        long cnt = 0;

        for(int i = 0; i < len; i++)
        {
            if(i == len - 1)
            {
                cnt += ((value - pow(10, i)) + 1) * (i + 1);
                break;
            }
            else
            {
                cnt += (pow(10, i + 1) - pow(10, i)) * (i + 1);
            }
            value *= 10 + str[i + 1] - 48;
        }

        cout << cnt << endl;
    }

    return 0;
}



