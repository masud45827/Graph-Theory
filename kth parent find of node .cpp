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
int depth[200004], st[200004], end1[200005],parent[200004];
vector<int>g[200004];
int d = 0;
int spt[100004][22];
int query(int p, int d)
{
	int tmp, log, i;
	for (i = 21; i >= 0; i--) {
		if(d-(1<<i)>=0){
			p = spt[p][i];
			d-=(1<<i);
		}
	}
	return p;
}
void dfs(int node, int p, int d)
{
	parent[node] = p;
	depth[node] = d;
	for (int u : g[node])
	{
		if (u == p) continue;
		dfs(u, node, d + 1);
	}
}
void sparse_table(int n)
{
	memn(spt);
	int i, j;
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
	int test = 1, fac = 1;
	//scanf("%d", &test);
	while (test--) {
		int n, i, j, x, y, q, u, v;
		cin >> n >> q;
		for (i = 1; i < n; i++) {
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		depth[1] = 0;
		dfs(1, 0,0);
		sparse_table(n);
		vector<int>g1[n + 4];
		while (q--) {
			int node,nth;
			cin>>node>>nth;
			 cout<<query(node,nth)<<endl;
		}
	}
	return 0;
}

