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
    inp_out();
    ll t, n, count1, count2;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n-1; i++)
        {
            count1 = 0;
            for (ll j = 0; j < n; j++)
            {
                if (arr[i][j] == '1')
                    count1++;
            }
            if (count1)
            {
                count2 = 0;
                for (ll j = 0; j < n; j++)
                {
                    if (arr[i+1][j] == '1')
                        count2++;
                }
                if (count1 == count2)
                {
                    cout << "SQUARE\n";
                    break;
                }
                else
                {
                    cout << "TRIANGLE\n";
                    break;
                }
            }
        }
    }
}