#include <iostream>
#include <vector>

using namespace std;

void subset(vector<int> v, int n, int k, int i)
{
    for (int j = v[i - 1] + 1; j <= n - k + i; j++)
    {
        v[i] = j;
        if (i == k)
        {
            for (int l = 1; l <= k; l++)
                cout << v[l] << " ";
            cout << endl;
        }
        else
            subset(v, n, k, i + 1);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(k + 1);
    v[0] = 0;

    subset(v, n, k, 1);
    return 0;
}