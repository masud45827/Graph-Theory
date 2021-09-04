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
vector<int>g[100001];
int main()
{
  int t = 1, fac = 1;
  cin >> t;
  while (t--)
  {
    int n,i,j,x,y,m,u,v;
    cin>>n>>m;
    for(i=0;i<=n;i++) g[i].clear();
    map<int,int>mp;
    vector<int>v1;
    for(i=0;i<m;i++)
    {
     cin>>u>>v;
     g[u].pb(v);
     mp[v]++;
    }
      queue<int>q;
    for(i=1;i<=n;i++)
    {
      if(mp[i]==0) q.push(i);
    }
    while(q.size())
    {
      u=q.front();
      v1.pb(u);
      q.pop();
        for(auto v:g[u])
        {
          mp[v]--;
          if(mp[v]==0) q.push(v);
        }
    }
    if(v1.size()!=n) 
      {
         cout<<"found cycle"<<endl;
         continue;
      }
    for(auto x:v1) cout<<x<<endl;
  }
}
