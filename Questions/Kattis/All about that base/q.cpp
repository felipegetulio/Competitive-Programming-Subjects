using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long
#define MAXN ((1LL<<32)-1)

int valor[1<<8];
char alg[40];

ll stringInBaseToDec(string s, int base){
    ll ans = 0;
    for(int i=0, tam=s.length(); i<tam; i++){
        ans = base*ans + valor[s[i]];
        if(ans > MAXN) return -1;
    }
    return ans;
}

int valido(string sx, string sy, string sz, char op, int base){
    ll x, y, z;
    x = stringInBaseToDec(sx, base);
    y = stringInBaseToDec(sy, base);
    z = stringInBaseToDec(sz, base);
    if(x == -1 || y == -1 || z == -1) return 0;
    switch(op){
        case '+': return (x + y == z);
        case '-': return (x - y == z);
        case '*': return (x * y == z);
        case '/': return (z * y == x);
    }
    return 0;
}

int maiorAlg(string s){
    int m = 0;
    for(int i=0, tam=s.length(); i<tam; i++)
        m = max(m, valor[s[i]]);
    return m;
}

int menorAlg(string s){
    int m = 40;
    for(int i=0, tam=s.length(); i<tam; i++)
        m = min(m, valor[s[i]]);
    return m;
}

void init(){
    for(char i='0'; i<='9'; i++)
        valor[i] = i-'0';
    for(char i='a'; i<='z'; i++)
        valor[i] = i-'a'+10;
    for(int i=1; i<10; i++)
        alg[i] = i-1+'1';
    for(int i=10; i<36; i++)
        alg[i] = i-10+'a';
    alg[36] = '0';
}

int main(){_
    int n;
    string sx, sy, sz, ans;
    char op, igual, maior, menor;

    init();
    cin >> n;
    while(n--){
        ans = "";
        cin >> sx >> op >> sy >> igual >> sz;

        maior = max(maiorAlg(sx), max(maiorAlg(sy), maiorAlg(sz)));
        menor = min(menorAlg(sx), min(menorAlg(sy), menorAlg(sz)));

        for(int base = (maior==menor && maior == 1? 1:maior+1); base<=36; base++)
            if(valido(sx, sy, sz, op, base))
                ans += alg[base];

        cout << (ans == ""? "invalid":ans) << endl;
    }

    return 0;
}
