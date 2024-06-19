#include "simpleMovingAverage.h"

const int inputVectorSize = 1000000;
const int minValue = 0;
const int maxValue = 1000;
const int numberOfTests = 10;

void generateInputVector(std::vector<float>& inputVector)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(minValue, maxValue);

    for (int i = 0; i < inputVectorSize; i++)
        inputVector.push_back(dis(gen));
}

void generateInputVector(std::vector<double>& inputVector)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(minValue, maxValue);

    for (int i = 0; i < inputVectorSize; i++)
        inputVector.push_back(dis(gen));
}

template <typename T>
bool testOutputData(std::vector<T>& inputVector, std::vector<T>& outputVector, int window)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, inputVectorSize - window - 1);

    for (int i = 0; i < numberOfTests; i++)
    {
        int position = dis(gen);
        T sum = 0;
        
        for (int j = 0; j < window; j++)
            sum += inputVector[position + j];

        if (sum / static_cast<T>(window) != outputVector[position])
            return false;
    }

    return true;
}

int main()
{

    std::cout << "--------Float Test--------" << std::endl;

    for (int window = 4; window <= 128; window *= 2)
    {
        std::vector<float> inputDataFloat;
        std::vector<float> outputDataFloat;

        generateInputVector(inputDataFloat);

        auto start = std::chrono::steady_clock::now();

        outputDataFloat = countSMA(inputDataFloat, window);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = end - start;
        
        std::cout << "  Window = " << window << ":" << std::endl;
        
        if (testOutputData(inputDataFloat, outputDataFloat, window))
        {
            std::cout << "      Pass!" << std::endl;
            std::cout << "      Time = " << elapsedSeconds.count() << " seconds" << std::endl;
        }
        else
            std::cout << "      Fail!" << std::endl;

        std::cout << std::endl;
    }
    
    std::cout << "--------Double Test--------" << std::endl;

    for (int window = 4; window <= 128; window *=2)
    {
        std::vector<double> inputDataDouble;
        std::vector<double> outputDataDouble;

        generateInputVector(inputDataDouble);

        auto start = std::chrono::steady_clock::now();

        outputDataDouble = countSMA(inputDataDouble, window);
        
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = end - start;
        
        std::cout << "  Window = " << window << ":" << std::endl;
        
        if (testOutputData(inputDataDouble, outputDataDouble, window))
        {
            std::cout << "      Pass!" << std::endl;
            std::cout << "      Time = " << elapsedSeconds.count() << " seconds" << std::endl;
        }
        else
            std::cout << "      Fail!" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}