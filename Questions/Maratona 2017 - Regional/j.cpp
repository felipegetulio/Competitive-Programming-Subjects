using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

int main(){_
	int ans = 0;
	string s;
	cin >> s;

	for(int i=0; i<s.size(); i++)
		ans += s[i]-'0';

	cout << ans%3 << '\n';

	return 0;
}