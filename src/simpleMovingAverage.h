#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <omp.h>

template <typename T>
inline std::vector<T> countSMA(std::vector<T> original, int window)
{
    std::vector<T> sma(original.size() - window);

    #pragma omp parallel for num_threads(16)
    for (int i = 0; i < original.size() - window; i++)
    {
        T sum = 0;

        for (int j = i; j < i + window; j++)
            sum += original[j];

        sma[i] = sum / static_cast<T>(window);
    }

    return sma;
}

