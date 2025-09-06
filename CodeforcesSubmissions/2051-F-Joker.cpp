#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
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
    if constexpr (is_same<T, string>::value)
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
    ll n, m, q, curr = 1;
    ip(n, m, q);
    vll idx(q), ans;
    ip(idx);
    m--;
    for (auto &e : idx)
        e--;
    vector<pair<ll, ll>> rng = {{m, m}};
    for (auto i : idx)
    {
        if (curr == n)
        {
            ans.push_back(curr);
            continue;
        }
        if (rng.size() == 1)
        {
            if (i == rng[0].first && i == rng[0].second)
                rng = {{0, 0}, {n - 1, n - 1}}, curr = 2;
            else if (i >= rng[0].first && i <= rng[0].second)
            {
                if (rng[0].second != n - 1)
                    curr++, rng.push_back({n - 1, n - 1});
                if (rng[0].first != 0)
                    curr++, rng.push_back({0, 0});
                sort(all(rng));
            }
            else if (i < rng[0].first)
                rng[0].first--, curr++;
            else if (i > rng[0].second)
                rng[0].second++, curr++;
        }
        else if (rng.size() == 2)
        {
            if (i >= rng[0].first && i <= rng[0].second)
                rng[1].first--, curr++;
            else if (i >= rng[1].first && i <= rng[1].second)
                rng[0].second++, curr++;
            else
            {
                rng[0].second++, curr++;
                if (rng[0].second != rng[1].first - 1)
                    rng[1].first--, curr++;
            }
        }
        else if (rng.size() == 3)
        {
            if (i >= rng[0].first && i <= rng[0].second)
            {
                if (rng[1].first != rng[0].second + 1)
                    rng[1].first--, curr++;
                if (rng[2].first != rng[1].second + 1)
                    rng[2].first--, curr++;
            }
            else if (i >= rng[2].first && i <= rng[2].second)
            {
                if (rng[1].second != rng[2].first - 1)
                    rng[1].second++, curr++;
                if (rng[0].second != rng[1].first - 1)
                    rng[0].second++, curr++;
            }
            else if (i >= rng[1].first && i <= rng[1].second)
            {
                if (rng[0].second != rng[1].first - 1)
                    rng[0].second++, curr++;
                if (rng[2].first != rng[1].second + 1)
                    rng[2].first--, curr++;
            }
            else if (i < rng[1].first && i > rng[0].second)
            {
                rng[0].second++, curr++;
                if (rng[0].second != rng[1].first - 1)
                    rng[1].first--, curr++;
                if (rng[2].first != rng[1].second + 1)
                    rng[2].first--, curr++;
            }
            else if (i < rng[2].first && i > rng[1].first)
            {
                rng[2].first--, curr++;
                if (rng[2].first != rng[1].second + 1)
                    rng[1].second++, curr++;
                if (rng[0].second != rng[1].first - 1)
                    rng[0].second++, curr++;
            }
        }
        // pr(rng);
        ans.push_back(curr);
    }
    pr(ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll too_much_work = 1;
    cin >> too_much_work;
    while (too_much_work--)
        click_clack_boom();
}