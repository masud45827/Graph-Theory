#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
//typedef     unsigned long long    ull;
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
#ifdef LOCAL
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ' ;
  err(++it, args...);
}
#else
#define error(args...)
#endif
vector<int>g[200004];
int vis[200005], color[200005];
bool dfs(int node, int c) {
  vis[node] = 1;
  color[node] = c;
  for (int u : g[node]) {
    if (vis[u] == 0) {
      bool res = dfs(u, c ^ 1);
      if (res == false) return false;
    } else {
      if (color[node] == color[u]) return false;
    }
  }
  return  true;
}
int main() {
  int test = 1, fac = 1;
  //scanf("%d", &test);
  while (test--) {
    int n, i, x, y, u, v, m;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    int f = 1;
    for (i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        bool ans = dfs(i, 0);
        if (ans == false) {
          f = 0; break;
        }
      }
    }
    if (f) cout << "Graph is bipartite" << endl;
    else cout << "Graph is not bipartite" << endl;
  }
  return 0;
}

