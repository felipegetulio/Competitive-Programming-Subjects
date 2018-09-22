using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);


int main(){_

	int n, num;
	int count = 0;

	cin >> n;


	while(n--){
		cin >> num;
		count += (num < 0);
	}

	cout << count << endl;


	return 0;
}