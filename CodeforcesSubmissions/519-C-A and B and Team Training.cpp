#include <iostream>
using namespace std;
int main()
{
 int n,m,cnt = 0;
 cin>>n>>m;
 while(n+m>2 && n>0 && m>0)
 {
  if(n>m) cnt++,m--,n-=2;
  else cnt++,n--,m-=2;
 }
 cout<<cnt<<"\n";
}