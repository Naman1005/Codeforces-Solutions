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
    ll n, a, b, p1 = 0, p2 = 0, g = 2;
    string s;
    cin >> n >> a >> b >> s;
    if (!count(all(s), '1'))
    {
        cout << (n + 1) * b + n * a << "\n";
        return;
    }
    ll j = n - 1;
    while (s[j] == '0')
        j--, p1++;
    ll i = 0;
    while (s[i] == '0')
        i++, p1++;
    p2 = n + 1 - p1, g = n + 2;
    auto cnt = [&](ll idx)
    {
        ll c = 0;
        while (s[idx] == '0')
            c++, idx++;
        return c;
    };
    while (i < j)
    {
        if (s[i] == '0')
        {
            ll c = cnt(i);
            if ((c - 1) * b + (c + 2) * a < (c - 1) * 2 * b + c * a)
                g += 2, p2 -= c - 1, p1 += c - 1;
            i += c;
            continue;
        }
        i++;
    }
    // cout << p1 << " " << g <<" "<<p2<< "\n";
    cout << (p1 + 2 * p2) * b + g * a << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}