#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 1<<8
#define zera() for(int i=0; i<MAXN; i++) codigo[i] = 0

using namespace std;

int codigo[MAXN];

int main(){_
	int c, n;
	string a, b, s;
	while(cin >> c >> n){
		zera();
		getline(cin, s);
		getline(cin, a);
		getline(cin, b);
		for(int i=0; i<c; i++){
			if(isalpha(a[i]) && isalpha(b[i])){
				codigo[tolower(a[i])] = tolower(b[i]);
				codigo[toupper(a[i])] = toupper(b[i]);
				codigo[tolower(b[i])] = tolower(a[i]);
				codigo[toupper(b[i])] = toupper(a[i]);
			}
			else{
				if(isalpha(a[i])){
					codigo[tolower(a[i])] = codigo[toupper(a[i])] = b[i];
					codigo[b[i]] = tolower(a[i]);
				}
				else if(isalpha(b[i])){
					codigo[tolower(b[i])] = codigo[toupper(b[i])] = a[i];
					codigo[a[i]] = tolower(b[i]);
				}
				else{
					codigo[a[i]] = b[i];
					codigo[b[i]] = a[i];
				}
			}	
		}
		
		while(n--){
			getline(cin, s);
			for(int i=0, tam=s.length(); i<tam; i++)
				s[i] = (codigo[s[i]]==0? s[i]:codigo[s[i]]);
			cout << s << endl;		
		}
		cout << endl;
	}


	return 0;
}
