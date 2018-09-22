#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 104

using namespace std;

int mat[MAXN][MAXN];

int resp(int n, int m){
	int caso1, caso2, caso3, caso4;
	
	for(int i=0; i<n; i++){
		caso1 = 1;
		for(int j=0; j<m; j++)
			caso1*=mat[i][j];
		if(caso1){
			caso1 = 0;
			break;
		}
		else caso1 = 1;
	}
	
	for(int i=0; i<m; i++){
		caso2 = 0;
		for(int j=0; j<n; j++)
			caso2|=mat[j][i];
		if(!caso2){
			break;
		}
	}
	
	for(int i=0; i<m; i++){
		caso3 = 1;
		for(int j=0; j<n; j++)
			caso3*=mat[j][i];
		if(caso3){
			caso3 = 0;
			break;
		}
		else caso3 = 1;
	}
	
	for(int i=0; i<n; i++){
		caso4 = 0;
		for(int j=0; j<m; j++)
			caso4|=mat[i][j];
		if(!caso4){
			break;
		}
	}
	
	return (caso1 + caso2 + caso3 + caso4);
	
	
}

int main(){_
	int n, m;
	while((cin >> n >> m) && (n||m)){
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> mat[i][j];
		cout << resp(n, m) << endl;
	}

	return 0;
}
