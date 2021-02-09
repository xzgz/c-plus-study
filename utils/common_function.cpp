#include <vector>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

template<typename dtype>
void Print1DVector(const vector<dtype>& array) {
    for (dtype val : array) cout << val << '\t';
    cout << endl;
}

void PrintNowTime() {
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "second from year 1970: " << now << endl;

    // 输出 tm 结构的各个组成部分
    cout << "year: " << 1900 + ltm->tm_year << endl;
    cout << "month: "<< 1 + ltm->tm_mon<< endl;
    cout << "day: "<<  ltm->tm_mday << endl;
    cout << "hour: "<< ltm->tm_hour << endl;
    cout << "minute: " << ltm->tm_min << endl;
    cout << "second: " << ltm->tm_sec << endl;
}

template <typename dtype>
vector<dtype> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length) {
    vector<dtype> array(length);
    static default_random_engine e(seed);
    static uniform_int_distribution<dtype> u(min, max);
//    default_random_engine e(seed);
//    uniform_int_distribution<int> u(min, max);
    for (int i = 0; i < length; ++i) {
        array[i] = u(e);
    }
    return array;
}
template <typename dtype>
vector<dtype> GenerateRandom1DIntegerArray(int min, int max, int length) {
    vector<dtype> array(length);
    std::random_device rd;
    default_random_engine e(rd());
    uniform_int_distribution<dtype> u(min, max);
    for (int i = 0; i < length; ++i) {
        array[i] = u(e);
    }
    return array;
}

template <typename dtype>
vector<dtype> GenerateRandom1DRealArray(unsigned int seed, int min, int max, int length) {
    vector<dtype> array(length);
    static default_random_engine e(seed);
    static uniform_real_distribution<dtype> u(min, max);
    for (int i = 0; i < length; ++i) {
        array[i] = u(e);
    }
    return array;
}
template <typename dtype>
vector<dtype> GenerateRandom1DRealArray(int min, int max, int length) {
    vector<dtype> array(length);
    std::random_device rd;
    default_random_engine e(rd());
    uniform_real_distribution<dtype> u(min, max);
    for (int i = 0; i < length; ++i) {
        array[i] = u(e);
    }
    return array;
}


template void Print1DVector(const vector<int>& array);
template void Print1DVector(const vector<unsigned int>& array);
template void Print1DVector(const vector<long int>& array);
template void Print1DVector(const vector<unsigned long int>& array);
template void Print1DVector(const vector<long long int>& array);
template void Print1DVector(const vector<unsigned long long int>& array);
template void Print1DVector(const vector<float>& array);
template void Print1DVector(const vector<double>& array);

template vector<int> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template vector<unsigned int> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template vector<long int> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template vector<unsigned long int> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template vector<long long int> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template vector<unsigned long long int> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template vector<int> GenerateRandom1DIntegerArray(int min, int max, int length);
template vector<unsigned int> GenerateRandom1DIntegerArray(int min, int max, int length);
template vector<long int> GenerateRandom1DIntegerArray(int min, int max, int length);
template vector<unsigned long int> GenerateRandom1DIntegerArray(int min, int max, int length);
template vector<long long int> GenerateRandom1DIntegerArray(int min, int max, int length);
template vector<unsigned long long int> GenerateRandom1DIntegerArray(int min, int max, int length);

template vector<float> GenerateRandom1DRealArray(unsigned int seed, int min, int max, int length);
template vector<double> GenerateRandom1DRealArray(unsigned int seed, int min, int max, int length);
template vector<float> GenerateRandom1DRealArray(int min, int max, int length);
template vector<double> GenerateRandom1DRealArray(int min, int max, int length);
