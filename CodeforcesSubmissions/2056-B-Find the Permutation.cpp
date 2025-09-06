#include <bits/stdc++.h>
using namespace std;
void dfs(int v, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
{
    vis[v] = true;
    for (int i : adj[v])
        if (!vis[i])
            dfs(i, adj, vis, st);
    st.push(v);
}
void solve()
{
    int n;
    cin >> n;
    vector<string> vs(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) cin >> vs[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (vs[i][j] == '1')
                adj[i].push_back(j);
    stack<int> st;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, adj, vis, st);
    while (!st.empty())
    {
        cout << st.top() + 1 << " ";
        st.pop();
    }
    cout << "\n";
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}