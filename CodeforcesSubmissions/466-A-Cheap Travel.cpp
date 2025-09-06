#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b, sum;
    cin >> n >> m >> a >> b;
    if (a > b / m)
        sum = (((n / m) * b) + ((n % m) * a));
    else
        sum = (n * a);
    cout << min(sum, (n / m + 1) * b);
}