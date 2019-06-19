#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;


int acc_apple(vector<int> aiv, vector<int>& acc_vec, int sum_pre, int start, int stop)
{
    for(int i = start; i <= stop; i++)
    {
        sum_pre += aiv[i];
        acc_vec.push_back(sum_pre);
    }

    return sum_pre;
}


int main()
{
    int n, ai, m, qi;
    vector<int> aiv;
    vector<int> qiv;
    vector<int> loc;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> ai;
        aiv.push_back(ai);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> qi;
        qiv.push_back(qi);
    }

//    for(int j = 0; j < m; j++)
//    {
//        int sum = 0;
//        for(int k = 0; k < n; k++)
//        {
//            sum += aiv[k];
//            if(sum >= qiv[j])
//            {
//                loc.push_back(k + 1);
//                break;
//            }
//        }
//    }

    int loc_max = 0;
    vector<int> acc_vec;
    for(int j = 0; j < m; j++)
    {
        int sum_pre = 0;
        int l = 0, r = n - 1;
        int mid = (l + r)/2;
        if(aiv[0] >= qiv[j])
        {
            loc.push_back(l + 1);
            continue;
        }
        else
        {
            if(loc_max == 0)
            {
                sum_pre = acc_apple(aiv, acc_vec, sum_pre, 0, mid);
                loc_max = mid;
            }
        }

        while(true)
        {
            if(mid > loc_max)
            {
                loc_max = mid;
                sum_pre = acc_apple(aiv, acc_vec, sum_pre, l + 1, mid);
            }

            if(acc_vec[mid] > qiv[j])
            {
                l = l;
                r = mid;
            }
            else
            {
                l = mid;
                r = r;
            }
            if(r - l <= 1)
            {
                if(acc_vec[l] >= qiv[j])
                {
                    loc.push_back(l + 1);
                }
                else
                {
                    loc.push_back(r + 1);
                }
                break;
            }
            mid = (l + r)/2;
        }
    }


    for(int j = 0; j < m; j++)
    {
        cout << loc[j] << endl;
    }


//    for(int i = 0; i < aiv.size(); i++)
//    {
//        cout << aiv[i];
//    }
//    cout << endl;
//    for(int i = 0; i < qiv.size(); i++)
//    {
//        cout << qiv[i] << endl;
//    }
}



