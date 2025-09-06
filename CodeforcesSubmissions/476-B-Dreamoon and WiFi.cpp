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
ll fact(ll n)
{
    ll fac = 1;
    for (ll i = 2; i <= n; i++)
        fac *= i;
    return fac;
}
int cases(ll diff, ll q)
{
    ll i;
    for (i = 0; i <= q; i++)
        if (diff == q - 2 * i)
            break;
    int combinations = fact(q) / (fact(q - i) * fact(i));
    return combinations;
}
int main()
{
    inp_out();
    string a, b;
    char plus = '+';
    char minus = '-';
    cin >> a >> b;
    ll l = a.length();
    ll FinalPosA = 0, FinalPosB = 0, q = 0;
    for (ll i = 0; i < l; i++)
    {
        if (a[i] == plus)
            FinalPosA++;
        else if (a[i] == minus)
            FinalPosA--;
        if (b[i] == plus)
            FinalPosB++;
        else if (b[i] == minus)
            FinalPosB--;
        else
            q++;
    }
    ll diff = FinalPosA - FinalPosB;
    // cout << setprecision(20) << diff << " " << q << "\n";
    if (!q)
    {
        if (diff == 0)
            cout << setprecision(20) << 1 << "\n";
        else
            cout << setprecision(20) << 0 << "\n";
        return 0;
    }
    double prob;
    if (abs(diff) % 2 == q % 2)
    {
        prob = cases(diff, q) / (double)pow(2, double(q));
        cout << setprecision(20) << prob << "\n";
    }
    else
        cout << setprecision(20) << 0 << "\n";
}