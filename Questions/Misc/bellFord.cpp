#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 1004
#define MAXM 2004
#define inf 1000000000
#define limpa(n) for(int i=0; i<n; i++) adj[i].clear()

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii adj[MAXN];
vi dist;

bool bell(int n){
	int u, v, w, s=0;

	dist.assign(n, inf);
	dist[s] = 0;
	
	for(int i=0; i<n-1; i++)
		for(u=0; u<n; u++){
			for(int j=0; j<adj[u].size(); j++){
				v = adj[u][j].first;
				w = adj[u][j].second;
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	
	for(u = 0; u<n; u++){
		for(int i=0, v, w; i<adj[u].size(); i++){
			v = adj[u][i].first;
			w = adj[u][i].second;
			if(dist[u] + w < dist[v])
				return true;
		}
	}
	return false;
}



int main(){_
	int n, m, u, v, w, t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		limpa(n);
		while(m--){
			cin >> u >> v >> w;
			adj[u].push_back(ii(v, w));
		}
		
		cout << (bell(n)? "":"not ") << "possible" << endl;
	
	}
	
	return 0;
	
}

