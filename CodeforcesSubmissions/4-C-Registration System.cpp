#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string x;
    unordered_map<string, int> m;
    while (n--)
    {
        cin >> x;
        if (m[x] == 0)
            cout << "OK\n";
        else
            cout << x << m[x] << "\n";
        m[x] += 1;
    }
}