using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define _a first
#define _b second
#define vi vector<int>
#define vii vector<ii>
#define _v _a
#define _w _b
#define _e _b
#define pb push_back
#define oo 1000000000
#define MAXN 10004
#define MAXK 102
#define isInMap(_map, u, v) (_map.find(u) != _map.end() && _map[u].find(v) != _map[u].end())
#define vert(v, e) (v*MAXK + e)

unordered_map<int, unordered_map<int, int>> path;
vii adj[MAXN];
vii state[MAXN*MAXK];
vi dist;

ii toState(int n){
	ii s;
	s._v = n/MAXK;
	s._e = n%MAXK;
	return s;
}

void dijkstra(int s, int n){
	int u, v, w, d;
	ii front;
	priority_queue<ii, vii, greater<ii> > pq;

	dist.assign(n+1, oo);
	dist[s] = 0;
	pq.push(ii(dist[s], s));

	while(!pq.empty()){
		front = pq.top(); pq.pop();

		d = front._a;
		u = front._b;

		if(d > dist[u])
			continue;

		for(int i=0; i<state[u].size(); ++i){
			v = state[u][i]._v;
			w = state[u][i]._w;

			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

void createGraph(int s, int d){
	int u, v, e, w, su, sv;
	ii front;
	queue<ii> que;
	unordered_map<int, unordered_map<int, int>> visEdges;

	que.push(ii(s, 0));

	while(!que.empty()){
		ii front = que.front(); que.pop();
		u = front._v;
		e = front._e;

		if(u == d)
			continue;

		su = vert(u, e);
		
		for(int i=0; i<adj[u].size(); ++i){
			v = adj[u][i]._v;
			w = adj[u][i]._w;

			if(!isInMap(visEdges, u, v)){
				sv = isInMap(path, u, v) ? vert(v, e) : vert(v, e+1);
				state[su].pb(ii(sv, w));
				que.push(toState(sv));
				visEdges[u][v] = 1;
			}
		}
	}
}

// void dfs(int u){

// 	ii p = toState(u);

// 	cout << "(" << p._v << ", " << p._e << ", " << dist[u] << ")" << endl;

// 	vis[u] = 1;

// 	for(int i=0, v, w; i<state[u].size(); ++i){
// 		v = state[u][i]._v;
// 		w = state[u][i]._w;

// 		if(!vis[v])
// 			dfs(v);
// 	}
// }

int main(){_
	int n, m, q, src, dest;
	int d, k, u, v, w;
	string ans[] = {"NAO", "SIM"};

	cin >> n >> m >> q >> src >> dest;
	cin >> u;

	do{
		cin >> v;
		path[u][v] = 1;
		u = v;
	}while(v != dest);

	while(m--){
		cin >> u >> v >> w;
		adj[u].pb(ii(v, w));
	}

	createGraph(src, dest);
	dijkstra(vert(src, 0), MAXN*MAXK);

	for(int i=0; i<MAXK; ++i){
		for(int j=i+1; j<MAXK; ++j){
			dist[vert(dest, i)] = min(dist[vert(dest, i)], dist[vert(dest, j)]);
		}
	}

	while(q--){
		cin >> k >> d;
		cout << ans[abs(dist[vert(dest, 0)] - dist[vert(dest, k)]) <= d] << endl;
	}

	return 0;
}