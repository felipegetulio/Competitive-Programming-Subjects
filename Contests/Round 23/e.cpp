using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1004
#define clear(k) for(int i=0; i<=k; ++i) sticks[i] = 0

int mat[MAXN][MAXN];
int sticks[MAXN];

int main(){_

	int col, row, c;
	int ones;
	int ans;

	while((cin >> col >> row >> c) && (col || row || c)){
		ans = 0;

		clear(row);

		for(int i=0; i<row; ++i)
			for(int j=0; j<col; ++j)
				cin >> mat[i][j];

		for(int j=0; j<col; ++j){
			ones = 0;
			for(int i=0; i<row; ++i){
				ones += mat[i][j];

				if(!mat[i][j] || i == row-1){
					++sticks[ones];
					ones = 0;
				}
			}
		}
	
		for(int i=c; i<=row; ++i)
			ans += sticks[i];

		cout << ans << endl;

	}

	return 0;
}