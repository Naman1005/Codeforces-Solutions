#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fro(i,x,y) for(ll i=(ll)(x); i<=(ll)(y); i++)
#define pre(i,x,y) for(ll i=(ll)(x); i>=(ll)(y); i--)
#define fact(n) (ll)tgamma(n+1)
#define truncMod(a,b) (ll)(a - (b * (floor(a / b))))
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" , stdin);
    freopen("output.txt" ,"w" , stdout);
#endif
}
void click_clack_boom()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<string> vs(n);
    fro(i, 0, n - 1) cin >> vs[i];
    fro(x1, 0, n - 1) fro(x2, x1, n - 1)
    {
        ll temp = 0;
        fro(j, 0, m - 1)
        {
            bool f = 1;
            fro(i, x1, x2) if (vs[i][j] == '1') f = 0;
            f ? temp++, ans = max(ans, (temp + x2 - x1 + 1) * 2) : temp = 0;
        }
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); inp_out();
    ll too_much_work = 1, copied_work = 1;
    // cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}