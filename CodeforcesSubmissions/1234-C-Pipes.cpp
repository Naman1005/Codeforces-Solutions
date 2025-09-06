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
    ll n, r = 0, c = 0, pr = 0, pc = -1;
    vector<string> vs(2);
    cin >> n >> vs[0] >> vs[1];
    auto first = [](char ch)
    { return ch == '1' || ch == '2'; };
    while (1)
    {
        if (r == 1 && c == n)
        {
            cout << "YES\n";
            return;
        }
        if (r < 0 || r > 1 || c < 0 || c > n - 1)
        {
            cout << "NO\n";
            return;
        }
        char ch = vs[r][c];
        pc = c;
        if (r == 0)        
            (pr == 0) ? (pr = r, (first(ch)) ? c++ : r++) : (pr = r, (first(ch)) ? r-- : c++);        
        else      
            (pr == 0) ? (pr = r, (first(ch)) ? r++ : c++) : (pr = r, (first(ch)) ? c++ : r--);        
    }
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