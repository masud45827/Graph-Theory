//https://codeforces.com/contest/1800/problem/G


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

const int N          = (int)2e5 + 5 ;
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
vector<ll>g[N + 3];
ll hash1[N + 3];
ll p = 200003;
ll dfs(ll node, ll par) {
  hash1[node] = 1;
  ll sz = g[node].size();
  for (ll x : g[node]) {
    if (x == par)  continue;
    dfs(x, node);
    ll y = ((hash1[x] + sz) * p) % mod;
    hash1[node] = (hash1[node] * y) % mod;
  }
}
ll dfs1(ll node, ll par) {
  set<ll>st;
  for (ll x : g[node]) {
    if (x == par) continue;
    if(st.find(hash1[x])==st.end()) st.insert(hash1[x]);
    else st.erase(st.find(hash1[x]));
  }
  if(st.empty()) return 1;
  if(st.size()>1) return 0;
  ll child=0;
  for(ll x:g[node]){
     if(x!=p&&hash1[x]==*st.begin()){
       child=x;
       break;
     }
  }
  return dfs1(child,node);
}

int main() {
  IOS;
  int test = 1, fac = 1;
  cin >> test;
  while (test--) {
    ll n, i, j, x, y;
    cin >> n;
    for(i=0;i<=n;i++) g[i].clear();
    for (i = 1; i < n; i++) {
      cin >> x >> y;
      g[x].pb(y);
      g[y].pb(x);
    }
    dfs(1, 0);
    if (dfs1(1, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

