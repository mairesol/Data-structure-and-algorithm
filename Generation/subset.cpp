#include <iostream>
#include <vector>

using namespace std;

void subset(int n, int k)
{
    vector<int> v(k);
    for (int j = 0; j < k; j++)
        v[j] = j + 1;

    int i;
    while (true)
    {
        for (int j = 0; j < k; j++)
            cout << v[j] << " ";
        cout << endl;

        i = k - 1;
        while (i >= 0 && v[i] == n - k + i + 1)
            --i;
        if (i == -1)
            return;
        v[i]++;
        for (int j = i + 1; j < k; j++)
            v[j] = v[j - 1] + 1;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    subset(n, k);
    return 0;
}