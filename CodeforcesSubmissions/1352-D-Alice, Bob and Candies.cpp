#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
#define sortv(v) sort(v.begin(), v.end())
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
ll truncMod(double a, double b)
{
    return a - (b * (floor(a / b)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, left, right, prev, a, b, temp_a, temp_b, temp,moves;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll arr[n];
        left = 1;
        right = n - 1;
        fro(i, 0, n - 1) cin >> arr[i];
        prev = arr[0];
        moves = 1;
        a = prev, b = temp_a = temp_b = 0;
        while(left<=right)
        {
            while((temp_b<=prev) && (left<=right))
            {
                temp_b += arr[right];
                right--;
            }
            if(temp_b)moves++;
            prev = temp_b;
            b += temp_b;
            temp_b = 0;
            while((temp_a<=prev) && (left<=right))
            {
                temp_a += arr[left];
                left++;
            }
            if(temp_a)moves++;
            prev = temp_a;
            a += temp_a;
            temp_a = 0;
        }
        cout<<moves<<" "<<a<<" "<<b<<"\n";
    }
}