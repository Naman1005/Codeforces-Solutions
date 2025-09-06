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
    ll n, m, k;
    cin >> n >> m >> k;
    vll arr(n + 1), updates(n + 1, 0), ops_cnt(m + 1);
    vector<vll> ops(m + 1, vll(3, 0));
    fro(i, 1, n) cin >> arr[i];
    fro(i, 1, m) cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    fro(i, 1, k)
    {
        ll l, r;
        cin >> l >> r;
        ops_cnt[l]++;
        if (r != m)
            ops_cnt[r + 1]--;
    }
    fro(i, 1, m) ops_cnt[i] += ops_cnt[i - 1];
    fro(i, 1, m) if (ops_cnt[i])
    {
        updates[ops[i][0]] += ops_cnt[i] * ops[i][2];
        if (ops[i][1] != n)
            updates[ops[i][1] + 1] -= ops_cnt[i] * ops[i][2];
    }
    fro(i, 1, n) updates[i] += updates[i - 1], arr[i] += updates[i];
    fro(i, 1, n) cout << arr[i] << " ";
    cout << "\n";
}