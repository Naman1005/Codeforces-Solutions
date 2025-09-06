#include <bits/stdc++.h>
using namespace std;
void solve(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        cout << (x1 + y2 - y1) << " " << y1 << " " << (x2 + y2 - y1) << " " << y2;
        return;
    }
    if (y1 == y2)
    {
        cout << x1 << " " << (y1 + x2 - x1) << " " << x2 << " " << (y2 + x2 - x1);
        return;
    }
    if ((x2 - x1 == y2 - y1) || (x2 - x1 == y1 - y2))
    {
        cout << x1 << " " << y2 << " " << x2 << " " << y1;
        return;
    }
    cout<<-1;
}
int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    solve(x1, y1, x2, y2);
}