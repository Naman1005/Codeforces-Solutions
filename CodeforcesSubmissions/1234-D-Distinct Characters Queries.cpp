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
class SegmentTree {
    int n;
    vector<ll> tree;
    ll merge_bits(ll a, ll b) { return a | b; }
    void build(const string &s, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = 1LL << (s[l] - 'a');
            return;
        }
        int m = (l + r) >> 1;
        build(s, idx * 2 + 1, l, m);
        build(s, idx * 2 + 2, m + 1, r);
        tree[idx] = merge_bits(tree[idx * 2 + 1], tree[idx * 2 + 2]);
    }
    ll query_bits(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int m = (l + r) >> 1;
        return merge_bits(query_bits(idx * 2 + 1, l, m, ql, qr), query_bits(idx * 2 + 2, m + 1, r, ql, qr));
    }
    void update_char(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            tree[idx] = 1LL << (c - 'a');
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m)
            update_char(idx * 2 + 1, l, m, pos, c);
        else
            update_char(idx * 2 + 2, m + 1, r, pos, c);
        tree[idx] = merge_bits(tree[idx * 2 + 1], tree[idx * 2 + 2]);
    }
 public:
    SegmentTree(const string &s) {
        n = s.size();
        tree.assign(4 * n, 0);
        build(s, 0, 0, n - 1);
    }
    void update(int pos, char c) { update_char(0, 0, n - 1, pos, c); }
    int range_unique(int l, int r) {
        ll mask = query_bits(0, 0, n - 1, l, r);
        return __builtin_popcountll(mask);
    }
};
void click_clack_boom() {
    string s;
    ll q, op, l, r;
    char c;
    cin >> s >> q;
    SegmentTree st(s);
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> c;
            st.update(l - 1, c);
        } else {
            cin >> l >> r;
            cout << st.range_unique(l - 1, r - 1) << "\n";
        }
    }
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