// calcula prefix function, maior prefixo que também é sufixo até a string de 0 até i.
vector<int> kmp(string s){
    int n = (int)s.size();

    vector<int> pi(n);

    for(int i=1; i<n; i++){
        int j = pi[i-1];

        while(j>0 && s[i]!=s[j]) j=pi[j-1];

        if(s[i]==s[j]) j++;

        pi[i]=j;
    }
    return pi;
}
