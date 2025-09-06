#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    inp_out();
    ll t, n, x, count, m, e;
    cin >> t;
    while (t--)
    {
        count = LONG_LONG_MAX;
        cin >> n;
        for (int a = 0; a < 3; a++) // 1
        {
            for (int b = 0; b < 2; b++) // 3
            {
                for (int c = 0; c < 3; c++) // 6
                {
                    for (int d = 0; d < 3; d++)
                    {
                        e = (n - a - b * 3 - c * 6 - d * 10);
                        if (e % 15 == 0 && ((e / 15) >= 0))
                        {
                            count = min(count, a + b + c + d + (e / 15));
                            // cout << a << " " << b << " " << c << " " << d << " " << e / 15 << "\n";
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }
     return 0;
}
 