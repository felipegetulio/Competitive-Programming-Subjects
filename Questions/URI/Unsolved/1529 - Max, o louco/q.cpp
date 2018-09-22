#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 12
#define MAXC 1002
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define limpa(grafo,n) for(int i=1; i<=n; i++) grafo[i].clear()

using namespace std;

vi vis;
vii adj[MAXN*MAXC], aux[MAXN];
int estados[MAXN][MAXC];
int custos[MAXN];
int nadj;

void init(int n){
    for(int i=1; i<=n; i++)
        for(int j=0; j<MAXC; j++)
            estados[i][j] = -1;
}


void dfs(int u, int gas, int c){
    int uadj = estados[u][gas] = nadj++;
    vis[u] = 1;
    for(int i=0, v, w, vadj, wadj; i<aux[u].size(); i++){
		v = aux[u][i].first;
		w = aux[u][i].second;

        if(vis[v] == -1)
            if(gas >= w){
                if(estados[v][gas-w] == -1)
                    dfs(v, gas-w);
                vadj = estados[v][gas-w];
                wadj = 0;
                adj[uadj].push_back(ii(vadj, wadj));
            }
            else{
                if(estados[u][w] == -1)
                    dfs(u, w);
                vadj = estados[u][w];
                wadj = custos[u]*(w-gas);
                adj[uadj].push_back(ii(vadj, wadj));
            }

	}

}

int main(){_
    int n, m, c, u, v, w;

    while(cin >> n >> m >> c && (n||m||c)){
        limpa(aux, n);
        limpa(adj, (n+1)*(c+1));
        init(n);
        nadj = 0;
        while(m--){
            cin >> u >> v >> w;
            aux[u].push_back(ii(v,w));
            aux[v].push_back(ii(u,w));
        }

    }

    return 0;
}
