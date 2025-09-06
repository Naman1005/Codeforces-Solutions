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
ll ask(ll l, ll r){
    cout << "? " << l << " " << r << '\n';
    cout << flush;
    ll ans;
    cin >> ans;
    return ans;
}
void click_clack_boom()
{
    ll plow = 1, phigh = 999, low, high, x;
    // cout << plow << " " << phigh << " " << low << " " << high << "\n";
    while (plow < phigh-2)
    {
        low = (2 * plow + phigh) / 3, high = (2 * phigh + plow) / 3;
        x = ask(low, high);
        if (x == low * high)
            plow = high;
        else if (x == low * (high + 1))
            plow = low, phigh = high;
        else if (x == (low + 1) * (high + 1))
            phigh = low;
    }
    // cout << plow << " " << low << " " << high << " " << phigh << "\n";
    if(phigh -plow == 2) {
        x = ask(1, plow + 1);
        if(x!=plow+1)phigh = plow + 1;
    }
    cout <<"! "<< phigh << "\n";
    cout << flush;
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