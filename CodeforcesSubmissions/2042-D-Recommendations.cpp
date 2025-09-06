//  ███▄    █  ▄▄▄       ███▄ ▄███▓ ▄▄▄       ███▄    █
//  ██ ▀█   █ ▒████▄    ▓██▒▀█▀ ██▒▒████▄     ██ ▀█   █
// ▓██  ▀█ ██▒▒██  ▀█▄  ▓██    ▓██░▒██  ▀█▄  ▓██  ▀█ ██▒
// ▓██▒  ▐▌██▒░██▄▄▄▄██ ▒██    ▒██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒
// ▒██░   ▓██░ ▓█   ▓██▒▒██▒   ░██▒ ▓█   ▓██▒▒██░   ▓██░
// ░ ▒░   ▒ ▒  ▒▒   ▓▒█░░ ▒░   ░  ░ ▒▒   ▓▒█░░ ▒░   ▒ ▒
// ░ ░░   ░ ▒░  ▒   ▒▒ ░░  ░      ░  ▒   ▒▒ ░░ ░░   ░ ▒░
//    ░   ░ ░   ░   ▒   ░      ░     ░   ▒      ░   ░ ░
//          ░       ░  ░       ░         ░  ░         ░
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define vpl vector<pll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
#define slice(s, i, j) (((size_t)(i) >= (s).size() || (size_t)(i) > (size_t)(j)) ? string() : (s).substr((size_t)(i), min((size_t)(j), (s).size() - 1) - (size_t)(i) + 1))
template <typename T> using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pqmx = priority_queue<T>;
void inp_out() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
template <typename T, typename = void> struct is_container : false_type {};
template <typename T> struct is_container<T, void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : true_type {};
template <typename T1, typename T2> void pr(const pair<T1, T2> &p) { cout << p.first << ' ' << p.second << endl; }
template <typename T> void pr(const T &element) {
    if constexpr (is_same<T, string>::value || is_same_v<decay_t<T>, const char *> || is_same_v<decay_t<T>, char *>)
        cout << element << endl;
    else if constexpr (is_container<T>::value) {
        for (const auto &e : element) pr(e);
        cout << endl;
    } else
        cout << element << ' ';
}
template <typename T, typename... Args> void pr(const T &first, const Args &...args) {
    pr(first);
    pr(args...);
}
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T> void ip(T &element) {
    if constexpr (is_same<T, string>::value)
        cin >> element;
    else if constexpr (is_container<T>::value) {
        for (auto &e : element) ip(e);
    } else
        cin >> element;
}
template <typename T, typename... Args> void ip(T &first, Args &...args) {
    ip(first);
    ip(args...);
}
void click_clack_boom() {
    ll n;
    ip(n);
    vpl vp(n);
    ip(vp);
    auto temp = vp;
    vll idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](ll a, ll b) {
        return vp[a].first == vp[b].first ? vp[a].second < vp[b].second : vp[a].first < vp[b].first;
    });
    sort(all(vp), [&](pair<ll, ll> &a, pair<ll, ll> &b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    multiset<ll> ms;
    vll ans(n, 0);
    vb vis(n, 0);
    fro(i, 0, n - 1) {
        if (!vis[i]) {
            vis[i] = 1;
            ms.insert(vp[i].second);
            fro(j, i + 1, n) {
                if (vp[j].first == vp[i].first) {
                    vis[j] = 1;
                    ms.insert(vp[j].second);
                } else
                    break;
            }
        }
        auto it = ms.lower_bound(vp[i].second);
        it++;
        if (it == ms.end()) continue;
        ans[idx[i]] += *it - vp[i].second;
    }
    vp = temp;
    sort(all(idx), [&](ll a, ll b) {
        return vp[a].second == vp[b].second ? vp[a].first > vp[b].first : vp[a].second > vp[b].second;
    });
    sort(all(vp), [&](pair<ll, ll> &a, pair<ll, ll> &b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second;
    });
    ms.clear();
    vis.assign(n, 0);
    fro(i, 0, n - 1) {
        if (!vis[i]) {
            vis[i] = 1;
            ms.insert(vp[i].first);
            fro(j, i + 1, n - 1) {
                if (vp[j].second == vp[i].second) {
                    vis[j] = 1;
                    ms.insert(vp[j].first);
                } else
                    break;
            }
        }
        auto it = prev(ms.upper_bound(vp[i].first));
        if (it == ms.begin()) continue;
        it--;
        ans[idx[i]] += vp[i].first - *it;
    }
    for (auto x : ans) pr(x, "");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    // cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}