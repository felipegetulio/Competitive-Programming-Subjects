#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 104

using namespace std;

map<string, int> ehEsp;

string minusculo(string s){
    string t = "";
    for(int i=0; i<s.length(); i++)
        t += tolower(s[i]);
    return t;
}

string words[MAXN];

int main(){_
    int e, t, f, tam;
    string esp, filme, s, sigla;
    cin >> t;

    while(t--){
        ehEsp.clear();
        cin >> e >> f;
        cin.ignore();
        getline(cin, esp);
        stringstream ss(esp);
        while(ss >> s)
            ehEsp[minusculo(s)] = true;

        while(f--){
            tam = 0;
            sigla = "";
            getline(cin, filme);

            for(int i=0; i<filme.length(); i++)
                if(filme[i] == '-' || filme[i] == ':')
                    filme[i] = ' ';
                else filme[i] = tolower(filme[i]);

            stringstream ss(filme);
            while(ss >> s)
                words[tam++] = s;

            for(int i=0; i<tam; i++){
                //cout << words[i] << endl;
                //cout << ehEsp[words[i]] << endl << endl;;
                if(ehEsp[words[i]]){
                    if(i != 0)
                        sigla += words[i][0];
                }
                else sigla += toupper(words[i][0]);
            }
            cout << sigla << endl;
        }
        cout << endl;
    }


    return 0;
}
