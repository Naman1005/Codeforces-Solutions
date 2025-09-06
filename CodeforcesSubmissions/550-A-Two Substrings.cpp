#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sortv(v) sort(all(v))
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
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
    string s;
    cin >> s;
    ll n = s.length(), fbab, faba, fab, fba;
    vector<string> arr(n);
    fro(i, 0, n - 2)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
            arr[i] = "AB";
        else if (s[i] == 'B' && s[i + 1] == 'A')
            arr[i] = "BA";
    }
    fbab = faba = fab = fba = 0;
    fro(i, 0, n - 2)
    {
        if (arr[i] == "AB") arr[i + 1] == "BA" ? faba++ : fab++;
        else if (arr[i] == "BA") arr[i + 1] == "AB" ? fbab++ : fba++;
    }
    if (faba > 1 || fbab > 1 || (fbab && fab > 1) || (faba && fba > 1)) cout << "YES\n";
    else if (!fab || !fba) cout << "NO\n";
    else cout << "YES\n";
}