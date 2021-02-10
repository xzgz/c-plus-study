//#include <bits/stdc++.h>
#include "include/utils.h"
#include "common_function.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    int n=prices.size();
    vector<int> f(n);
    vector<int> b(n);
    int min_price=prices[0];
    for(int i=1;i<n;i++){
        f[i]=max(f[i-1],prices[i]-min_price);
        min_price=min(prices[i],min_price);
    }
    int max_price=prices[n-1];
    for(int i=n-2;i>=0;i--){
        b[i]=max(b[i+1],max_price-prices[i]);
        max_price=max(max_price,prices[i]);
    }
    int res=0;
    for(int i=0;i<n-1;i++){
        res=max(res,max(f[i]+b[i+1],f[i]));
    }
    res=max(res,f[n-1]);
    return res;
}

typedef void (*Ptf)();

void print() {
    cout << "print\n";
}

void TestFunPtr() {
    Ptf fun1 = &print;
    Ptf fun2 = print;
    fun1();
    fun2();
}

void TestInputStringToArray() {
    string str;
    getline(cin, str);

    vector<int> arr;
    String2IntArray(arr, str);
    for (int n : arr) cout << n << " ";
    cout << endl;

    arr.clear();
    String2IntArray2(arr, str);
    for (int n : arr) cout << n << " ";
    cout << endl;
}

void TestGenerateRandomNumber() {
    cout << "RAND_MAX: " << RAND_MAX << endl;
    unsigned int seed = time(nullptr);

    vector<int> test_array;
    test_array = GenerateRandom1DIntegerArrayUseRandSideClose(3, 15, 20);
    Print1DVector(test_array);
    SleepCrossPlatform(2000);
//    SleepCrossPlatformUseSTL(2000);
    test_array = GenerateRandom1DIntegerArrayUseRandSideClose(3, 15, 20);
    Print1DVector(test_array);

    int length = 10000000;
    int number_kind = 27;
    int base_number = 22;
    vector<int> count_array(number_kind + 1);
    vector<int> arr;
//    arr = GenerateRandom1DIntegerArrayUseRandSideClose(base_number, base_number + number_kind, length);
    arr = GenerateRandom1DIntegerArrayUseRandSideOpen(base_number, base_number + number_kind, length);
//    arr = GenerateRandom1DIntegerArrayUseRandLeftClose(base_number, base_number + number_kind, length);
//    arr = GenerateRandom1DIntegerArrayUseRandRightClose(base_number, base_number + number_kind, length);
//    arr = GenerateRandom1DIntegerArray<int>(base_number, base_number + number_kind, length);

    for (int val : count_array) {
        cout << val << '\t';
    }
    cout << endl;
    cout << "length/number_kind: " << length / number_kind << endl;
    cout << "length/(number_kind + 1): " << length / (number_kind + 1) << endl;
    cout << "length/(number_kind - 1): " << length / (number_kind - 1) << endl;

    for (int val : arr) {
        count_array[val - base_number]++;
    }
    for (int val : count_array) {
        cout << val << '\t';
    }
    cout << endl;
}

void TestSetprecision() {
    float a, b, c;
    int g, h;
    a = 3.1;
    b = 2.9;
    c = 5.02;
    g = -3.9;
    h = 6;
    cout << a << '\t' << fixed << setprecision(8) << b << '\t' << c
         << '\t' << g << '\t' << h << endl;
    cout << 0 % 3 << endl;
    cout << 2 % 3 << endl;
    cout << 5 % 3 << endl;
    cout << 333333337 * 3 % 1000000007 << endl;
}

int main() {
    TimerClock tc(true);
//    TestFunPtr();
//    TestInputStringToArray();
//    TestGenerateRandomNumber();
    TestSetprecision();

    return 0;
}
