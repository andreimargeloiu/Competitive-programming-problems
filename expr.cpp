# include <fstream>
# include <algorithm>
# include <cstring>
# include <bitset>
# include <vector>
# define NR 100005
# define nrb 8005
# define N 305
using namespace std;
ifstream f("expr.in");
ofstream g("expr.out");
vector <int> v;
bitset <nrb> BB, B[N];
int i,j,n,m,l,nr,VV,ok,poz,K;
int var[NR];
char s[NR];

void normalizare () {
    int VV2=VV, i; VV=0; var[0]=-1;
    sort (var+1, var+VV2+1);
    for (i=1; i<=VV2; ++i)
        if (var[i-1] != var[i]) var[++VV]=var[i];
}
void citire () {
    f.getline (s+1, NR); l=strlen(s+1);
    for (i=1; i<=l; i+=0) {
        if ('0'<=s[i] && s[i]<='9') {
            nr=0;
            while ('0'<=s[i] && s[i]<='9') {
                nr=nr*10 + s[i]-'0';
                ++i;
            }
            var[++VV]=nr;
        }
        else ++i;
    }
}
void afisare (int K) {
    int ok=0;
    g<<"{";
    for (int i=1; i<nrb; ++i) {
        if (B[K][i]==1) {
            if (ok) g<<","; ok=1;
            g<<var[i];
        }
    }
    g<<"}\n";
}

void eval(int &, int);
void termen(int &, int);
void numar (int &, int);
int cb(int);

void scoate () {
    pop_heap(v.begin(), v.end());
    v.pop_back();
}
void baga (int X) {
    v.push_back(X);
    push_heap(v.begin(), v.end());
}
void init (int X) {
    B[X]=B[X] & BB;
}
void eval(int &poz, int K) { //B este gol cand intru in functie
    int P, K2, K3;
    //scot doi bitseti
    K2=v[0]; init (K2); scoate();
    K3=v[0]; init (K3); scoate();

    termen (poz, K);

    while (s[poz]=='*' || s[poz]=='+' || s[poz]=='-' || s[poz]=='%')
    {
        P=poz; ++poz;

        termen (poz, K2);
        //{1,2,3,4}%({1,2,3,4}*{}+{1,2}+{5,6}-{1})
        /*
        * - intersectie
        + - reuniune
        - - diferenta
        % - diferenta simetrica: A%B = (A-B)+(B-A) = (A+B) - (A*B)
        */

        switch (s[P]) {
            case '*': {(B[K]=B[K] & B[K2]); break;}// intersectie
            case '+': {(B[K]=B[K] | B[K2]); break;}// reuniune
            case '-': {                     // diferenta
                 B[K3]=B[K] ^ B[K2];

                 B[K]=B[K3] & B[K];
                 break;
            }
            case '%': {                     //diferenta simetrica
                 B[K3]=B[K] ^ B[K2];
                 //afisare (K2);

                 B[K] =B[K3] & B[K]; // A-B
                 B[K2]=B[K3] & B[K2]; // B-A

                 B[K]=B[K] | B[K2];
                 break;
            }
        }
    }
    baga (K2); baga(K3);
}
void termen(int &poz, int K) {
    int K2;
    K2=v[0]; init (K2); scoate();

    if (s[poz]=='(') {
        ++poz;
        eval(poz, K2);
        ++poz;
    }
    else if (s[poz]=='{') {
        ++poz; // trec de "{"
        if ('0'<=s[poz] && s[poz]<='9') {
            while ('0'<=s[poz] && s[poz]<='9')  {
                numar(poz, K2);
                ++poz; // trec de ','
            }
        }
        else ++poz;
    }
    init (K); B[K]=B[K] | B[K2];

    baga (K2);
}
void numar (int &poz, int K) { // B nu e curat
    int nr=0;
    while ('0'<=s[poz] && s[poz]<='9') {
        nr=nr*10 + s[poz]-'0';
        ++poz; // trec de ','
    }
    B[K][cb(nr)]=1;

    //g<<cb(nr)<<"\n";
    //afisare (K);
}
int cb (int k) {
    int ci=1, cs=VV, mij;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        if (var[mij]==k) return mij;

        if (var[mij] < k) ci=mij+1;
                     else cs=mij-1;
    }
}
int main ()
{
    citire ();
    normalizare ();

    for (i=2; i<N; ++i)
        baga(i);

    K=1; poz=1;
    eval (poz, K);

    afisare (K);

    return 0;
}
