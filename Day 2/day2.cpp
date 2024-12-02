#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool IsSafe(const std::vector<int>& numbersVector, const int tolerance = 0);
bool IsIncreaseConsistent(const std::vector<int>& numbersVector);
bool IsDifferenceConsistent(const std::vector<int>& numbersVector);


int main()
{
    int nbOfSafeLines{};
    int nbOfTolerantSafeLines{};
    if(std::ifstream numbersStream{"input.in"})
    {
        std::string tempString{};
        while(std::getline(numbersStream, tempString))
        {
            std::istringstream tempStream{ tempString };
            std::string tempNumberString{};
            std::vector<int> numbers{};
            while(std::getline(tempStream, tempNumberString, ' '))
            {
                numbers.push_back(std::stoi(tempNumberString));
            }

            //evaluate the number string
            if(IsSafe(numbers))
            {
                ++nbOfSafeLines;
            }

            if(IsSafe(numbers, 1))
            {
                ++nbOfTolerantSafeLines;
            }
        }
    }
    std::cout << "Number of Safe lines : " << nbOfSafeLines << std::endl;
    std::cout << "Number of tolerant Safe lines : " << nbOfTolerantSafeLines << std::endl;




    return 0;
}

bool IsSafe(const std::vector<int>& numbersVector, const int tolerance)
{
    if(tolerance == 0)
    {
        return IsIncreaseConsistent(numbersVector) && IsDifferenceConsistent(numbersVector);
    }

    for(int i{0}; i < numbersVector.size(); ++i)
    {
        std::vector<int> tempVector{ numbersVector };
        tempVector.erase(tempVector.begin() + i);

        if(IsSafe(tempVector, tolerance - 1))
        {
            return true;
        }
    }

    return false;

}

bool IsIncreaseConsistent(const std::vector<int>& numbersVector)
{
    bool isIncreasing{ numbersVector[0] > numbersVector[1] };
    for (int i{ 1 }; i < numbersVector.size() - 1; ++i)
    {
        if ((numbersVector[i] > numbersVector[i + 1]) != isIncreasing)
        {
            return false;
        }
    }
    return true;
}

bool IsDifferenceConsistent(const std::vector<int>& numbersVector)
{
    for (int i{ 0 }; i < numbersVector.size() - 1; ++i)
    {
        int absoluteDifference{ std::abs(numbersVector[i] - numbersVector[i + 1]) };
        if (absoluteDifference < 1 || absoluteDifference > 3)
        {
            return false;
        }
    }

    return true;
}
