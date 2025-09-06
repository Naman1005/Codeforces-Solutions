#include <iostream>
using namespace std;
int
main ()
{
  string s;
  cin >> s;
  bool change = false;
  if (s.size() == 1)
  change = true;
  else
 {
   change = true;
   for (int i = 1; i < s.length (); i++)
  if (islower (s[i]))
    {
   change = false;
   break;
    }
 }
 if(change)
 {
     for(int i=0; i<s.size(); i++)
     if(islower(s[i]))
     cout<<(char)toupper(s[i]);
     else
     cout<<(char)tolower(s[i]);
 }
 else
 cout<<s;
}