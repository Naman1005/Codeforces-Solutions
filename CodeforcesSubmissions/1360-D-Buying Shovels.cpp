#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n, k, i, j, ans;
    double sq;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ans = LONG_LONG_MAX;
        sq = sqrt(n);
        for (i = 1; i <= sq; ++i)
        {
            if (n % i == 0)
            {
                j = n / i;
                if (i <= k)
                {
                    ans = min(ans, j);
                }
                if (j <= k)
                {
                    ans = min(ans, i);
                }
            }
        }
        cout << ans << "\n";
    }
}