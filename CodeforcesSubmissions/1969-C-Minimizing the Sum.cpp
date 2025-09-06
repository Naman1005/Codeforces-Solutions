#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
template <typename T, typename = void>
struct is_container : false_type
{
};
template <typename T>
struct is_container<T, void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : true_type
{
};
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
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void click_clack_boom()
{
    ll n, k;
    ip(n, k);
    vll a(n);
    ip(a);
    vector<vll> dp(n + 1, vll(k + 1, 0));
    // dp[i][j] means first i elements are picked using j operations
    // when no elements are picked (meaning i = 0) dp[0][j] = 0 for all j
    // when no operations are done (meaning j = 0) dp[i][0] = prefix[i] for all i
    fro(i, 1, n) dp[i][0] = dp[i - 1][0] + a[i - 1];
     fro(i, 1, n) fro(j, 1, k)
    {
        // transitions can be:
        // 1. Do not perform an operation, dp[i][j] = dp[i-1][j] + a[i-1]
        // 2. Perform m (m<=j and m < i) operations from the last element a[i-1] and
        //    make all m+1 elements from the last equal to a[i-1]
        // 3. Perform m (m<=j and m < i) operations from a[i-m-1] till the end of the array
        //    making all m+1 elements equal to a[i-m-1]
        dp[i][j] = dp[i - 1][j] + a[i - 1];
        ll case2 = LONG_LONG_MAX, case3 = LONG_LONG_MAX;
        fro(m, 1, j)
        {
            if (m >= i)
                break;
            case2 = min(case2, dp[i - m - 1][j - m] + a[i - 1] * (m + 1));
            case3 = min(case3, dp[i - m][j - m] + a[i - m - 1] * (m));
        }
        dp[i][j] = min({dp[i][j], case2, case3});
    }
    pr(dp[n][k], " ");
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); inp_out();
    ll too_much_work = 1, copied_work; cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now(); auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / copied_work) << " ms" << endl;
}