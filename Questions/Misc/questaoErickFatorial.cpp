#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);

using namespace std;

int cb[] = {1, 1, 2, 6, 24, 12, 72, 4, 32, 88, 88};
int pot[] = {1, 76, 12, 44, 28, 36, 32, 84, 8, 96, 52, 24, 88, 56, 72, 64, 68, 16, 92, 4, 48};

int l2do(int n){
	if(n <= 10) return cb[n];
	if(n%5!=0) return ((n%100)*l2do(n-1))%100;
	return (l2do(n/5) * pot[(n/5)%20 + ((n/5)!=0)])%100;
}

int main(){_
	int n, ans;

	int k = 1;

	for(int i=1; i<100; ++i){
		if(i%5 != 0){
			k = (k * i)%100;	
		}
	}

	for(int i=0; i<20; ++i){
		cout << k << endl;
		k = (k*k)%100;
	}

	


	while(cin >> n)
		cout << l2do(n)/10 << endl;
	return 0;
}
