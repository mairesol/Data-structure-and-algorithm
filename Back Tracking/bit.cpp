#include <iostream>
#include <string>

using namespace std;

void bit(string b, int i)
{
    for (int j = 0; j <= 1; j++)
    {
        b[i] = '0' + j;
        if (i == b.size() - 1)
            cout << b << endl;
        else
            bit(b, i + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    string b(n, 0);
    bit(b, 0);
    return 0;
}