#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
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
        long long cnt = 0;
        long long value = 0;
        long a0 = 1000000000;
        long a1 = 999999999;

        value = str[0] - 48;
        for(int i = 1; i < len; ++i)
        {
            value *= 10 + str[i] - 48;
        }

        switch(len)
        {
        case 1:
            cnt = value;
            break;
        case 2:
            cnt = ((value - 10) + 1) * 2 + 9;
            break;
        case 3:
            cnt = ((value - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        case 4:
            cnt = ((value - 1000) + 1) * 4 + ((999 - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        case 5:
            cnt = ((value - 10000) + 1) * 5 + ((9999 - 1000) + 1) * 4 + ((999 - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        case 6:
            cnt = ((value - 100000) + 1) * 6 + ((99999 - 10000) + 1) * 5 + ((9999 - 1000) + 1) * 4 + ((999 - 100) + 1) * 3
                    + ((99 - 10) + 1) * 2 + 9;
            break;
        case 7:
            cnt = ((value - 1000000) + 1) * 7 + ((999999 - 100000) + 1) * 6 + ((99999 - 10000) + 1) * 5
                    + ((9999 - 1000) + 1) * 4 + ((999 - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        case 8:
            cnt = ((value - 10000000) + 1) * 8 + ((9999999 - 1000000) + 1) * 7 + ((999999 - 100000) + 1) * 6
                    + ((99999 - 10000) + 1) * 5 + ((9999 - 1000) + 1) * 4 + ((999 - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        case 9:
            cnt = ((value - 100000000) + 1) * 9 + ((99999999 - 10000000) + 1) * 8 + ((9999999 - 1000000) + 1) * 7
                    + ((999999 - 100000) + 1) * 6 + ((99999 - 10000) + 1) * 5 + ((9999 - 1000) + 1) * 4
                    + ((999 - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        case 10:

            cnt = ((value - a0) + 1) * 10 + ((a1 - 100000000) + 1) * 9 + ((99999999 - 10000000) + 1) * 8
                    + ((9999999 - 1000000) + 1) * 7 + ((999999 - 100000) + 1) * 6 + ((99999 - 10000) + 1) * 5
                    + ((9999 - 1000) + 1) * 4 + ((999 - 100) + 1) * 3 + ((99 - 10) + 1) * 2 + 9;
            break;
        default:
            break;
        }

        cout << cnt << endl;
    }

    return 0;
}





