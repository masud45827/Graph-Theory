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
vector<int>g[100004];
vector<pair<int, int>>vt;
int vis[100005], in[100004], low[100005];
int time1 = 0;
void dfs(int node, int p) {
  vis[node] = 1;
  in[node] = low[node] = time1;
  time1++;
  for (int u : g[node]) {
    if (u == p) continue;
    if (vis[u] == 1) {
      low[node] = min(low[node], in[u]);
    } else {
      dfs(u, node);
      if (in[node] < low[u]) {
        vt.pb({node, u});
      }
      low[node] = min(low[node], low[u]);
    }
  }
}
int main() {
  int t = 1, fac = 1;
//  scanf("%d", &t);
  while (t--) {
    int n, i, j, x, y, m, u, v;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    for (i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        dfs(i, -1);
      }
    }
    for (i = 0; i < vt.size(); i++) cout << vt[i].F << " " << vt[i].S << endl;
  }
}
