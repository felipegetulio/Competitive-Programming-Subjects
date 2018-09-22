#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100003
#define MAX_VIS 2*MAXN-1
#define LOGN 17
#define visited 1
#define unvisited -1
#define limpa() for(int i=0; i<n; i++) adj[i].clear();

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii adj[MAXN];
int vis[MAX_VIS], firstOcur[MAXN], idx;
int mat[MAX_VIS][LOGN];
ll dist[MAX_VIS];
vi num;


void dfs(int u, ll length){
	num[u] = visited;
	firstOcur[u] = idx;
	vis[idx] = u;
	dist[idx++] = length;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i].first;
		ll w = adj[u][i].second;
		if(num[v] == unvisited){
			dfs(v, length+w);
			vis[idx] = u;
			dist[idx++] = length;
		}
	}
}

void preProcess(int n){
	idx = 0;
	num.assign(n, unvisited);
	dfs(0, 0);

	for(int i=0; i<idx; i++)
		mat[i][0] = i;
	
	for(int j=1; (1<<j)<=idx; j++)
		for(int i=0; i+(1<<j)-1 < idx; i++){
			if(dist[mat[i][j-1]] < dist[mat[i + (1<<(j-1))][j-1]])
				mat[i][j] = mat[i][j-1];
			else mat[i][j] = mat[i + (1<<(j-1))][j-1];	
		}
}

int rmq(int i, int j){
	if(i>j){ i^=j; j^=i; i^=j; }
	int k = log2(j-i+1);
	return (dist[mat[i][k]] < dist[mat[j-(1<<k)+1][k]]? mat[i][k] : mat[j-(1<<k)+1][k]);
}

ll distancia(int u, int v){
	return dist[firstOcur[u]] + dist[firstOcur[v]] - 2*dist[rmq(firstOcur[u], firstOcur[v])];
}

int main(){_
	int u, v, n, m, q, s, t;
	ll w;
	while(scanf("%d",&n) && n){
		limpa();
		for(u=1; u<n; u++){
			scanf("%d %lld",&v,&w);
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));	
		}
		preProcess(n);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&s,&t);
			printf("%lld%c",distancia(s, t),(q?' ':'\n'));
		}
	}
	return 0;
}
