#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 10004
#define MAXM 100005

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii adj[MAXN];
vi dist;


struct edge{
	int u, v, w;
};

int tam[MAXN], pai[MAXN];
edge e[MAXM];

int id(int n){
	return n == pai[n]? n: pai[n] = id(pai[n]);
}

bool cmp(edge a, edge b){
	return (a.w <= b.w);
}

void join(int a, int b){
	a = id(a); b = id(b);
	if(a == b) return;
	if(tam[a] < tam[b]) swap(a, b);
	pai[b] = a;
	tam[a] += tam[b];
}


int kruskal(int n, int m){
	sort(e, e+m, cmp);
	int u, v;
	int mst = 0, qntA = 0;
	for(int i=0; i<m ; i++){
		u = id(e[i].u);
		v = id(e[i].v);
		
		if(u != v){
			mst += e[i].w;
			join(u,v);
			qntA++;
		}
	}
	return mst;
}



void init(int n){
	for(int i=1; i<=n; i++){
		tam[i] = 1;
		pai[i] = i;
	}

}

int main(){_
	int n, m, u, v, w;
	
	cin >> n >> m;
	init(n);
	for(int i=0; i<m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;	

	cout << kruskal(n , m) << endl;
	return 0;
}
