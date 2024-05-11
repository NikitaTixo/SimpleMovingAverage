#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <omp.h>

template <typename T>
std::vector<T> countSMA(std::vector<T> original, int window)
{
    std::vector<T> sma;
    sma.resize(original.size() - window);

    #pragma omp parallel for num_threads(32)
    for (int i = window-1; i < original.size(); i++)
    {
        T sum = 0;
        
        for (int j = i - window + 1; j <= i; j++)
            sum += original[j];

        sma[i-window+1] = sum / static_cast<T>(window);
    }

    return sma;
}