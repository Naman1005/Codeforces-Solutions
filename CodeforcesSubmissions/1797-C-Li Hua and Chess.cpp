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
ll ask(ll r, ll c)
{
    cout << "? " << r << " " << c << '\n' << flush;
    ll ans; cin >> ans; return ans;
}
void click_clack_boom()
{
    ll n, m, a,b;
    cin >> n >> m;
    ll x = ask(1, 1), r = 1e18, c = 1e18;
     if(x+1 <= n) r = ask(x + 1, 1);
    if(x+1 <= m) c = ask(1, x + 1);
     if(r == c && r == x) a = b = x + 1;
    else if(r < x) a = x + 1, b = r + 1;
    else if(c < x) a = c + 1, b = x + 1;
        cout << "! " << a << " " << b << "\n" << flush;   
}
int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}