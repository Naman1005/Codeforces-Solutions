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
typedef unsigned long long ull;
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
thread_local mt19937_64 rng = []() {
    random_device rd;
    array<ull, 3> seeds{(ull)rd(), (ull)chrono::high_resolution_clock::now().time_since_epoch().count(), (ull)hash<thread::id>{}(this_thread::get_id())};
    seed_seq seq(seeds.begin(), seeds.end());
    return mt19937_64(seq);
}();
ll rand_ll(ll l, ll r) {
    if (l > r) swap(l, r);
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng);
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
void inp_out() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
void click_clack_boom() {
    ll n, k, d;
    ip(n, k, d);
    function<mint(ll, ll)> run = [&](ll s, ll e) -> mint {
        if (e <= 0) return 0;
        vector<mint> dp(s + 1);
        dp[0] = 1;
        fro(i, 1, s) {
            fro(j, 1, e) {
                if (i - j < 0) break;
                dp[i] += dp[i - j];
            }
        }
        return dp[s];
    };
    pr((run(n, k) - run(n, d - 1)).val(), "");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    ll too_much_work = 1, copied_work = 1;
    // cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    // cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}