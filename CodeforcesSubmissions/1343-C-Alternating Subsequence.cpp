#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long count, max_in_group, t, n, sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // vector<long long> ele;
        int ele[n];
        for (int i = 0; i < n; i++)
        {
            // long long m;
            // cin >> m;
            // ele.push_back(m);
            cin>>ele[i];
        }
        sum = 0;
        max_in_group = ele[0];
        for (int i = 0; i < n - 1; i++)
        {
            if ((ele[i] > 0 && ele[i + 1] > 0) || (ele[i] < 0 && ele[i + 1] < 0))
            {
                if (max_in_group < ele[i + 1])
                    max_in_group = ele[i + 1];
            }
            else if ((ele[i] > 0 && ele[i + 1] < 0) || (ele[i] < 0 && ele[i + 1] > 0))
            {
                sum += max_in_group;
                max_in_group = ele[i + 1];
            }
        }
        sum += max_in_group;
        cout << sum << "\n";
    }
}