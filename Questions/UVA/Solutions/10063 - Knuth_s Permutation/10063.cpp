#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 3628800

using namespace std;

string perm;
int tam;

void knuthsPerm(int ind, string s){
    if(ind == tam){
        cout << s << endl;
        return;
    }
    string r;
    for(int i=0; i<=ind; i++){
        r = s;
        r.insert(i, 1, perm[ind]);
        knuthsPerm(ind+1, r);
    }
}

int main(){_
	cin >> perm;
	while(true){
		tam = perm.length();
		knuthsPerm(0, "");
		if(cin >> perm) cout << endl;
		else break;
	}


    return 0;
}
