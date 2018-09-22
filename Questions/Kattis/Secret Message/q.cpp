using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

int main(){_
    int n, tam;
    string s;

    cin >> n;
    while(n--){
        cin >> s;
        tam = ceil(sqrt(s.length()));
        for(int i=tam*tam-s.length(); i--;)
            s += "*";

        for(int i=tam*(tam-1); i<tam*tam; i++)
            for(int j=i; j>=0; j-=tam)
                if(s[j] != '*') cout << s[j];
        cout << endl;

    }

    return 0;
}
