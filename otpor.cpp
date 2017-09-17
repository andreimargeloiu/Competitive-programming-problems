# include <bits/stdc++.h>
# define NR 100005
using namespace std;
//ifstream f("test.in");
//ofstream g("test.out");
int i,n,poz,l;
double rez[100], sol;
char s[NR];

double eval(int &);
double termen (int &);
double factor (int &);

double eval (int &poz) { //cand intre pe prima poz e paranteza
    ++poz; //trec de prima paranteza
    double sol=termen (poz);

    while (s[poz]=='-' && poz<=l) {
        ++poz; //trecem de '-'
        sol+=termen(poz);
    }
    ++poz; // trec de ultima paranteza
    return sol;
}
double termen (int &poz) {
    double sol=factor (poz);
    if (s[poz]=='|') { // nu e doar in singur rezostor
        sol=((double)(1))/sol;
        while (s[poz]=='|' && poz<=l) {
            ++poz; //trec de '|'
            sol+=(((double)(1))/factor(poz));
        }
        return ((double)(1))/sol;
    }else return sol;
}
double factor (int &poz) {
    double sol;

    if (s[poz]=='R') { //daca e rezistor
        ++poz;
        sol=rez[s[poz]-'0'];
        ++poz;//trec de rezistor si indice
    } else sol=eval(poz); //este '('

    return sol;
}
int main ()
{
    cin>>n;
    for (i=1; i<=n; ++i)
        cin>>rez[i];
    cin.get();

    cin.getline (s+1, NR); l=strlen(s+1);

    poz=1;
    sol=eval(poz);

    cout<<fixed<<setprecision(6)<<sol<<"\n";


    return 0;
}
