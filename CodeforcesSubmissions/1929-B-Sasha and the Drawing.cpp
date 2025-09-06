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
    ll t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n == 1)
            cout << 1 << "\n";
        // // else if(k <= ((4*n)-4))
        // // cout<<ceil(k/2.0)<<"\n";
        // // else
        // // {
        // //     if(k == ((4*n)- 2))
        // //     cout<<2*n<<"\n";
        // //     else
        // //     cout<<(2*n)-1<<"\n";
        // else if (k == ((4 * n) - 2))
        //     cout << 2 * n << "\n";
        // else if (k == ((4 * n) - 3))
        //     cout << (2 * n) - 1 << "\n";
        // else
        //     cout << ceil(k / 2.0) << "\n";
        else if(k == ((4*n)- 2))
        cout<<(k+2)/2<<"\n";
        else
        cout<<(k+1)/2<<"\n";
    }
}