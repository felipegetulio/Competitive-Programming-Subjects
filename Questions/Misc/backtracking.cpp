









#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 17
using namespace std;

int col[MAXN];
int cont;

bool podeColocar(int l, int c){
	for(int i=1; i<=l-1; i++){
		if(col[i] == c || abs(l - i) == abs(c - col[i]))
			return false;
	}
	return true;
}

void backtracking(int l, int n){
	cont += (l == n+1);

	for(int c = 1; c<=n; c++){
		if(podeColocar(l, c)){
			col[l] = c;
			backtracking(l+1, n);
		}
	}
}


int main(){_
	int n;
	
	while(cin >> n, n){
		cont = 0;
		backtracking(1, n);
		cout << cont << endl;
	}

	return 0;
}
