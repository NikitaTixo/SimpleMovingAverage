#include <iostream>
#include <vector>

template <typename T>
std::vector<T> countSMA(std::vector<T> original, int window)
{
    std::vector<T> sma;
    for (int i = window-1; i < original.size(); i++)
    {
        T sum = 0;
        for (int j = i - window + 1; j <= i; j++)
        {
            sum += original[j];
        }

        sma.push_back(sum / window);
    }

    return sma;
}