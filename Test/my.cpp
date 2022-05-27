#include <iostream>
#include <vector>

using namespace std;

void arrange(vector<int> v, int n, int k, int i, vector<bool> b)
{
    for (int j = 1; j <= n; j++)
    {
        if (b[j] == true)
        {
            v[i] = j;
            if (i == k)
            {
                for (int l = 1; l <= k; l++)
                    cout << v[l] << " ";
                cout << endl;
            }
            else
            {
                b[j] = false;
                arrange(v, n, k, i + 1, b);
                b[j] = true;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(k + 1);
    vector<bool> b(k + 1);

    for (int i = 1; i <= k; i++)
        b[i] = true;

    arrange(v, n, k, 1, b);
    return 0;
}