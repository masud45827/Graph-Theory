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
vector<int>g[100001];
int parent[100004], depth[100004];
int spt[100004][22];
int po(int x) {
  int c = 0;
  while (x > 0) {
    c++;
    x /= 2;
  }
  return c;
}
int query(int n, int p, int q) {
  int tmp, log, i;

  if (depth[p] < depth[q]) swap(p, q);

  //   log=1;
  // while(1) {
  //   int next=log+1;
  //   if((1<<next)>depth[p]) break;
  //   log++;
  // }
  log = po(depth[p]);

  for (i = log; i >= 0; i--)
    if (depth[p] - (1 << i) >= depth[q])
      p = spt[p][i];

  if (p == q)
    return p;

  for (i = log; i >= 0; i--)
    if (spt[p][i] != -1 && spt[p][i] != spt[q][i])
      p = spt[p][i], q = spt[q][i];

  return parent[p];
}
void dfs(int node, int p, int d) {
  parent[node] = p;
  depth[node] = d;
  for (int u : g[node]) {
    if (u == p) continue;
    dfs(u, node, d + 1);
  }
}
void sparse_table(int n) {
  memn(spt);
  int i, j;
  for (i = 1; i <= n; i++) spt[i][0] = parent[i];
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 1; i <= n; i++) {
      if (spt[i][j - 1] != -1) {
        spt[i][j] = spt[spt[i][j - 1]][j - 1];
      }
    }
  }
}
int main() {
  int t = 1, fac = 1;
  //scanf("%d", &t);
  while (t--) {
    int n, i, j, x, y;
    cin >> n;
    for (i = 1; i < n; i++) {
      cin >> x >> y;
      g[x].pb(y);
      g[y].pb(x);
    }
    dfs(1, 0, 0);
    sparse_table(n);
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << query(n, l, r) << endl;
    }
  }
}
