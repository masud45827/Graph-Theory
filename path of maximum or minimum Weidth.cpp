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
const int inf = (int) 2e9 + 5;
const ll  Inf = (ll) 2e18 + 5;
const int N   = (int) 2e5 + 5;
const int M   = (int) 18;
vector<pi>g1[N];
int par[M][N], mn[M][N], mx[M][N], dep[N];
void dfs(int u, int p = -1, int d = 0) {
  dep[u] = d;
  for (int i = 1; i < M; i++) {
    par[i][u] = par[i - 1][par[i - 1][u]];
    mx[i][u] = max(mx[i - 1][u], mx[i - 1][par[i - 1][u]]);
    mn[i][u] = min(mn[i - 1][u], mn[i - 1][par[i - 1][u]]);
  }
  for (auto x : g1[u]) {
    int v = x.F, w = x.S;
    if (p != v) {
      par[0][v] = u, mx[0][v] = mn[0][v] = w;
      dfs(v, u, d + 1);
    }
  }
}

int maximum_edge(int u, int v) {
  int ans = INT_MIN;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = M - 1; i >= 0 and u != v; i--) {
    if (dep[par[i][u]] >= dep[v]) {
      ans = max(ans, mx[i][u]);
      u = par[i][u];
    }
  }
  if (u == v) return ans;
  for (int i = M - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      ans = max(ans, max(mx[i][u], mx[i][v]));
      u = par[i][u], v = par[i][v];
    }
  }
  return max(ans, max(mx[0][u], mx[0][v]));
}

int minimum_edge(int u, int v) {
  int ans = INT_MAX;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = M - 1; i >= 0 and u != v; i--) {
    if (dep[par[i][u]] >= dep[v]) {
      ans = min(ans, mn[i][u]);
      u = par[i][u];
    }
  }
  if (u == v) return ans;
  for (int i = M - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      ans = min(ans, min(mn[i][u], mn[i][v]));
      u = par[i][u], v = par[i][v];
    }
  }
  return min(ans, min(mn[0][u], mn[0][v]));
}
int main()
{
  int t = 1, fac = 1;
//  scanf("%d",&t);
  while (t--)
  {
    int n, m, i, j, x, y, u, v, w, q;
    scanf("%d %d %d", &n, &m, &q);
    for (i=0;i<m;i++) {
      cin>>u>>v>>w;
      g1[u].push_back({v, w});
      g1[v].push_back({u, w});
    }
    par[0][1] = 1;
    mx[0][1] = 0;
    mn[0][1] = inf;
    dfs(1);
    while (q--) {
      cin >> u >> v >> w;
      x = maximum_edge(u, v);
      cout << x << endl;
    }

  }
}
