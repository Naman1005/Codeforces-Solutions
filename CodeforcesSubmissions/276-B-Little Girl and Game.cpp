#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    inp_out();
    string str;
    cin >> str;
    int n = str.length();
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++)
        m[str[i]] += 1;
    // for (auto k : m)
    //     cout << k.first << " " << k.second << "\n";
            int count = 0;
    for(auto k:m)
    if(k.second & 1)
    count++;
    if(!count)
    cout<<"First\n";
    else
    count&1?cout<<"First\n":cout<<"Second\n";
    // cout<<count<<"**\n";
}