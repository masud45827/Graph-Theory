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
vector<int>g[100005];
int vis[100005],parent[100005];
int e,s=-1;
int dfs(int v,int par)
{
   vis[v]=1;
   for(int u:g[v])
   {
    if(u==par) continue;
    if(vis[u]==0)
    {
      parent[u]=v;
      int ck=dfs(u,parent[u]);
      if(ck==1) return 1;
    }else
    {
      s=u; e=v;
      return 1;
    }
   }
   return 0;
}
int main()
{
   int n,i,j,m,u,v;
   cin>>n>>m;
   for(i=0;i<m;i++)
   {
           cin>>u>>v;
           g[u].pb(v);
           g[v].pb(u);
   }
   for(i=1;i<=n;i++)
   {
      if(vis[i]==0)
      {
        if(dfs(i,0)) break;
      }
   }
    if(s==-1) 
    {
      cout<<"IMPOSSIBLE"<<endl; return 0;
    }
    vi v1;
    v1.pb(s);
    for(v=e;v!=s;v=parent[v]) v1.pb(v);
      v1.pb(s);
    int l=v1.size();
    cout<<l<<endl;
     for(i=0;i<l;i++) cout<<v1[i]<<" ";
      cout<<endl;
}
