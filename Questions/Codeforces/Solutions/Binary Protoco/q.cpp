using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

int main(){_
    int n, cont = 0, ans = 0;
    string s;
    cin >> n >> s;

    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            ans = 10*ans + cont;
            cont = 0;
            continue;
        }
        cont++;
    }
    ans = 10*ans + cont;

    cout << ans << endl;


    return 0;
}
