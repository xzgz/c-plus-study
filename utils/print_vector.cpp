#include <vector>
#include <iostream>

using namespace std;

template<typename dtype>
void Print1DVector(const vector<dtype>& array) {
    for (dtype val : array) cout << val << '\t';
    cout << endl;
}

template void Print1DVector(const vector<int>& array);
template void Print1DVector(const vector<unsigned int>& array);
template void Print1DVector(const vector<long int>& array);
template void Print1DVector(const vector<unsigned long int>& array);
template void Print1DVector(const vector<long long int>& array);
template void Print1DVector(const vector<unsigned long long int>& array);
