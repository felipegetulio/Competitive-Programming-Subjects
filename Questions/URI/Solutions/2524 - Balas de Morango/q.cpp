using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1004
#define inf 1000000000

int memo[MAXN][MAXN];
int balas[MAXN];
int n, m;

int qntPacotes(int ind, int soma){
	if(memo[ind][soma] != -1) return memo[ind][soma];
	if(ind == m) return soma == 0? 0:-inf;
	return memo[ind][soma] = max(1 + qntPacotes(ind+1, (soma + balas[ind])%n), qntPacotes(ind+1, soma));
}

void init(){
	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++)
			memo[i][j] = -1;
}

int main(){_
	while(cin >> n >> m){
		init();
		for(int i=0; i<m; i++)
			cin >> balas[i];
		cout << qntPacotes(0, 0) << endl;
	}
	return 0;
}
