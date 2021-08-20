// #include<bits/stdc++.h>
// using namespace std;
// typedef     long long    ll;
// typedef     unsigned long long    ull;
// typedef     vector<int> vi;
// typedef     vector<long long> vl;
// typedef     pair<int, int>pi;
// typedef     pair<long long, long long>pl;
// #define F   first
// #define S   second
// #define pb  push_back
// #define     all(x)      x.begin() , x.end()
// #define mod 1000000007
// #define       FOR(i,a,b) for(i=a;i<=b;i++)
// #define     mem(a)      memset(a , 0 ,sizeof a)
// #define     memn(a)     memset(a , -1 ,sizeof a)
// vector<int>g[100005];
// int vis[100005],m,n;
// int par[100005];
// int f;
// void bfs(int x)
// {
//     par[x]=1;
//     vis[x]=1;
//      queue<int>q;
//      q.push(x);
//      int  u,v;
//       while(!q.empty())
//       {
//          u=q.front(); q.pop();
//          for(int v:g[u])
//          {
//            if(vis[v]==0)
//            {
//             if(par[u]==1) par[v]=2;
//             else par[v]=1;
//             q.push(v);
//             vis[v]=1;
//            }
//          }
//       }
// }
// int main()
// {
//   int t = 1, fac = 1;
//   //cin >> t;
//   while (t--)
//   {
//    int i,j,x,y,u,v;
//    cin>>n>>m;
//    pair<int,int>p[m+2];
//    for(i=0;i<m;i++)
//    {
//     cin>>u>>v;
//     g[u].pb(v);
//     g[v].pb(u);
//     p[i].F=u; p[i].S=v;
//    }
 
//    for(i=1;i<=n;i++)
//    {
//      if(vis[i]==0)
//      {
//         bfs(i);
//      }
//    }
//    for(i=0;i<m;i++)
//    {
//     if(par[p[i].F]==par[p[i].S])
//     {
//         cout<<"IMPOSSIBLE"<<endl;
//         return 0;
//     }
//    }
//    for(i=1;i<=n;i++) cout<<par[i]<<" ";
//     cout<<endl;
//   }
// }
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
int vis[100005], m, n;
int par[100005];
int f;
void bfs(int x)
{
    par[x] = 1;
    vis[x] = 1;
    queue<int>q;
    q.push(x);
    int  u, v;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        for (int v : g[u])
        {
            if (par[v] == par[u])  f=1;
            if (vis[v] == 0)
            {
                if (par[u] == 1) par[v] = 2;
                else par[v] = 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}
int main()
{
    int t = 1, fac = 1;
    //cin >> t;
    while (t--)
    {
        int i, j, x, y, u, v;
        cin >> n >> m;
        for (i = 0; i < m; i++)
        {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
      
        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                bfs(i);
            }
        }
          if (f)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        for (i = 1; i <= n; i++) cout << par[i] << " ";
        cout << endl;
    }
}
