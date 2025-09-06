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
ll ask(ll l, ll r)
{
    cout << "? " << l << " " << r << '\n';
    ll ans;
    cin >> ans;
    return ans;
}
void click_clack_boom()
{
    ll n, u, x;
    cin >> n;
    vll a(n + 1, -1);
    fro(i, 2, n)
    {
        u = 1, x = -1;
        while (1)
        {
            x = ask(u, i);
            if (x == u)
                break;
            u = x;
        }
        a[i] = x;
    }
    cout << "! ";
    fro(i, 2, n) cout << i << " " << a[i] << " ";
    cout << "\n";
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