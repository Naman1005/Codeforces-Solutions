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
    char head, tail;
    int flag;
    string ans;
    cin >> t;
    while (t--)
    {
        //         1
        // 9
        // 100101101
        // 101001101
        flag = 1;
        count1 = 1;
        count2 = 1;
        cin >> n;
        char first[n - 1], second[n - 1];
        cin >> head;
        for (ll i = 0; i < n - 1; i++)
            cin >> first[i];
        for (ll i = 0; i < n - 1; i++)
            cin >> second[i];
        cin >> tail;
        ans = head;
        for (ll i = 0; i < n - 1; i++)
        {
            if (second[i] < first[i] && flag)
            {
                ans += second[i];
                flag = 0;
            }
            else if (flag)
                ans += first[i];
            else if (!flag)
                ans += second[i];
        }
        for (ll i = 0; i < n - 1; i++)
        {
            if (first[i] == ans[i + 1])
                count1++;
            else
                break;
        }
        for (ll i = n - 2; i >= 0; i--)
        {
            if (second[i] == ans[i + 1])
                count2++;
            else
                break;
        }
        ans += tail;
        cout << ans << "\n"
             << count1 + count2 - n << "\n";
        // cout<<count1<<" "<<count2<<"\n";
    }
}