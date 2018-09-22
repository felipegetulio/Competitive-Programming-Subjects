#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100004

using namespace std;

int qntWorms[MAXN];
int accum[MAXN];
int pileOf[MAXN*10];

void init(int n){
	int pile = 1;
	
	for(int i=1; i<=accum[n]; i++){
		pile += (i > accum[pile]);
		pileOf[i] = pile;
	}

}

int main(){_
	int n, m, worm;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> qntWorms[i];
		accum[i] = accum[i-1] + qntWorms[i];
	}
	init(n);
	cin >> m;
	while(m--){
		cin >> worm;
		cout << pileOf[worm] << endl;
	}
	

	return 0;
}
