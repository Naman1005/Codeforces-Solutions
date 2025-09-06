#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t, n, x, sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long arr[n], arr2[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr2[i] = arr[i] - i;
        }
        unordered_map<long long, long long> m;
        for (long long i = 0; i < n; i++)
            m[arr2[i]] += 1;
        sum = 0;
        for (auto k : m)
        {
            x = k.second;
            if (x > 1)
            {
                sum += (x * (x - 1)) / 2;
            }
        }
        cout << sum << "\n";
    }
}