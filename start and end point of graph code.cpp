//range  minimum value query
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
vector<ll>g[200001];
ll  a[200004], st[200004], end1[200004], d = 1;
ll sub[200004];
void dfs1(ll node,ll p) {
  sub[node] = a[node];
  for (ll u : g[node]) {
    if (u == p) continue;
    dfs1(u, node);
    sub[node] += sub[u];
  }
}
void dfs2(ll node, ll p) {
  st[node] = d;
  for (ll u : g[node]) {
    if (p == u) continue;
    d++;
    dfs2(u, node);
  }
  d++;
  end1[node] = d;
}
ll isancestor(ll u, ll v) {
  if (st[u] >= st[v] && end1[u] <= end1[v]) return 1;
  else return 0;
}
int main()
{
  int t = 1, fac = 1;
  scanf("%d", &t);
  while (t--)
  {
    d = 1;
    ll n, i, j, x, y;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 0; i <= n; i++) {
      g[i].clear();
      end1[i]=0;st[i]=0;
    }
    for (i = 1; i < n; i++)
    {
      cin >> x >> y;
      g[x].pb(y);
      g[y].pb(x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ll q;
    cin >> q;
    while (q--)
    {
      ll l, r, u, v;
      cin >> u >> v >> x;
       ll ans;
      if (isancestor(u, v) || isancestor(v, u)) ans=sub[x];
      else if(isancestor(x,u)||isancestor(x,v)) ans=sub[x];
      else {
        if (isancestor(u, x) && isancestor(v, x)) ans=sub[x];
        else if (isancestor(u, x)==0&& isancestor(v, x)==0) ans=sub[x];
        else {
          if (isancestor(u, x)) ans=(sub[x] - sub[u] + sub[v]);
          else ans=(sub[x] - sub[v] + sub[u]);
        }
      }
      cout<<ans<<" ";

    }
    cout << endl;

  }

}
