#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);
        return binary_search(arr, mid + 1, right, x);
    }
    return -1;
}

int main()
{
    return 0;
}