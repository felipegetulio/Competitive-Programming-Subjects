#include<cstdio>
#include<algorithm>
#define MAXN 1002
#define MAXM 52

using namespace std;

int dp[MAXN][MAXM];
int w[MAXN], v[MAXN];
int n, c;

void limpa(int n, int c){
	for(int i=0; i<=n; i++)
		for(int j=0; j<=c; j++)
			dp[i][j] = -1;
}

int grau(int id, int pesoRestante){
	if(pesoRestante == 0) return 0;
	if(id == n) return 0;
	
	if(dp[id][pesoRestante] != -1) return dp[id][pesoRestante];
	
	if(w[id] > pesoRestante) 
		return dp[id][pesoRestante] = grau(id+1, pesoRestante);
	
	if(w[id] <= pesoRestante)
		return dp[id][pesoRestante] = max(grau(id+1, pesoRestante), v[id] + grau(id+1, pesoRestante - w[id]));
}


int main(){
	int maxGrau;
	int caso = 1;
	
	while(scanf("%d%d", &n, &c), n!=0 || c!=0){
		limpa(n, c);
		for(int i=0; i<n; i++)
			scanf("%d%d", 	w+i, v+i);
		maxGrau = grau(0, c);
		printf("Caso %d: %d\n", caso++, maxGrau);
	} 
	
	
	return 0; 
}
