#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<typeinfo>

using namespace std;

double round_fc(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

void test_float2integer()
{
    cout << "floor(0.5) << floor(0.2) << floor(0.8) << floor(1.1) << floor(1.6) << floor(2.0)" << endl;
    cout << floor(0.5) << floor(0.2) << floor(0.8) << floor(1.1) << floor(1.6) << floor(2.0) << endl;
    cout << "floor(-0.5) << floor(-0.2) << floor(-0.8) << floor(-1.1) << floor(-1.6) << floor(-2.0)" << endl;
    cout << floor(-0.5) << floor(-0.2) << floor(-0.8) << floor(-1.1) << floor(-1.6) << floor(-2.0) << endl;

    cout << "ceil(0.5) << ceil(0.2) << ceil(0.8) << ceil(1.1) << ceil(1.6) << ceil(2.0)" << endl;
    cout << ceil(0.5) << ceil(0.2) << ceil(0.8) << ceil(1.1) << ceil(1.6) << ceil(2.0) << endl;
    cout << "ceil(-0.5) << ceil(-0.2) << ceil(-0.8) << ceil(-1.1) << ceil(-1.6) << ceil(-2.0)" << endl;
    cout << ceil(-0.5) << ceil(-0.2) << ceil(-0.8) << ceil(-1.1) << ceil(-1.6) << ceil(-2.0) << endl;

    cout << "round_fc(0.5) << round_fc(0.2) << round_fc(0.8) << round_fc(1.1) << round_fc(1.6) << round_fc(2.0)" << endl;
    cout << round_fc(0.5) << round_fc(0.2) << round_fc(0.8) << round_fc(1.1) << round_fc(1.6) << round_fc(2.0) << endl;
    cout << "round_fc(-0.5) << round_fc(-0.2) << round_fc(-0.8) << round_fc(-1.1) << round_fc(-1.6) << round_fc(-2.0)" << endl;
    cout << round_fc(-0.5) << round_fc(-0.2) << round_fc(-0.8) << round_fc(-1.1) << round_fc(-1.6) << round_fc(-2.0) << endl;

    cout << "round(0.5) << round(0.2) << round(0.8) << round(1.1) << round(1.6) << round(2.0)" << endl;
    cout << round(0.5) << round(0.2) << round(0.8) << round(1.1) << round(1.6) << round(2.0) << endl;
    cout << "round(-0.5) << round(-0.2) << round(-0.8) << round(-1.1) << round(-1.6) << round(-2.0)" << endl;
    cout << round(-0.5) << round(-0.2) << round(-0.8) << round(-1.1) << round(-1.6) << round(-2.0) << endl;
}

void test_about_string()
{
    char *a = "kj";
    char *b = "qwe";
    b += 'q';
//    b += "a";
    const char *c = "poii";
    c += 'a';
//    c += "a";
    char d = 'asd}';
//    char *d = 'asd}';
    string e = "sddff";
//    string e = 'sddff';

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    e += "asd";
    cout << e << endl;
    e += 'gpo';
    cout << e << endl;
}

extern "C" {

void test_c_type() {
    char cr = 'qweeK';
    char *s = "abaabcac";
//    typeof(s) tfs = "asd";
    int it;
    int ita[6];
    float ft;
    double de;
    int *pit;
    int *pita[6];
    float *pft;
    double *pde;
    printf("cr: %c\n", cr);
    printf("s: %s\n", s);
//    printf("tfs: %s\n", tfs);
    cout << "typeid:" << endl;
    cout << typeid(cr).name() << endl;
    cout << typeid(s).name() << endl;
//    cout << typeid(tfs).name() << endl;
    cout << typeid(it).name() << endl;
    cout << typeid(ita).name() << endl;
    cout << typeid(ft).name() << endl;
    cout << typeid(de).name() << endl;
    cout << typeid(pit).name() << endl;
    cout << typeid(pita).name() << endl;
    cout << typeid(pft).name() << endl;
    cout << typeid(pde).name() << endl;
//    printf("%d\n", typeid(s) == typeid(tfs));
    printf("%d\n", typeid(s) == typeid(ft));
//    cout << (typeid(s) == typeid(tfs)) << endl;
    cout << (typeid(s) == typeid(cr)) << endl;

    if (typeid(s) == typeid(ft))
        cout << "l1" << endl;
    cout << "l2" << endl;
    cout << "l3" << endl;

    cout << "***************" << endl;
//    if (typeid(s) == typeid(tfs))
//        cout << "l1" << endl;
    cout << "l2" << endl;
    cout << "l3" << endl;

    cout << "***************" << endl;
    if (typeid(s) == typeid(ft))
        cout << "l1" << endl;
    cout << "l2" << endl;
    cout << "l3" << endl;

    cout << "***************" << endl;
//    if (typeid(s) == typeid(tfs))
//        cout << "l1" << endl;
    cout << "l2" << endl;
    cout << "l3" << endl;
}

}

void GetNext(char* p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

//int compute_shui(int salary)
//{
//    int shui;
//    int sa_exp = salary - 5000;

//    switch(sa_exp)
//    {
//    case sa_exp <= 0:
//        shui = 0;
//        break;
//    case (sa_exp > 0) && (sa_exp <= 3000):
//        shui = 0;
//        break;
//    }

//    return shui;
//}

int main()
{
//    int num;
//    vector<int> nums;
//    while(cin >> num)
//    {
//        nums.push_back(num);
//    }

//    int test_point_cnt = nums[0];
//    for(int i = 0; i < test_point_cnt; i++)
//    {
//        cout << nums[i+1] << endl;
//    }

//    test_float2integer();
//    test_about_string();
    test_c_type();


//    GetNext(s, next);
//    for(int i = 0; i < strlen(s); i++)
//    {
////        cout << next[i] << endl;
//        printf("%d\n", next[i]);
//    }
//    char *s = "KJHHHpooo";
//    cout << int(s[-1]) << endl;
//    cout << s[-1] << endl;

    return 0;
}



