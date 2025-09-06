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
ll prefXor(ll n) { return (n & 3) == 0 ? n : (n & 3) == 1 ? 1 : (n & 3) == 2 ? n + 1 : 0; }
ll xorRange(ll l, ll r) { return prefXor(r) ^ (l > 0 ? prefXor(l - 1) : 0); }
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
const int mod = 1e9 + 7;
struct mint {
    int x;
    mint() { x = 0; }
    mint(int32_t xx) {
        x = xx % mod;
        if (x < 0) x += mod;
    }
    mint(long long xx) {
        x = xx % mod;
        if (x < 0) x += mod;
    }
    int val() { return x; }
    mint &operator++() {
        x++;
        if (x == mod) x = 0;
        return *this;
    }
    mint &operator--() {
        if (x == 0) x = mod;
        x--;
        return *this;
    }
    mint operator++(int32_t) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int32_t) {
        mint result = *this;
        --*this;
        return result;
    }
    mint &operator+=(const mint &b) {
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint &operator-=(const mint &b) {
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    mint &operator*=(const mint &b) {
        long long z = x;
        z *= b.x;
        z %= mod;
        x = (int)z;
        return *this;
    }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint operator/=(const mint &b) { return *this = *this * b.inv(); }
    mint power(long long n) const {
        mint ok = *this, r = 1;
        while (n) {
            if (n & 1) r *= ok;
            ok *= ok;
            n >>= 1;
        }
        return r;
    }
    mint inv() const { return power(mod - 2); }
    friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
    friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
    friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
    friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
    friend bool operator==(const mint &a, const mint &b) { return a.x == b.x; }
    friend bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }
    friend ostream &operator<<(ostream &os, const mint &obj) {
        os << obj.x;
        return os;
    }
    friend istream &operator>>(istream &is, mint &obj) {
        int32_t x;
        is >> x;
        obj = mint(x);
        return is;
    }
};
struct factorials {
    int n;
    vector<mint> ff, iff;
    factorials(int nn) {
        n = nn;
        ff.resize(n + 1);
        iff.resize(n + 1);
        ff[0] = 1;
        for (int i = 1; i <= n; i++) { ff[i] = ff[i - 1] * i; }
        iff[n] = ff[n].inv();
        for (int i = n - 1; i >= 0; i--) { iff[i] = iff[i + 1] * (i + 1); }
    }
    mint C(int n, int r) {
        if (n == r) return mint(1);
        if (n < 0 || r < 0 || r > n) return mint(0);
        return ff[n] * iff[r] * iff[n - r];
    }
    mint P(int n, int r) {
        if (n < 0 || r < 0 || r > n) return mint(0);
        return ff[n] * iff[n - r];
    }
    mint solutions(int n, int r) { return C(n + r - 1, n - 1); }
    mint catalan(int n) { return ff[2 * n] * iff[n] * iff[n + 1]; }
};
factorials F(2e5);
void click_clack_boom() {
    ll n, m, k, ep = 0;
    ip(n, m);
    vector<vll> adj(n + 1);
    vll deg(n + 1, 0), vec;
    fro(i, 1, m) {
        ll u, v;
        ip(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    if (m != n - 1) {
        pr("0");
        return;
    }
    if (n == 2) {
        pr("2");
        return;
    }
    vb leaf(n + 1, 0);
    fro(i, 1, n) {
        if (deg[i] == 1)
            leaf[i] = 1;
        else
            vec.push_back(i);
    }
    k = vec.size();
    if (k == 0) {
        pr("0");
        return;
    }
    for (auto u : vec) {
        ll cnt = 0;
        for (auto v : adj[u])
            if (!leaf[v]) cnt++;
        if (cnt > 2) {
            pr("0");
            return;
        }
        if (cnt <= 1) ep++;
    }
    if (!((k > 1 && ep == 2) || (k == 1 && ep == 1))) {
        pr("0");
        return;
    }
    if (k > 1) {
        vb vis(n + 1);
        queue<ll> q;
        q.push(vec[0]);
        vis[vec[0]] = 1;
        ll curr = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            curr++;
            for (auto v : adj[u])
                if (!leaf[v] && !vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
        }
        if (curr != k) {
            pr("0");
            return;
        }
    }
    mint mul = 1;
    for (auto u : vec) {
        ll cnt = 0;
        for (auto v : adj[u])
            if (leaf[v]) cnt++;
        mul *= F.ff[cnt];
    }
    pr((k == 1 ? mint(2) * mul : mint(4) * mul).val(), "");
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