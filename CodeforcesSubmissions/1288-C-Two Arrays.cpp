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
mint dp[11][1001][1001];
bool vis[11][1001][1001];
ll n, m;
mint fun(int i, int a, int b) {
    if (i == m) return 1;
    if (a > b || b < 1 || a > n) return 0;
    if (vis[i][a][b]) return dp[i][a][b];
    vis[i][a][b] = true;
    return dp[i][a][b] = fun(i + 1, a, b) + fun(i, a + 1, b) + fun(i, a, b - 1) - fun(i, a + 1, b - 1);
}
void click_clack_boom() {
    cin >> n >> m;
    fro(idx, 0, m - 1) fro(ai, 0, n) fro(bi, 0, n) dp[idx][ai][bi] = -1;
    cout << fun(0, 1, n) << "\n";
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