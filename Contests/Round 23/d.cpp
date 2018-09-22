using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);


int main(){_

	int per_month;
	int cur, n;
	int rem;


	cin >> per_month >> n;
	rem = per_month;

	while(n--){
		cin >> cur;
		rem += per_month - cur;
	}


	cout << rem << endl;


	return 0;
}