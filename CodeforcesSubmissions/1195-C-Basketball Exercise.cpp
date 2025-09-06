    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define pi 3.141592653589793238462643383279
    #define vi vector<int>
    #define vll vector<ll>
    #define um unordered_map
    #define all(a) (a).begin(),(a).end()
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
    void solve()
    {
        ll n;
        cin>>n;
        vector<vll> arr(2, vll(n)), dp(2, vll(n));
        fro(i,0,n-1)cin>>arr[0][i];
        fro(i,0,n-1)cin>>arr[1][i];
        dp[0][0] = arr[0][0], dp[1][0] = arr[1][0];
        fro(i,1,n-1)
        {
            dp[0][i] = max(arr[0][i] + dp[1][i-1], dp[0][i-1]);
            dp[1][i] = max(arr[1][i] + dp[0][i-1], dp[1][i-1]);
        }
        cout<<max(dp[0][n-1], dp[1][n-1])<<"\n";
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        inp_out();
        cout<<setprecision(20)<<fixed;
        ll t = 1;
        // cin>>t;
        while(t--)solve();
    }