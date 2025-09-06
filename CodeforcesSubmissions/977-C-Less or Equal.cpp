#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
        if(k == 0 && arr[0] == 1)
    {
        cout<<-1;
        return 0;
    }
    if(n == k)
    {
        cout<<arr[k-1];
        return 0;
    }
    if((arr[k-1] == arr[k]) && k != 0)
    {
        cout<<-1;
        return 0;
    }
    else
        cout<<arr[k]-1;
}