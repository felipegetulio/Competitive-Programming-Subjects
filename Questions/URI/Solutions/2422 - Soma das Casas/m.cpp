#include<bits/stdc++.h>
#define MAXN 100005
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int v[MAXN];

int binarySearch(int left, int right, int num){

	int lo = left, hi = right, mid;

	while(lo < hi){

		mid = lo + (hi - lo >> 1);

		if(v[mid] >= num) hi = mid;
		else lo = mid+1;
	}

	return lo;
}

int main(){_

	int n, k, sum = -1, i;
	int pos;

	cin >> n;

	for(int i=0; i<n; ++i){
		cin >> v[i];
	}

	cin >> k;

	for(i=0; i<n-1 && sum != k; ++i){
		pos = binarySearch(i+1, n, k-v[i]);
		sum = v[pos] + v[i];
	}
	
	cout << v[i-1] << ' ' << v[pos] << endl;


	return 0;
}