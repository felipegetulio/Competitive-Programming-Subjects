using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define zerar() for(char i='a'; i<='z'; i++) freq[i] = 0

int freq[1<<8];

int main(){_
    int n;
    string s, outras;
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        zerar();
        outras = "";
        for(int i=0, tam=s.length(); i<tam; i++)
            freq[tolower(s[i])] = 1;

        for(char i='a'; i<='z'; i++)
            if(!freq[i]) outras += i;
        if(outras == "") cout << "pangram";
        else cout << "missing " << outras;
        cout << endl;
    }



    return 0;
}
