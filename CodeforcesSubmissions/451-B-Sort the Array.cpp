#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n;
    cin >> n;
    long arr[n];
    long brr[n];
    long crr[n];
    // INPUT
    for (long i = 0; i < n; i++)
    {
        cin >> arr[i];
        brr[i] = arr[i];
    }
    // SORTING
    sort(brr, brr + n);
    for (long i = 0; i < n; i++)
        crr[i] = brr[i];
    // Making brr
    bool f = true;
    for (long i = 0; i < n; i++)
    {
        brr[i] = arr[i] - brr[i];
        if (brr[i] && f)
            f = false;
    }
    if (f)
    {
        cout << "yes\n"
             << 1 << " " << 1;
        return 0;
    }
    // FINDING boundary limits of segment
    long i = 0, j = n - 1;
    for (long x = 0; x < n - 1; x++)
        if (brr[x])
        {
            i = x;
            break;
        }
    for (long x = n - 1; x > 0; x--)
        if (brr[x])
        {
            j = x;
            break;
        }
     long x = i + 1, y = j + 1;
    // SWAPPING
    long temp;
    while (i <= j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    // Checking
    bool flag = true;
    for (long i = 0; i < n; i++)
    {
        if(arr[i] != crr[i])
        {
            // cout<<arr[i]<<" "<<crr[i]<<"\n";
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "yes\n"
             << x << " " << y;
    else
        cout << "no\n";
}