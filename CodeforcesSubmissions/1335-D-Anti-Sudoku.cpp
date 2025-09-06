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
    char c;
    int arr2[9][9];
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                cin >> c;
                arr2[i][j] = c - '1' + 1;
            }
        arr2[0][0] = arr2[1][0];
        arr2[1][3] = arr2[2][3];
        arr2[2][6] = arr2[0][6];
        arr2[3][1] = arr2[4][1];
        arr2[4][4] = arr2[5][4];
        arr2[5][7] = arr2[2][7];
        arr2[6][2] = arr2[7][2];
        arr2[7][5] = arr2[8][5];
        arr2[8][8] = arr2[6][8];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << arr2[i][j];
            cout << "\n";
        }
        // cout<<"\n";
    }
}