#include<iomanip>
#include<iostream>
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
    
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); ++it)
    {
        int m = *it++;
        int n = *it;
        bool flag = false;
        
        for(int i = m; i <= n; ++i)
        {
             int v100 = i/100;
             int v10 = (i - 100 * v100)/10;
        	 int v1 = i - 100 * v100 - 10 * v10;
             
             if(pow(v100, 3) + pow(v10, 3) + pow(v1, 3) == i)
             {
                 cout << i << " ";
                 flag = true;
             }
        }
        
        if(flag)
        {
            cout << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    
    return 0;
}



