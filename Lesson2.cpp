﻿#include <iostream>

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

void Merge(int numbers[], int start,int half, int end, int temp[])
{
    int i = start;
    int j = half + 1;
    int tempIndex{};

    while (i <= half && j <= end)
    {
        if (numbers[i] < numbers[j])
        {
            temp[tempIndex] = numbers[i++];
        }
        else
        {
            temp[tempIndex++] = numbers[j++];
        }
    }

    while (i <= half)
    {
        temp[tempIndex++] = numbers[i++];
    }

    while (j <= end)
    {
        temp[tempIndex++] = numbers[j++];
    }

    tempIndex = 0;
    for (int i = start; i <= end; ++i)
    {
        numbers[i] = temp[tempIndex++];
    }
}

void MergeSort(int numbers[], int start, int end, int temp[])
{
    if (start == end)
    {
        return;
    }

    int half = (start + end) / 2;

    MergeSort(numbers, start, half, temp);
    MergeSort(numbers, half + 1, end,temp);

    Merge(numbers, start, half, end, temp);
    int i = start;
    int j = half + 1;
    int tempIndex{};

    while (i <= half && j <= end)
    {
        if (numbers[i] < numbers[j])
        {
            temp[tempIndex] = numbers[i++];
        } else
        {
            temp[tempIndex++] = numbers[j++];
        }
    }

    while (i <= half)
    {
        temp[tempIndex++] = numbers[i++];
    }

    while (j <= end)
    {
        temp[tempIndex++] = numbers[j++];
    }

    tempIndex = 0;
    for (int i = start; i <= end; ++i)
    {
        numbers[i] = temp[tempIndex++];
    }
}

void QuickSort(int numbers[], int start, int end)
{
    int i = start;
    int j = end;
    int pivot = numbers[(start + end) / 2];

    do
    {
        while (numbers[i] < pivot)
        {
            i++;
        }
        while (numbers[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (start < j)
    {
        QuickSort(numbers, start, j);
    }
    if (i < end)
    {
        QuickSort(numbers, i, end);
    }


}

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

void SelectionSort(int number[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int minIndex = i;
        for (int j = i; j < count; j++)
        {
            if (numbers[minIndex] > numbers[j])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = numbers[minIndex];
            numbers
        }
    }
}

void BubbleSort(int numbers[], int count)
{
    for (int phase = 0; phase < count - 1; ++phase)
    {
        for (int k = 0; k < count - 1 - phase; ++k)
        {
            if (numbers[k] > numbers[k + 1])
            {
                int temp = numbers[k];
                numbers[k] = numbers[k + 1];
                numbers[k + 1] = temp;
            }
        }
    }
}

void InsertionSort(int numbers[], int count)
{
    for (int i = 1; i < count; i++)
    {
        int j = i;
        int target = numbers[i];

        while (--j >= 0 && target < numbers[j])
        {
            numbers[j + 1] = numbers[j];
            numbers[j] = target;
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

    //SequentialSort(scores, SIZE_ARRAY, Ascending);
    SelectionSort(scores, SIZE_ARRAY);
    PrintArray(scores, SIZE_ARRAY);
}
