#include<bits/stdc++.h>
#define MAXP 104
#define zera() for(int i=1; i<=100; i++) freq[i] = 0

using namespace std;

//vetor de frequência -> fácil

int freq[MAXP];

int main(){
	int n, k, p, cont;
	while(scanf("%d%d", &n, &k) && (n||k)){
		cont = 0;
		zera();
		while(n--){
			scanf("%d", &p);
			freq[p]++;
		}
		for(int i=1; i<=100; i++)
			cont += (freq[i]>=k);
		printf("%d\n", cont);
		
	}
	
	return 0;
}
