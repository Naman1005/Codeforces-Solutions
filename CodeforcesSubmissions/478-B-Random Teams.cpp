#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    cin>>n>>m;
    ll arr[10];
    if (n == m)
        cout << 0 << " " << 0;
    else
    {
        arr[0] = n - m + 1;
        arr[1] = n / m;
        arr[2] = n % m;
         cout << (arr[2] * (arr[1] + 1) * arr[1] / 2) + ((m - arr[2]) * arr[1] * (arr[1] - 1) / 2) << " " << arr[0] * (arr[0] - 1) / 2;
    }
}