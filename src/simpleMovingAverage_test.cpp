#include "simpleMovingAverage.h"

int main()
{
    std::vector<float> vectorFloat = {1.0, 2.0, 4.0, 7.0, 10.0, 14.0, 19.0, 25.0};
    int window = 3;

    std::vector<float> resultFloat = countSMA(vectorFloat, window);

    while(!resultFloat.empty())
    {
        std::cout << resultFloat.front() << " ";
        resultFloat.erase(resultFloat.begin());
    }

    std::cout << std::endl;

    // test double type 
    std::vector<double> vectorDouble = {1.0, 2.0, 4.0, 7.0, 10.0, 14.0, 19.0, 25.0};

    std::vector<double> resultDouble = countSMA(vectorDouble, window);

    while(!resultDouble.empty())
    {
        std::cout << resultDouble.front() << " ";
        resultDouble.erase(resultDouble.begin());
    }

    std::cout << std::endl;

    return 0;
}