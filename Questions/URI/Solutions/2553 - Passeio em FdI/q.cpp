using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 50
#define inf 1000000000

int v[MAXN], a[MAXN];
int n;
int memo[MAXN][820][820];

int qntAtracoes(int ind, int qntV, int qntA){
	//primeiro testar os casos inválidos
	//retornar o valor neutro da função quando estiver neste casos
	//depois os casos bases
	if(qntV < 0 || qntA < 0) return -inf;

	if(ind == n) return 0;

	if(memo[ind][qntV][qntA] != -1) return memo[ind][qntV][qntA];

	return memo[ind][qntV][qntA] = max(qntAtracoes(ind+1, qntV, qntA),1 + qntAtracoes(ind+1, qntV+v[ind], qntA+a[ind]));
}

void init(){
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n*20; j++)
			for(int k=0; k<=n*20; k++)
				memo[i][j][k] = -1;
}

int main(){_
	int na, nv;

	while(scanf("%d", &n) != EOF){
		init();
		scanf("%d%d", &nv, &na);
		for(int i=0; i<n; i++)
			scanf("%d %d", v+i, a+i);
		printf("%d\n", qntAtracoes(0, nv, na));
	}



	return 0;
}
