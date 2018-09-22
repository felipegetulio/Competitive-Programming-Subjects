using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long

int main(){_
    int n, tam;
    string s;

    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        tam = s.length();
        if(tam > 10) cout << s[0] << tam-2 << s[tam-1];
        else cout << s;
        cout << endl;
    }

    return 0;
}
