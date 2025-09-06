#include <bits/stdc++.h>
using namespace std;
int main()
{
    int even, odd, n, x, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int arr[n];
        even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
                odd++;
            else
                even++;
        }
        if (odd == 0)
        {
            cout << "No\n";
            continue;
        }
        // cout<<"EVEN: "<<even<<", ODD: "<<odd<<"\n";
        if ((odd & 1) == 0)
            odd -= 1;
        if((even == 0)&&((x&1) == 0))
        {
            cout<<"No\n";
            continue;
        }
        // cout<<"EVEN: "<<even<<", ODD: "<<odd<<"\n";
        if (odd + even >= x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}