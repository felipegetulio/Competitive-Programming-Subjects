using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

unordered_set<string> mp;

int main(){_

	string s;
	string resp[2] = {"no", "yes"};
	int ans = 1;

	while(cin >> s){
		ans &= (mp.find(s) == mp.end());
		mp.insert(s);
	}

	cout << resp[ans] << endl;

	return 0;
}