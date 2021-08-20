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
vector<pair<int, pi>>g;
int parent[100005];
int find(int s) {
  if (parent[s] == s)return s ;
  return parent[s] = find(parent[s]) ;
}
int fun(int n)
{
  sort(all(g));

  for (int i = 0; i <= n; i++) parent[i] = i;
  int u, v, w, edge = 0, res = 0;
  for (auto p : g)
  {
    w = p.F; u = p.S.F; v = p.S.S;
    u = find(u); v = find(v);
    if (u != v)
    {
      res += w;
      parent[u] = v;
      edge++;
      if (edge == (n - 1)) return res;
    }

  }
}
int main()
{
  int t = 1, fac = 1;
//  scanf("%d",&t);
  while (1)
  {
    int n, m, i, j, x, y, u, v, w;
    g.clear();
    scanf("%d %d", &n, &m);
    if ((n + m) == 0) break;
    for (i = 0; i < m; i++)
    {
      scanf("%d %d %d", &u, &v, &w);
      g.pb({w, {u, v}});
    }
    printf("%d\n", fun(n));
  }
}
