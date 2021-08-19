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
  //cin >> t;
  while (t--)
  {
       int n,i,j,x,y,m,s,u,v,w;
       cin>>n>>m;
        int edge_u[m+2],edge_v[m+2],cost[m+2];
        vector<int>d(n+2,1e9);
        for(i=0;i<m;i++) cin>>edge_u[i]>>edge_v[i]>>cost[i];
        cin>>s;
        d[s]=0;
        int neg_cl=0,update=0;
       for(i=0;i<n;i++)
       {
          update=0;
           for(j=0;j<m;j++)
           {
              u=edge_u[j]; v=edge_v[j];  w=cost[j];
              if(d[u] != 1e9&&d[u]+w<d[v])
              {
                update=1;
                d[v]=d[u]+w;
                  if(i==(n-1)) neg_cl=1;
              }
           }
           if(!update) break;
       }
       if(neg_cl) cout<<"negative cycle detected"<<endl;
       else
       {
        for(i=1;i<=n;i++) cout<<i<<" "<<d[i]<<endl;
       }
  }
}
