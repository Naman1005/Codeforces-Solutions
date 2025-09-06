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
template <typename T, typename = void>
struct is_container : false_type{};
template <typename T>
struct is_container<T, void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : true_type{};
template <typename T1, typename T2>
void pr(const pair<T1, T2> &p) { cout << p.first << ' ' << p.second << endl; }
template <typename T>
void pr(const T &element)
{
    if constexpr (is_same<T, string>::value || is_same_v<decay_t<T>, const char *> || is_same_v<decay_t<T>, char *>)
        cout << element << endl;
    else if constexpr (is_container<T>::value)
    {
        for (const auto &e : element)
            pr(e);
        cout << endl;
    }
    else
        cout << element << ' ';
}
template <typename T, typename... Args>
void pr(const T &first, const Args &...args)
{
    pr(first);
    pr(args...);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T>
void ip(T &element)
{
    if constexpr (is_same<T, string>::value)
        cin >> element;
    else if constexpr (is_container<T>::value)
    {
        for (auto &e : element)
            ip(e);
    }
    else
        cin >> element;
}
template <typename T, typename... Args>
void ip(T &first, Args &...args)
{
    ip(first);
    ip(args...);
}
void click_clack_boom()
{
    ll n, m, q;
    ip(n, m);
    vector<string> vs(n);
    ip(vs, q);
    vector<vll> hor(n + 1, vll(m + 1)), ver(n + 1, vll(m + 1));
    fro(i, 0, n - 1) fro(j, 0, m - 1)
    {
        hor[i + 1][j + 1] = (j < m - 1 && vs[i][j] == '.' && vs[i][j + 1] == '.');
        ver[i + 1][j + 1] = (i < n - 1 && vs[i][j] == '.' && vs[i + 1][j] == '.');
        hor[i + 1][j + 1] += hor[i][j + 1] + hor[i + 1][j] - hor[i][j];
        ver[i + 1][j + 1] += ver[i + 1][j] + ver[i][j + 1] - ver[i][j];
    }
    // pr(hor,ver);
    while (q--)
    {
        ll r1, c1, r2, c2;
        ip(r1, c1, r2, c2);
        cout << hor[r2][c2 - 1] - hor[r2][c1 - 1] - hor[r1 - 1][c2 - 1] + hor[r1 - 1][c1 - 1] + ver[r2 - 1][c2] - ver[r1 - 1][c2] - ver[r2 - 1][c1 - 1] + ver[r1 - 1][c1 - 1] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); inp_out();
    ll too_much_work = 1, copied_work = 1;
    // cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}