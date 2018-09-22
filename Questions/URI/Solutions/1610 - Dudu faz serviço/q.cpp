#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 10005
#define WHITE -1
#define GRAY 0
#define BLACK 1
#define vi vector<int>
#define limpa(n) for(int i=1; i<=n; i++) adj[i].clear()

using namespace std;

vi num;
vi adj[MAXN];

bool dfs(int u){
    num[u] = GRAY;
    bool ans = false;
    for(int i=0, v; i<adj[u].size() && !ans; i++){
        v = adj[u][i];

        if(num[v] == WHITE)
            ans |= dfs(v);
        else if(num[v] == GRAY)
            return true;
    }
    num[u] = BLACK;
    return ans;
}

int main(){_
    int n, m, u, v, t;
    bool temCiclo;
    cin >> t;
    while(t--){
        temCiclo = false;
        cin >> n >> m;
        limpa(n);
        while(m--){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        num.assign(n+1, WHITE);
        for(u=1; u<=n && !temCiclo; u++)
            if(num[u] == WHITE)
                temCiclo |= dfs(u);
        cout << (temCiclo? "SIM":"NAO") << endl;
    }

    return 0;
}
