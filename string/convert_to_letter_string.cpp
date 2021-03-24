#include "common_function.h"
#include <iostream>

using namespace std;

/*
 * 从左往右尝试的模型
 * 规定1和A对应、2和B对应、3和C对应...那么一个字符串"111"就可以转化为："AAA"、"KA"和"AK"。
 * 给定一个只由数字字符组成的字符串str，返回有多少种转化结果。
 */
int process(const string& str, int i) {
    if (i == str.length()) return 1;
    if (str[i] == '0') return 0;
    if (str[i] == '1') {
        int res = process(str, i + 1);
        if (i + 1 < str.length()) {
            res += process(str, i + 2);
        }
        return res;
    }
    if (str[i] == '2') {
        int res = process(str, i + 1);
        if (i + 1 < str.length() && str[i + 1] >= '0' && str[i + 1] <= '6') {
            res += process(str, i + 2);
        }
        return res;
    }
    // str[i] = '3' ~ '9'
    return process(str, i + 1);
}

int main() {
    string str = "1235121";
    int kinds = process(str, 0);
    cout << "transformation kinds: " << kinds << endl;
}
