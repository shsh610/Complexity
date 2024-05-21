#include <iostream>
#include <chrono>

//Big O Notation
// 1. 곱하기 - 변수를 제외한 상수는 무시
//              4 * n * n = n * n
// 2. 더하기 - 더 높은 차수만 사용
//             n + 6 = n^1 + 6 * n^0 = n
// 3. 조건 - worst case

//n개의 데이터를 처리할 때 A 알고리즘과 B 알고리즘을 비교

using Comparison = bool(*)(int, int);

bool Ascending(int x, int y)
{
    return x > y;
}

bool Descending(int x, int y)
{
    return x < y;
}

// Time Complexity : 
// Space Complexity : 

void Sort(int numbers[], int count, Comparison f)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (f(numbers[i], numbers[j]))
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main()
{
    const int SIZE_ARRAY{ 10 };
    int scores[SIZE_ARRAY]{ 20, 10, 40, 30, 70, 90, 80, 60, 50, 100 };

    auto startTime = std::chrono::system_clock::now();
    Sort(scores, SIZE_ARRAY, Ascending);
    auto endTime = std::chrono::system_clock::now();

    auto duration = endTime - startTime;
    std::cout << "Sort() - " << duration.count() << "ms" << std::endl;

    for (int i = 0; i < SIZE_ARRAY; i++)
    {
        std::cout << scores[i] << std::endl;
    }
    //32, 93 ,72, 17, 44
}
