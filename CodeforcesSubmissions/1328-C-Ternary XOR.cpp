#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     string x;
     int t;
     cin >> t;
     while (t--)
     {
          cin >> n;
          cin >> x;
          string a = "";
          string b = "";
          bool flag = false;
          for (int i = 0; i < n; i++)
          {
               if (flag)
               {
                    a += '0';
                    b += x[i];
               }
               else
               {
                    if (x[i] == '2')
                    {
                         a += '1';
                         b += '1';
                    }
                    else if (x[i] == '1')
                    {
                         a += '1';
                         b += '0';
                         flag = true;
                    }
                    else if (x[i] == '0')
                    {
                         a += '0';
                         b += '0';
                    }
               }
          }
           cout << a << "\n";
          cout << b << "\n";
     }
}