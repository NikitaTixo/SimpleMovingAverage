#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template <typename T>
std::vector<T> countSMA(std::vector<T> original, int window)
{
    std::vector<T> sma;
    T sum = 0;

    for (int i = 0; i < original.size(); i++)
    {
        sum += original[i];

        if (i >= window-1)
        {
            sma.push_back(sum / static_cast<T>(window));
            sum -= original[i - (window - 1)];
        }
    }
    return sma;
}

