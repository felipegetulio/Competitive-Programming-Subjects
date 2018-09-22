using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define i64 long long
#define MAXN 19
#define vi vector<int>
#define vii vector<ii>
#define ii pair<int, int>
#define pb push_back
#define eb emplace_back
#define oo 1000000000

bitset<500> qrcodes[MAXN], aux;
int adj[MAXN][MAXN];
int memo[MAXN][1<<MAXN];
int n, a;

void createGraph(){
	int w;

	for(int i=0; i<n; ++i){
		for(int j=i+1; j<=n; ++j){
			aux = qrcodes[i] ^ qrcodes[j];
			w = aux.count();
			adj[i][j] = adj[j][i] = w;
		}
	}

	for(int i=1; i<=n; ++i){
		adj[i][0] = a;
	}
}

int tsp(int u, int bitmask){

	if((bitmask>>1) == (1<<n)-1){
		return 0;
	}

	if(~memo[u][bitmask]){
		return memo[u][bitmask];
	}

	int ans = oo;

	if(u != 0){
		ans = min(ans, a + tsp(0, bitmask));
	}

	for(int v=1; v<=n; ++v){
		if(!(bitmask & (1<<v))){
			ans = min(ans, adj[u][v] + tsp(v, bitmask | (1<<v)));
		}
	}

	return memo[u][bitmask] = ans;
}

int main(){_
	char num;

	cin >> n >> a;

	for(int i=1; i<=n; ++i){
		for(int j=0; j<441; ++j){
			cin >> num;
			qrcodes[i][j] = (num == '1');
		}
	}

	createGraph();

	for(int i=0; i<=n; ++i){
		for(int j=0; j<(1<<n); ++j){
			memo[i][j] = -1;
		}
	}

	cout << tsp(0, 1) << endl;


    return 0;
}
