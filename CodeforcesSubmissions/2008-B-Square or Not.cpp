#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(),(a).end()
#define sort_and_unique(a) sort(all(a));(a).resize(unique(all(a))-(a).begin())
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
bool check(ll n, string s)
{
    ll r = sqrt(n);
    if(r*r != n)
        return false;
    fro(i, 0, r - 1) if (s[i] != '1' || s[n - r + i] != '1') return false;
    fro(i,1,r-2)
    {
        if(s[i*r]!='1' || s[i*r+r-1]!='1')
            return false;
        fro(j, 1, r - 2) if (s[i * r + j] != '0') return false;
    }
    return true;
}
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    cout << (check(n, s) ? "YES\n" : "NO\n");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    inp_out();
    cout<<setprecision(20)<<fixed;
    ll t = 1;
    cin>>t;
    while(t--)solve();
}