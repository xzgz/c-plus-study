#include "print_vector.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

vector<int> GenerateRandom1DIntArray(unsigned int seed, int min, int max, int length) {
    vector<int> array(length);
    static default_random_engine e(seed);
    static uniform_int_distribution<int> u(min, max);
//    default_random_engine e(seed);
//    uniform_int_distribution<int> u(min, max);
    for (int i = 0; i < length; ++i) {
        array[i] = u(e);
    }
    return array;
}

vector<int> GenerateRandom1DIntArray(int min, int max, int length) {
    vector<int> array(length);
    std::random_device rd;
//    static default_random_engine e(rd());
//    static uniform_int_distribution<int> u(min, max);
    default_random_engine e(rd());
    uniform_int_distribution<int> u(min, max);
    for (int i = 0; i < length; ++i) {
        array[i] = u(e);
    }
    return array;
}

/*
 * 计算一个非负整数N的阶乘。
 */
unsigned long long int Factorial(int N) {
    if (N < 0) return 0;

    unsigned long long int result = 1;
    for (int i = 2; i <= N; ++i) {
        result *= i;
    }
    return result;
}

/*
 * 计算 0! + 1! + 2! + 3! + ... + N!。
 */
unsigned long long int AccumulateFactorial1(int N) {
    if (N < 0) return 0;

    unsigned long long int result = 0;
    for (int i = 0; i <= N; ++i) {
        result += Factorial(i);
    }
    return result;
}

unsigned long long int AccumulateFactorial2(int N) {
    if (N < 0) return 0;

    unsigned long long int result = 1;
    unsigned long long int temp = 1;
    for (int i = 1; i <= N; ++i) {
        temp *= i;
        result += temp;
    }
    return result;
}

int main() {
    int N = 21;
    unsigned long long result = 0;
    time_point<high_resolution_clock> start = high_resolution_clock::now();

    result = AccumulateFactorial2(N);

    time_point<high_resolution_clock> end = high_resolution_clock::now();
    long int duration = duration_cast<microseconds>(end - start).count();
    double ms = double(duration) / 1000;
    cout << "result=" << result << endl
         << "used " << ms << " ms" << endl;

    vector<int> array;
    std::random_device rd;
    unsigned int seed = rd();
//    array = GenerateRandom1DIntArray(seed, 1, 21, 20);
    array = GenerateRandom1DIntArray(1, 21, 20);
    Print1DVector<int>(array);
//    array = GenerateRandom1DIntArray(seed, 1, 21, 20);
    array = GenerateRandom1DIntArray(1, 21, 20);
    Print1DVector<int>(array);
//    vector<int> array(20);
//    default_random_engine e;
//    uniform_int_distribution<int> u(1, 21);
//    for (int i = 0; i < 20; ++i) {
//        array[i] = u(e);
//    }
}
