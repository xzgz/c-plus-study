#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;


int match_loc(string phone_str, vector<string>& prefix_strs)
{
    int r = -1;
    bool match = false;
    for(int j = 0; j < prefix_strs.size(); j++)
    {
        for(int k = 0; k < phone_str.size(); k++)
        {
            if(phone_str[k] != prefix_strs[j][k])
            {
                break;
            }
            else if(k == prefix_strs[j].size() - 1)
            {
                match = true;
                r = j;
                break;
            }
        }

        if(match)
        {
            break;
        }
    }

    return r;
}

int main()
{
    string str;
    vector<string> phone_strs;
    vector<string> prefix_strs;
    vector<string> loc_strs;
    vector< vector<string> > phone_strs_vec;
    vector< vector<string> > prefix_strs_vec;
    vector< vector<string> > loc_strs_vec;
    vector<int> Ms;
    int T, N, M;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        phone_strs.clear();
        prefix_strs.clear();
        loc_strs.clear();

        cin >> N;
        for(int j = 0; j < N; j++)
        {
            cin >> str;
            string prefix = "";
            for(int k = 0; k < 11; k++)
            {
                if(str[k] != 'x')
                {
                    prefix += str[k];
                }
                else
                {
                    break;
                }
            }
            prefix_strs.push_back(prefix);

            cin >> str;
            loc_strs.push_back(str);
        }

        cin >> M;
        Ms.push_back(M);
        for(int j = 0; j < M; j++)
        {
            cin >> str;
            phone_strs.push_back(str);
        }
        phone_strs_vec.push_back(phone_strs);
        prefix_strs_vec.push_back(prefix_strs);
        loc_strs_vec.push_back(loc_strs);
    }

    for(int i = 0; i < T; i++)
    {
//        phone_strs.clear();
//        prefix_strs.clear();
//        loc_strs.clear();
        phone_strs = phone_strs_vec[i];
        prefix_strs = prefix_strs_vec[i];
        loc_strs = loc_strs_vec[i];
        int M = Ms[i];

//        for(int i = 0; i < prefix_strs.size(); i++)
//        {
//            cout << prefix_strs[i] << endl;
//        }
//        for(int i = 0; i < loc_strs.size(); i++)
//        {
//            cout << loc_strs[i] << endl;
//        }
//        for(int i = 0; i < phone_strs.size(); i++)
//        {
//            cout << phone_strs[i] << endl;
//        }

        for(int p = 0; p < M; p++)
        {
            int r;
            r = match_loc(phone_strs[p], prefix_strs);
            if(r == -1)
            {
                cout << "unknown" << endl;
            }
            else
            {
                cout << loc_strs[r] << endl;
            }
        }
    }
}


