#include <bits/stdc++.h>
using namespace std;
 int main()
{
    long n, a, b, c;
    cin >> n >> a >> b >> c;
    long MIN, MID, MAX;
    if (a > b && c > b)
    {
        MIN = b;
        MID = min(a, c);
        MAX = max(a, c);
    }
    else if (b > a && c > a)
    {
        MIN = a;
        MID = min(b, c);
        MAX = max(b, c);
    }
    else if (a > c && b > c)
    {
        MIN = c;
        MID = min(a, b);
        MAX = max(a, b);
    }
    long nMIN = n / MIN;
    long nMID = n / MID;
    long nMAX = n / MAX;
    // 5  5  3  2
    //    1  1  2
    //    0  2  3
     // 11  9     3     2
    // n   MAX   MID   MIN
    //     1     3     5
    //     nMAX  nMID  nMIN
    //     2     2     1
     // 7  5  5  2
    //    1  1  3
    //    2  2  1
    // cout<<MIN<<" "<<MID<<" "<<MAX<<"\n";
    // cout<<nMIN<<" "<<nMID<<" "<<nMAX<<"\n";
    float k;
    long maximum = INT_MIN;
    for (int i = nMID; i >= 0; i--)
    {
        for (int j = nMAX; j >= 0; j--)
        {
            k = (floor)((n - i * MID - j * MAX)) / MIN;
            if (floor(k) == ceil(k))
                if (i + j + k > maximum)
                    maximum = i + j + k;
        }
    }
    cout << maximum;
}