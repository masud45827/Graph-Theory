#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  int t = 1, fac = 1;
  cin >> t;
  while (t--)
  {
      int n,m,i,j,x,y,u,v,k;
      cin>>n;
      int dis[n+2][n+2];
      for(u=1;u<=n;u++)
      {
        for(v=1;v<=n;v++) cin>>dis[u][v];
      }
     for(int mid=1;mid<=n;mid++) 
      {
        for(u=1;u<=n;u++)
        {
            for(v=1;v<=n;v++)
            {
                 dis[u][v]=min(dis[u][v],dis[u][mid]+dis[mid][v]);
            }
        }
      }
      int q;
      cin>>q;
      ll ans=0;
      while(q--)
      {
        int l,r;
        cin>>l>>r;
       ans+=dis[l][r];
      }
     printf("Case #%d: %lld\n",fac,ans);
     fac++;
    
  }
}
