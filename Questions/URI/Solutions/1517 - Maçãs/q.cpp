#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXK 1002
#define MAXN 21
#define MAXM 21

using namespace std;

struct Position{
    int i, j;
};

struct Maca{
    Position pos;
    int tempo;
};

int n, m, k, maiorTempo;
Maca macas[MAXK];
int memo[MAXN][MAXM][MAXK<<1];

int distancia(Position a, Position b){
    return max(abs(a.i - b.i), abs(a.j - b.j));
}

int qntMacas(Position posiAtual, int indMaca, int tempo){
    if(indMaca == k) return 0;

    if(memo[posiAtual.i][posiAtual.j][tempo] != -1)
        return memo[posiAtual.i][posiAtual.j][tempo];

    if(macas[indMaca].tempo - tempo >= distancia(posiAtual, macas[indMaca].pos))
        return memo[posiAtual.i][posiAtual.j][tempo] = max(1 + qntMacas(macas[indMaca].pos, indMaca+1, macas[indMaca].tempo), qntMacas(posiAtual, indMaca+1, tempo));

    return memo[posiAtual.i][posiAtual.j][tempo] = qntMacas(posiAtual, indMaca+1, tempo);
}

void init(int n, int m, int k){
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            for(int l=0; l<=(k<<1); l++)
                memo[i][j][l] = -1;
}

bool cmp(Maca a, Maca b){
    return a.tempo < b.tempo;
}

int main(){_
    Position ini;
    while(cin >> n >> m >> k && (n||m||k)){
        init(n, m, k);
        maiorTempo = 0;
        for(int i=0; i<k; i++){
            cin >> macas[i].pos.i >> macas[i].pos.j >> macas[i].tempo;
        }
        sort(macas, macas+k, cmp);
        cin >> ini.i >> ini.j;
        cout << qntMacas(ini, 0, 0) << endl;
    }


	return 0;
}
