#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (((1 & arr[0]) == (1 & arr[1])) && ((1 & arr[1]) == (1 & arr[2])))
    {
        for (int i = 3; i < n; i++)
        {
            if ((1 & arr[i]) != (1 & arr[i - 1]))
            {
                cout << (i + 1);
                return 0;
            }
        }
    }
    else
    {
        if ((1 & arr[0]) == (1 & arr[1]))
            cout << 3;
        else if ((1 & arr[1]) == (1 & arr[2]))
            cout << 1;
        else if ((1 & arr[2]) == (1 & arr[0]))
            cout << 2;
    }
}