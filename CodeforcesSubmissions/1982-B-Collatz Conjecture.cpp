#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(),(a).end()
#define sortv(v) sort(all(v))
#define sort_and_unique(a) sort(all(a));(a).resize(unique(all(a))-(a).begin())
#define fro(i,x,y) for(ll i=x; i<=y; i++)
#define pre(i,x,y) for(ll i=x; i>=y; i--)
#define fact(n) (ll)tgamma(n+1)
#define truncMod(a,b) (ll)(a - (b * (floor(a / b))))
void inp_out()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" , stdin);
    freopen("output.txt" ,"w" , stdout);
    #endif
}
ll solve(ll x, ll y, ll k)
{
    ll rem2, rem = y - (x % y);
    if (k == rem)
    {
        x += k;
        while (x % y == 0) x /= y;
        return x;
    }
    if (k < rem)
        return x + k;
    while (true)
    {
        rem2 = rem;
        if (x == 1)break; 
        if (k >= rem2)
        {
            k -= rem2, x += rem2;
            while (x % y == 0) x /= y;
            rem = y - (x % y);
        }
        else
        {
            x += k, k = 0;
            break;
        }
    }
    if (k != 0) return k % (y - 1) + 1;
    return x;
}
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    inp_out();
    cout<<setprecision(20)<<fixed;
    ll t,x,y,k;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k;
        cout<<solve(x,y,k)<<endl;
    }
}
 