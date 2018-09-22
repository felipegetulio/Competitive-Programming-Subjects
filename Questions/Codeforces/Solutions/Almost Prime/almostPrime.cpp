#include<bits/stdc++.h>
#define MAXN 3003

using namespace std;

typedef vector<int> vi;

int qntPrimos[MAXN];

//crivo modificado

int qntQuasePrimos(int n){
	int cont = 0;
	for(int i=2; 2*i<=n; i++)
		if(qntPrimos[i] == 0)
			for(int j=2*i; j<=n; j+=i)
				qntPrimos[j]++;
	
	for(int i=0; i<=n; i++)
		cont += (qntPrimos[i] == 2);
	return cont;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", qntQuasePrimos(n));
	
	return 0;
}
