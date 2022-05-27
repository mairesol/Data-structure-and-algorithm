#include <algorithm>
#include <iostream>

using namespace std;

void quick_sort(int arr[], int left, int right) // Chon phan tu giua lam truc
{
    if (left < right)
    {
        int i, j, pivot;
        pivot = arr[(left + right) / 2];
        i = left;
        j = right;
        while (i < j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quick_sort(arr, left, j);
        if (i < right)
            quick_sort(arr, i, right);
    }
}

int main()
{
    return 0;
}