#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100005

using namespace std;

int xorAteN(int n){
	int ans = n%4;
	switch(ans){
		case 0: return n;
		case 1: return 1;
		case 2: return n+1;
		case 3: return 0;
	}
}

int main(){_
	int x = 1 + 2 + 3 + (1^2) + (2^3) + (1^2^3);
	cout << x << endl;
	cout << x << endl;
	


	return 0;
}
