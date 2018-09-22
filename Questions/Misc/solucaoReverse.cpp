#include<bits/stdc++.h>
#define N 3
#define MAXN 1<<(N*N)
#define inf 1000000000

using namespace std;

typedef vector<int> vi;

vi adj[MAXN], dist;


int posi(int i, int j){
    return N*i+j;
}

void grafo(){
	int estados[] = {11, 23, 38, 89, 186, 308, 200, 464, 416};
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<N*N; j++)
			adj[i].push_back(i^estados[j]);
}

int bfs(int s){
	int u, v, d1 = 0, d2 = (MAXN)-1;
	if(s == d1 || s == d2) return 0;
	dist.assign(MAXN, inf);
	queue <int> fila;
	dist[s] = 0;
	fila.push(s);
	while(!fila.empty()){
		u = fila.front(); fila.pop();

		for(int i=0; i<adj[u].size(); i++){
			v = adj[u][i];
			if(dist[v] == inf){
				dist[v] = dist[u]+1;
				if(v == d1 || v == d2) return dist[v];
				fila.push(v);
			}
		}
	}
	return inf;
}

int main(){
	int t, a, b, distA, distB;
	int vitA = 0, vitB = 0, empate = 0;
	char c;
	grafo();
	scanf("%d ", &t);
	while(t--){
		a = b = 0;
		for(int i=0; i<N*N; i++){
            scanf("%c ", &c);
            a |= ((c=='*') << i);
        }
        for(int i=0; i<N*N; i++){
            scanf("%c ", &c);
            b |= ((c=='*') << i);
        }
        distA = bfs(a);
        distB = bfs(b);
		  
        vitA += (distA < distB);
        vitB += (distB < distA);
	}

	if(vitA > vitB) printf("Fred wins!\n");
	else if(vitA < vitB) printf("Jason wins!\n");
	else printf("Its a draw!\n");
	return 0;
}
