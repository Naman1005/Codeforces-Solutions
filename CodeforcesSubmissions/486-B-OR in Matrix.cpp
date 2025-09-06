#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
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
    ll m, n;
    bool frow, fcol, oexits = false, final = false;
    ;
    cin >> m >> n;
    ll matA[m][n], matB[m][n];
    fro(i, 0, m - 1) fro(j, 0, n - 1) cin >> matB[i][j];
    fro(i, 0, m - 1) fro(j, 0, n - 1)
    {
        if (matB[i][j])
        {
            oexits = true;
            frow = fcol = true;
            fro(k, 0, n - 1) if (k != j && (!matB[i][k]))
            {
                frow = false;
                break;
            }
            fro(k, 0, m - 1) if (k != i && (!matB[k][j]))
            {
                fcol = false;
                break;
            }
            if (frow && fcol)
            {
                matA[i][j] = 1;
                final = true;
            }
            else if (frow || fcol)
                matA[i][j] = 0;
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
        else
            matA[i][j] = 0;
    }
    if (oexits && (!final))
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        fro(i, 0, m - 1)
        {
            fro(j, 0, n - 1) cout << matA[i][j] << " ";
            cout << "\n";
        }
    }
}