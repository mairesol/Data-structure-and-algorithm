#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void permute(int n)
{
    vector<int> v(n);
    for (int j = 0; j < n; j++)
        v[j] = j + 1;

    int i, j, k;
    while (true)
    {
        for (j = 0; j < n; j++)
            cout << v[j] << " ";
        cout << endl;
        i = n - 2;
        while (i >= 0 && v[i] > v[i + 1])
            i--;
        if (i == -1)
            return;
        k = n - 1;
        while (v[k] < v[i])
            k--;
        swap(v[i], v[k]);
        reverse(v.begin() + i + 1, v.end());
    }
}

int main()
{
    int n;
    cin >> n;
    permute(n);
    return 0;
}