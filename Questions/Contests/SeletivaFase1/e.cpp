#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 1<<8

using namespace std;

typedef unsigned long long ull;

int peso[MAXN];

ull toBin(string s){
	
}

void init(){
	for(char i='0'; i<='9'; i++)
		peso[i] = i-'0';
	for(int i='A'; i<='Z'; i++)
		peso[i] = (i-'A') + 10;
	for(int i='a'; i<='z'; i++)
		peso[i] = (i-'a') + 36;
	peso['-'] = 62;
	peso['_'] = 63;
}



int main(){_
	string s;
	ull n = 0, mult = 1;
	init();
	cin >> s;
	for(int i=0; i<s.length(); i++){
		n = 64*n + peso[s[i]];
	}
		
	cout << n << endl;



	return 0;
}
