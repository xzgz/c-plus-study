#ifndef C_PLUS_STUDY_INCLUDE_PRINT_VECTOR_H
#define C_PLUS_STUDY_INCLUDE_PRINT_VECTOR_H

#include <vector>

template<typename dtype>
void Print1DVector(const std::vector<dtype>& array);

void PrintNowTime();

template <typename dtype>
std::vector<dtype> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DIntegerArray(int min, int max, int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArray(unsigned int seed, int min, int max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArray(int min, int max, int length);

#endif // C_PLUS_STUDY_INCLUDE_PRINT_VECTOR_H
