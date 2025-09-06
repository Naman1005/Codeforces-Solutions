#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t, n;
    string s;
    char j;
    cin >> t;
    while (t--)
    {
        s = "";
        unordered_map<char, int> m1;
        for (char i = 'a'; i <= 'z'; i++)
        {
            m1[i] = 0;
        }
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
        {
            for (j = 'a'; j <= 'z'; j++)
            {
                if (m1[j] == arr[i])
                {
                    m1[j]++;
                    break;
                }
            }
            s += j;
        }
        cout << s << "\n";
    }
}