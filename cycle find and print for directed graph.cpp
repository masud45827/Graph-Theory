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
int dfs(int v) {
     vis[v] = 1;
    for (int u : g[v]) {
        if (vis[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return 1;
        } else if (vis[u] == 1) {
            e= v;
            s = u;
            return 1;
        }
    }
    vis[v] = 2;
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
   }
   for(i=1;i<=n;i++)
   {
      if(vis[i]==0)
      {
        if(dfs(i)) break;
      }
   }
  // cout<<s<<" "<<e<<endl;
    if(s==-1) 
    {
      cout<<"IMPOSSIBLE"<<endl; return 0;
    }
    vi v1;
    for(v=e;v!=s;v=parent[v]) v1.pb(v);
      reverse(all(v1));
      v1.pb(s);
    int l=v1.size()+1;
    cout<<l<<endl;
    cout<<s<<" ";
     for(i=0;i<l-1;i++) cout<<v1[i]<<" ";
      cout<<endl;
}
