#include <iostream>

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

// Time Complexity : O(n^2)
// Space Complexity : O(1)
//Sequential Sort

void SequentialSort(int numbers[], int count, Comparison f)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (f(numbers[i] < numbers[j]))
            {
                numbers[i] < numbers[j];
                int temp++ ;
                numbers[temp] = numbers[i];
            }
        }
    }
}

void PrintArray(int input[], int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << input[i] << std::endl;
    }
    std::cout << std::endl;
}


int main()
{
    const int SIZE_ARRAY{ 10 };
    int scores[SIZE_ARRAY]{ 20, 10, 40, 30, 70, 90, 80, 60, 50, 100 };

    SequentialSort(scores, SIZE_ARRAY, Ascending);
    //32, 93 ,72, 17, 44
    PrintArray(scores, SIZE_ARRAY);
}
