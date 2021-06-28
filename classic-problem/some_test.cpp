//#include <bits/stdc++.h>
#include "include/utils.h"
#include "common_function.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <exception>

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

void MyFunction() {
    cout << "MyFunction\n";
}

void TestFunPtr() {
    cout << "TestFunPtr:" << endl;
    Ptf fun1 = &MyFunction;
    Ptf fun2 = MyFunction;
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

int addInt1(int a, int b) {
    int res = a + b;
    if(a > 0 && b > 0 && res < 0) throw overflow_error("addInt1 -- too big");
    if(a < 0 && b < 0 && res > 0) throw overflow_error("addInt1 -- too small");
    return res;
}
int addInt2(int a, int b) {
    if(a > 0 && b > 0 && a > numeric_limits<int>::max() - b) throw overflow_error("addInt2 -- too big");
    if(a < 0 && b < 0 && a < numeric_limits<int>::min() - b) throw overflow_error("addInt2 -- too small");
    return a + b;
}
int addInt3(int a, int b) {
    int x = a + b;
    if ((x ^ a) < 0 && (x ^ b) < 0) throw overflow_error("addInt3 -- too big or too small");
    return x;
}
void TestIntAddOverFlow() {
    cout << "TestIntAddOverFlow:" << endl;
    int a = -numeric_limits<int>::max();
    int b = -2;
    int c;
//    c = addInt1(a, b);
//    c = addInt2(a, b);
    c = addInt3(a, b);
    cout << "c = " << c << endl;
}

void TestFloatBigSubBig() {
    cout << "TestFloatBigSubBig:" << endl;

    float f1 = 2.34E+10f;
    float f2 = f1 + 10.0f;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f2 - f1 = " << f2 - f1 << endl;
}

void TestConstPtr() {
    cout << "TestConstPtr:" << endl;

    float f3 = 0.1;
    const float *pf = &f3;
    printf("%f\n", *pf);
    f3 = 0.2;
    printf("%f\n", *pf);
//    *pf = 0.3;  // error: assignment of read-only location *pf
    f3 = 0.3;
    printf("%f\n", *pf);

    float f4 = 1.2;
    pf = &f4;
    printf("%f\n", *pf);

    const float f5 = 1.3;
//    float *pf2 = &f5;  // invalid conversion from const float* to float* [-fpermissive]
}

int main() {
    TimerClock tc(true);
    TestFunPtr();
//    TestInputStringToArray();
//    TestGenerateRandomNumber();
//    TestSetprecision();
//    TestIntAddOverFlow();
//    TestFloatBigSubBig();
    TestConstPtr();

    return 0;
}
