using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MOD 1000000007
#define i64 long long

i64 freq[1<<8];

int main(){_
	string s, w;
	int index[12];
	i64 ans = 1;

	cin >> s >> w;

	for(int i=0; i<w.size(); ++i){
		for(int j=0; j<s.size(); ++j){
			if(w[i] == s[j])
				index[i] = j;
		}
	}

	for(int i=0; i<w.size(); ++i){
		for(int j=0; j<s.size(); ++j){
			freq[s[i]] += 
		}
	}	
	

	for(int i=0; i<w.size(); ++i){
		cout << freq[w[i]] << endl;
		ans = (ans * freq[w[i]])%MOD;
	}

	cout << ans << endl;

	return 0;
}