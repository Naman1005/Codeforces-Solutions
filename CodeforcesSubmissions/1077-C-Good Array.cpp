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
    ll n, sum = 0;
    cin >> n;
    vll arr(n),final;
    map<ll, ll> mp;
    for (auto &x : arr)
    {
        cin >> x;
        mp[x]++, sum+=x;
    }
    fro(i,0,n-1)
    {
        sum -= arr[i], mp[arr[i]]--;
        if(sum%2==0 && mp[sum/2] && sum/2<=1e6)
            final.push_back(i);
        mp[arr[i]]++, sum+= arr[i];
    }
    cout<<final.size()<<"\n";
    for(auto x: final) cout<<x+1<<" ";
    return 0;
}