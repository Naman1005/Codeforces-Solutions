// Touch some grass my bro
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
 // condition A = si > wi
// condition B = si < wi
// dp[i][j][k] = number of ways to make strings of length i following condition A if j is true and following condition B if k is true.
// dp[i][0][0] = numways for string of length i where no condtion is satisfied
// dp[i][0][1] = numways for string of length i where only condtion B is satisfied
// dp[i][1][0] = numways for string of length i where only condtion A is satisfied
// dp[i][1][1] = numways for string of length i where condtions A and B are satisfied
// The answer would be given by dp[n][1][1] as we want to make strings of length n while following both conditions
// for strings of length 1 we cannot make both conditions true at once.
ll n;
mint fun(ll i, bool j, bool k, string &s, string &w, vector<vector<vector<mint>>> &dp) {
    // if i reaches n we can check if both conditions are true
    if (i == n) return (j && k);
    // if already calculated some result, return it
    if (dp[i][j][k] != -1) return dp[i][j][k];
    // if both strings have digits at i, we can't control the conditions and can move ahead
    if (s[i] != '?' && w[i] != '?') {
        if (s[i] > w[i])
            dp[i][j][k] = fun(i + 1, true, k, s, w, dp);
        else if (s[i] < w[i])
            dp[i][j][k] = fun(i + 1, j, true, s, w, dp);
        else
            dp[i][j][k] = fun(i + 1, j, k, s, w, dp);
    } else {
        dp[i][j][k] = 0;
        if (s[i] == '?' && w[i] == '?') {
            // if both strings have ? at i then we can control all three conditions of >, =, < freely
            // for 2 empty spots, we have a total of 100 distinct ways to fill them,
            // 45 ways for >, 45 ways for < and 10 ways for =
            dp[i][j][k] += fun(i + 1, j, k, s, w, dp) * 10;    // for =
            dp[i][j][k] += fun(i + 1, true, k, s, w, dp) * 45; // for >
            dp[i][j][k] += fun(i + 1, j, true, s, w, dp) * 45; // for <
        } else if (s[i] == '?') {
            // if si is ? we have 1 way for =, '9' - wi ways for > and wi - '0' ways for <
            dp[i][j][k] += fun(i + 1, j, k, s, w, dp);                      // for =
            dp[i][j][k] += fun(i + 1, true, k, s, w, dp) * int('9' - w[i]); // for >
            dp[i][j][k] += fun(i + 1, j, true, s, w, dp) * int(w[i] - '0'); // for <
        } else if (w[i] == '?') {
            // if wi is ? we have 1 way for =, '9' - si ways for > and si - '0' ways for <
            dp[i][j][k] += fun(i + 1, j, k, s, w, dp);                      // for =
            dp[i][j][k] += fun(i + 1, true, k, s, w, dp) * int(s[i] - '0'); // for >
            dp[i][j][k] += fun(i + 1, j, true, s, w, dp) * int('9' - s[i]); // for <
        }
    }
    return dp[i][j][k];
}
 void click_clack_boom() {
    string s, w;
    cin >> n >> s >> w;
    vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(2, vector<mint>(2, -1)));
    cout << fun(0, 0, 0, s, w, dp) << "\n";
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