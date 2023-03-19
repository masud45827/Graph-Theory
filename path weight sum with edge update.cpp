//https://atcoder.jp/contests/abc294/tasks/abc294_g
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define setpr(x) cout<<setprecision(x)<<fixed
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
template <typename T> inline void Int(T &a) {
  bool minus = false; a = 0; char ch = getchar();
  while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
  if (ch == '-') minus = true; else a = ch - '0';
  while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
  if (minus)a *= -1 ;
}
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

const int N          = (int)3e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
vector<ll>g[2*N + 2];
ll parent[2*N + 2], depth[2*N + 2];
ll spt[N + 2][30];
ll tr[2 * N + 5];
ll start[2*N + 2], endd[2*N + 2];
ll tm1 = 0;
ll  po(ll x) {
  ll c = 0;
  while (x > 0)
  {
    c++;
    x /= 2;
  }
  return c;
}
void update(ll i, ll x) {
  while (i <= 2 * N) {
    tr[i] += x;
    i += (i & (-i));
  }
}
ll query(ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += tr[x];
    x -= (x & (-x));
  }
  return sum;
}
ll lca( ll p, ll q)
{
  ll tmp, log, i;

  if (depth[p] < depth[q]) swap(p, q);
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
void dfs(ll node, ll p, ll d) {
  parent[node] = p;
  depth[node] = d;
  start[node] = ++tm1;
  for (ll u : g[node])
  {
    if (u == p) continue;
    dfs(u, node, d + 1);
  }
  endd[node] = ++tm1;
}
void sparse_table(ll n)
{
  memn(spt);
  ll i, j;
  for (i = 1; i <= n; i++) spt[i][0] = parent[i];
  for (j = 1; (1 << j) <= n; j++)
  {
    for (i = 1; i <= n; i++)
    {
      if (spt[i][j - 1] != -1) {
        spt[i][j] = spt[spt[i][j - 1]][j - 1];
      }
    }
  }
}

int main() {
  ll test = 1, fac = 1;
  //cin >> test;
  while (test--) {
    ll n, i, j, x, y, w;
    cin >> n;
    ll a[n + 2], b[n + 2], we[n + 2];
    for (i = 1; i < n; i++){
      cin >> x >> y >> w;
      a[i] = x; b[i] = y; we[i] = w;
      g[x].pb(y);
      g[y].pb(x);
    }
    dfs(1, 1, 1);
    sparse_table(n);
    for (i = 1; i < n; i++) {
      x = a[i]; y = b[i]; w = we[i];
      ll lc = lca(x, y);
      ll node = x;
      if (lc == x) node = y;
      else node = x;
      update(start[node], w);
      update(endd[node], -w);
    }
    ll q;
    cin >> q;
    while (q--) {
      ll t;
      cin >> t;
      if (t == 1) {
        cin >> i >> w;
        x = a[i]; y = b[i];
        ll lc = lca(x, y);
        ll node = x;
        if (lc == x) node = y;
        else node = x;
        update(start[node], -we[i]);
        update(endd[node], we[i]);
        update(start[node], w);
        update(endd[node], -w);
        we[i]=w;
      } else {
        cin >> x >> y;
        ll lc = lca(x, y);
        ll dis = query(start[x]) + query(start[y]);
        dis = dis - 2LL * query(start[lc]);
        cout << dis << endl;
      }
    }

  }
  return 0;
}

