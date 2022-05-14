#include <iostream>
#include <string>

using namespace std;

void bit_generator(int n)
{
    string bit(n, '0');
    int i;
    while (true)
    {
        cout << bit << endl;
        i = n - 1;
        while (i >= 0 && bit[i] == '1')
            i--;
        if (i == -1)
            return;
        bit[i] = '1';
        bit.replace(i + 1, n - i - 1, n - i - 1, '0');
    }
}
int main()
{
    int n;
    cin >> n;
    bit_generator(n);
}