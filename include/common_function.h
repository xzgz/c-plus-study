#ifndef C_PLUS_STUDY_INCLUDE_PRINT_VECTOR_H
#define C_PLUS_STUDY_INCLUDE_PRINT_VECTOR_H

#include <vector>
#include <chrono>

template<typename dtype>
void Print1DVector(const std::vector<dtype>& array);

void PrintNowTime();

class TimerClock {
public:
    TimerClock(bool use_destruct_print_time);

    ~TimerClock();

    void update();

    double get_second();
    double get_milli_second();
    long int get_micro_second();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
    bool use_destruct_print_time_;
};

template <typename dtype>
std::vector<dtype> GenerateRandom1DIntegerArray(unsigned int seed, int min, int max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DIntegerArray(int min, int max, int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArray(unsigned int seed, int min, int max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArray(int min, int max, int length);


std::vector<int> GenerateRandom1DIntegerArrayUseRandSideOpen(unsigned int seed, int min, int max, int length);
std::vector<int> GenerateRandom1DIntegerArrayUseRandSideOpen(int min, int max, int length);

std::vector<int> GenerateRandom1DIntegerArrayUseRandSideClose(unsigned int seed, int min, int max, int length);
std::vector<int> GenerateRandom1DIntegerArrayUseRandSideClose(int min, int max, int length);

std::vector<int> GenerateRandom1DIntegerArrayUseRandLeftClose(unsigned int seed, int min, int max, int length);
std::vector<int> GenerateRandom1DIntegerArrayUseRandLeftClose(int min, int max, int length);

std::vector<int> GenerateRandom1DIntegerArrayUseRandRightClose(unsigned int seed, int min, int max, int length);
std::vector<int> GenerateRandom1DIntegerArrayUseRandRightClose(int min, int max, int length);


template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandSideOpen(unsigned int seed, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandSideOpen(int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandSideClose(unsigned int seed, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandSideClose(int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandLeftClose(unsigned int seed, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandLeftClose(int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandRightClose(unsigned int seed, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealZeroOneArrayUseRandRightClose(int length);


template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandSideOpen(unsigned int seed, dtype min, dtype max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandSideOpen(dtype min, dtype max, int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandSideClose(unsigned int seed, dtype min, dtype max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandSideClose(dtype min, dtype max, int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandLeftClose(unsigned int seed, dtype min, dtype max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandLeftClose(dtype min, dtype max, int length);

template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandRightClose(unsigned int seed, dtype min, dtype max, int length);
template <typename dtype>
std::vector<dtype> GenerateRandom1DRealArrayUseRandRightClose(dtype min, dtype max, int length);

void SleepCrossPlatform(unsigned int millisecond);
void SleepCrossPlatformUseSTL(unsigned int millisecond);

#endif // C_PLUS_STUDY_INCLUDE_PRINT_VECTOR_H
