#include <bits/stdc++.h>
using namespace std;
 void solve(long long a, long long b)
{
    long long l = (a * b) / __gcd(a, b);
    if(a == 1)
    {
        cout<<(b*b)<<"\n";
        return;
    }
    else if (l == b)
    {
        for(int i=2; i*i<=b; i++)
        {
            if(b%i == 0)
            {
                cout<<(b*i)<<"\n";
                return;
            }
        }
    }
    else
    {
        cout << l << "\n";
        return;
    }
}
 int main()
{
    long long t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        solve(a, b);
    }
}