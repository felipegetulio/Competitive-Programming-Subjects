#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXOBJ 103
#define MAXTAM  503
#define inf 1000000000

using namespace std;

int bestValor[MAXOBJ][MAXTAM], valor[MAXOBJ], tam[MAXOBJ], bestTam[MAXOBJ][MAXTAM];


void mochila(int n, int m){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(tam[i]<=j){
				if(bestValor[i-1][j-tam[i]] + valor[i] > bestValor[i-1][j]){
					bestValor[i][j] = bestValor[i-1][j-tam[i]] + valor[i];
					bestTam[i][j] = bestTam[i-1][j-tam[i]] + tam[i];
				}
				else{
					bestValor[i][j] = bestValor[i-1][j];
					bestTam[i][j] = bestTam[i-1][j];
				}
			}
			else{
				bestValor[i][j] = bestValor[i-1][j];
				bestTam[i][j] = bestTam[i-1][j];
			}
	cout << bestTam[n][m] << ' ' << bestValor[n][m] << endl;
}

int main(){_

	int n, m;
	while((cin >> m >> n) && (n||m)){
		for(int i=1; i<=n; i++)
			cin >> tam[i] >> valor[i];
		mochila(n, m);
	
	}
	

	return 0;
}
