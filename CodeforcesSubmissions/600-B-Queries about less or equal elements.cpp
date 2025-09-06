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
    ll a, b, l, h, mid, index;
    cin >> a >> b;
    ll arr[a];
    for (ll i = 0; i < a; i++)
        cin >> arr[i];
    ll target[b];
    for (ll i = 0; i < b; i++)
        cin >> target[i];
     sort(arr, arr + a);
     vector<ll> keys, values;
    ll j = 0;
    keys.push_back(arr[j]);
    values.push_back(1);
    for (ll i = 1; i < a; i++)
    {
        if (keys[j] == arr[i])
            values[j]++;
        else
        {
            j++;
            keys.push_back(arr[i]);
            values.push_back(1);
        }
    }
    for (ll i = 1; i < values.size(); i++)
        values[i] += values[i - 1];
    // for (ll i = 0; i < keys.size(); i++)
    // {
    //     cout << keys[i] << " : " << values[i] << "\n";
    // }
     for (ll i = 0; i < b; i++)
    {
        l = 1;
        h = keys.size() - 1;
        index = -1;
        if (target[i] >= keys[h])
            index = h;
        else
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                // cout << "**" << mid << "**"
                //      << "\n";
                if ((keys[mid - 1] <= target[i]) && (target[i] < keys[mid]))
                {
                    index = mid - 1;
                    break;
                }
                else if (target[i] > keys[mid - 1])
                {
                    l = mid + 1;
                    continue;
                }
                else if (target[i] < keys[mid])
                {
                    h = mid - 1;
                    continue;
                }
            }
        if (index == -1)
            cout << 0 << " ";
        else
            cout << values[index] << " ";
        // cout << "\n";
    }
}