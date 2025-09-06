#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, t, l, r;
    cin >> n;
    long long arr[n], sortedarr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        sortedarr[i] = arr[i];
    }
    sort(sortedarr, sortedarr + n);
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
        sortedarr[i] += sortedarr[i - 1];
    }
    cin >> m;
    while (m--)
    {
        cin >> t >> l >> r;
        if (t == 1)
            cout << (arr[r - 1] - ((l - 2) >= 0 ? arr[l - 2] : 0)) << "\n";
        else if (t == 2)
            cout << (sortedarr[r - 1] - ((l - 2) >= 0 ? sortedarr[l - 2] : 0)) << "\n";
    }
}