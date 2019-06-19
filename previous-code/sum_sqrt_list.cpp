#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;


int main()
{
    int num;
    vector<int> nums;
    while(cin >> num)
    {
        nums.push_back(num);
    }

    vector<float> sum_q;
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); ++it)
    {
        float sum = 0;
        float a1 = *it++;
        int m = *it;

        float temp = a1;
        for(int i = 0; i < m; ++i)
        {
            sum += temp;
            temp = sqrt(temp);
        }

        sum_q.push_back(sum);
    }

    vector<float>::iterator ft;
    cout.setf(ios::fixed);
    for(ft = sum_q.begin(); ft != sum_q.end(); ++ft)
    {
        cout << setprecision(2) << *ft << endl;
    }

    return 0;
}





