#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 1004
#define MAXF 100004
#define limpaFila() while(!pq.empty()) pq.pop();

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, int> ii;
typedef vector<ii> vii;

ll primos[MAXN], multiplos[MAXF], proxMult[MAXN];;
int idProxMult[MAXN]; 
priority_queue <ii, vii, greater<ii> > pq;//first: proximo multiplo, second: indice do primo do multiplo

int main(){_
	int n, m, idMult, idPrimoDoProxMult;
	ll multAtual;
	multiplos[0] = 1;
	while(cin >> n >> m, n || m){
		idMult = 1;
		for(int i=0; i<n; i++){
			cin >> primos[i];
			proxMult[i] = primos[i];
			idProxMult[i] = 1;
			pq.push(ii(proxMult[i], i));
		}

		for(int i=0; i<m; i++){
			multAtual = pq.top().first;
			idPrimoDoProxMult = pq.top().second; pq.pop();
			if(multiplos[idMult-1] != multAtual)
				multiplos[idMult++] = multAtual;
			else i--;
			proxMult[idPrimoDoProxMult] = multiplos[idProxMult[idPrimoDoProxMult]++]*primos[idPrimoDoProxMult];
			pq.push(ii(proxMult[idPrimoDoProxMult], idPrimoDoProxMult));
		}
		
		cout << multiplos[m] << endl;
		limpaFila();

	}

	return 0;
}
