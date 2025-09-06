#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n, i, j;
    double sq;
    cin >> n;
    sq = sqrt(n);
    for (i = 2; i <= sq; i++)
    {
        if (n % i == 0)
            for (j = i + 1; j <= sq; j++)
            {
                if ((n % j == 0) && (n % (i * j) == 0) && (n / (i * j) != i) && (n / (i * j) != j))
                {
                    cout << "yes\n";
                    cout << i << " " << j << " " << (n / (i * j)) << "\n";
                    return;
                }
            }
    }
    cout << "no\n";
}
 int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}