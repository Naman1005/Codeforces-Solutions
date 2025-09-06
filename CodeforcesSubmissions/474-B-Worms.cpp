#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n, m, key, l, r, mid;
    cin >> n;
    int arr[n];
    cin>>arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cin >> m;
    // 1   2   3   4   5   6   7   8   9
    // 1   3   6   10  15  21  28  36  45
    while (m--)
    {
        cin >> key;
        l = 0, r = n-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(key <= arr[mid] && (key>arr[mid-1] || mid < 1))
            {
                cout<<(mid+1)<<"\n";
                break;
            }
            if(key<arr[mid])
            {
                r = mid-1;
                continue;
            }
            if(key>arr[mid])
            {
                l = mid+1;
                continue;
            }
        }
    }
}