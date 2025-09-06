#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
#define sortv(v) sort(v.begin(), v.end())
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}
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
    int t, len, p1, p2, min_len;
    int flag1, flag2, flag3;
    string s;
    cin >> t;
    while (t--)
    {
        flag1 = 0, flag2 = 0, flag3 = 0;
        cin >> s;
        len = s.length();
        p1 = 0;
        p2 = 0;
        fro(i, 0, len - 1)
        {
            s[i] == '1' ? flag1++ : (s[i] == '2' ? flag2++ : flag3++);
            if (flag1 && flag2 && flag3)
            {
                p2 = i;
                break;
            }
        }
        if (!p2)
            cout << 0 << "\n";
        else
        {
            min_len = p2 + 1;
            while (p2 < len)
            {
                s[p1] == '1' ? flag1-- : (s[p1] == '2' ? flag2-- : flag3--);
                p1++;
                while ((!flag1 || !flag2 || !flag3) && p2 < len)
                {
                    p2++;
                    s[p2] == '1' ? flag1++ : (s[p2] == '2' ? flag2++ : flag3++);
                }
                if (flag1 && flag2 && flag3)
                    min_len = min(min_len, p2 - p1 + 1);
            }
            cout << min_len << "\n";
        }
    }
}