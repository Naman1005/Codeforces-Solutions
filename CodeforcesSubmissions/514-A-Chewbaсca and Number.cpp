#include <bits/stdc++.h>
using namespace std;
long long solve(long long n)
{
    long long m = n;
    long long i = 0;
    while (m > 9)
    {
        if (m % 10 > 4)
            n = n - ((2 * (m % 10)) - 9) * pow(10, i);
        i++;
        m = m / 10;
    }
    if (m > 4 && m < 9)
        n = n - ((2 * (m % 10)) - 9) * pow(10, i);
    return n;
}
int main()
{
    long long n;
    cin >> n;
    cout << solve(n);
}