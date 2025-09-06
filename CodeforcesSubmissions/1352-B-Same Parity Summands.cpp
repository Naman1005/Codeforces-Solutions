#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, t;
    cin >> t;
    long n;
    while (t--)
    {
        cin >> n >> k;
        if(n<k)
        {
            cout<<"NO\n";
            continue;
        }
        if (n & 1)
        {
            if (k & 1)
            {
                cout<<"YES\n";
                for (int i = 1; i < k; i++)
                    cout << 1 << " ";
                cout << (n - k + 1) << "\n";
            }
            else
                cout << "NO\n";
        }
        else
        {
            if (k & 1)
            {
                if (k > (n / 2))
                    cout << "NO\n";
                else
                {
                    cout<<"YES\n";
                    for (int i = 1; i < k; i++)
                        cout << 2 << " ";
                    cout << (n - (2 * k) + 2) << "\n";
                }
            }
            else
            {
                cout<<"YES\n";
                for (int i = 1; i < k; i++)
                    cout << 1 << " ";
                cout << (n - k + 1) << "\n";
            }
        }
    }
}