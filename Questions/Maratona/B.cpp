#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 10004
#define MAXM 2000004
#define inf 1000000000

using namespace std;

int v[MAXN], freq[MAXM];

int main(){_
	int n, m, preco1, preco2, menorDif;
	while(cin >> n){
		for(int i=0; i<n; i++)
			cin >> v[i];
		cin >> m;
		for(int i=0; i<=m; i++)
			freq[i] = 0;
			
		menorDif = inf;
		for(int i=0, j; i<n; i++){
			j = m - v[i];
			if((j>=0) && (j<MAXM)){
				if(freq[j]!=0)
					if(abs(v[i]-j) < menorDif){
						menorDif = abs(v[i]-j);
						preco1 = min(v[i], j);
						preco2 = max(v[i], j);
					}
			}
			freq[v[i]]++;
		}
		cout << "Peter should buy books whose prices are " << preco1 << " and " << preco2 << '.' << endl << endl;	
	}

	return 0;
}
