using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 26
#define MAXMEMO 15
#define oo 2000000000.0
#define vert(a, b) (5*(a) + (b))

int oddn, n;
int vis;
int oddVertices, vertices;

double adj[MAXN][MAXN];
double oddDist[MAXN][MAXN];
double memo[1<<MAXMEMO];
int oddToVert[MAXN];
int vertToOdd[MAXN];

void dfs(int u){
	vis |= (1 << u);

	for(int v, setv = vertices; setv; setv -= (setv)&(-setv)){
		v = __builtin_ffs(setv)-1;
		if(adj[u][v] < oo - 0.5 && !(vis & (1 << v))){
			dfs(v);
		}
	}
}

int bitLenght(int n){
	int count = 0;

	while(n){
		++count;
		n>>=1;
	}
	return count;
}

bool isConnected(){
	if(vertices == 0)
		return true;

	vis = 0;
	n = bitLenght(vertices);
	dfs(__builtin_ffs(vertices) - 1);
	return vis == vertices;
}

double minCost(int bitmask){
	
	if(memo[bitmask] > -0.5)
		return memo[bitmask];

	if(__builtin_popcount(bitmask) <= 2){
		return memo[bitmask] = 0;
	}

	double ans = oo;

	for(int u=__builtin_ffs(bitmask)-1; u<oddn-1; ++u){
		if(bitmask & (1 << u)){
			for(int v=u+1; v<oddn; ++v){
				if(bitmask & (1 << v)){
					ans = min(ans, oddDist[u][v] + minCost(bitmask & (~(1 << u)) & (~(1 << v))));
				}
			}
		}
	}
	
	return memo[bitmask] = ans;
}

void init(){
	memset(vertToOdd, -1, sizeof(vertToOdd));
	memset(oddToVert, -1, sizeof(oddToVert));

	for(int i=0; i<MAXN; ++i)
		for(int j=0; j<MAXN; ++j)
			adj[i][j] = oo * (i != j);

	for(int i=0; i<(1<<MAXMEMO); ++i)
		memo[i] = -1.0;
}


int main(){_
	int t, u, v, di, dj, lines, div;
	double w, sumEdges, ans;
	string sa, sb, su, sv;

	cin >> t;
	cout.precision(2);

	for(int ncase = 1; ncase<=t; ++ncase){
		init();

		sumEdges = 0;
		oddVertices = vertices = 0;
		oddn = n = 0;

		cin >> lines;

		while(lines--){
			cin >> sa >> sb;

			if(sa == sb)
				continue;

			div = abs(__gcd(sb[0] - sa[0], sb[1] - sa[1]));
			di = (sb[0] - sa[0])/div;
			dj = (sb[1] - sa[1])/div;

			su = sv = sa;
			
			do{
				sv[0] = su[0] + di;
				sv[1] = su[1] + dj;

				u = vert(su[0] - 'A', su[1] - '1');
				v = vert(sv[0] - 'A', sv[1] - '1');
				w = hypot(sv[0] - su[0], sv[1] - su[1]);

				if(adj[u][v] > oo - 0.5){
					adj[u][v] = adj[v][u] = w;
					vertices |= (1 << u) | (1 << v);
					oddVertices ^= (1 << u) ^ (1 << v);
					sumEdges += w;
				}
				
				su = sv;
			}while(sv != sb);
		}

		cout << "Case " << ncase << ": ";

		if(!isConnected() ){
			cout << "~x(" << endl;
		}
		else{
			for(int k=0; k<MAXN; ++k){
				for(int i=0; i<MAXN; ++i){
					for(int j=0; j<MAXN; ++j){
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					}
				}
			}

			for(int bit = oddVertices; bit; bit -= (bit)&(-bit)){
				u = __builtin_ffs(bit)-1;
				oddToVert[oddn] = u;
				vertToOdd[u] = oddn++;
				//cout << "vert[" << (__builtin_ffs(u)-1) << "] = " << oddn-1 << endl;
			}

			for(int i=0; i<oddn; ++i){
				for(int j=0; j<oddn; j++){
					oddDist[i][j] = adj[oddToVert[i]][oddToVert[j]];
				}
			}
				
			ans = minCost((1 << oddn)-1);

			cout << fixed << (sumEdges + ans) << endl;
		}

	}

	return 0;
}



