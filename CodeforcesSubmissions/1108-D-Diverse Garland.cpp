#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
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
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, cnt = 0;
    cin >> n;
    string temp = "", s, col = "RGB";
    char c;
    cin >> s;
    vector<string> vec;
    fro(i, 0, n - 1)
    {
        temp += s[i];
        if (i < n - 1 && s[i] != s[i + 1])
            vec.push_back(temp), temp = "";
    }
    if (temp.size())
        vec.push_back(temp);
    fro(i, 0, vec.size() - 1) if (vec[i].size() > 1)
    {
        for (auto x : col)
            if (x != vec[i][0] && (i == vec.size() - 1 || x != vec[i + 1][0]))
                c = x;
        fro(j, 1, vec[i].size() - 1) vec[i][j++] = c, cnt++;
    }
    cout << cnt << "\n";
    fro(i, 0, vec.size() - 1) cout << vec[i];
    cout << "\n";
}