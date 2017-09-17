# include <bits/stdc++.h>
# define NR 100000
using namespace std;
ifstream f("dorel.in");
ofstream g("dorel.out");
struct elem {
    int nr1, nr2, i;
}var[2*NR];
bool cmp (elem x, elem y) {
    if (x.nr1 > y.nr1) return 0;
        else if (x.nr1==y.nr1 && x.nr2 >= y.nr2) return 0;
            else return 1;
}
int i,j,n,m,N,ci,cs,mij,Q,poz,ST,DR,VV,LX,LY,ok;
short sol, SOL, Maux;
short pi[NR], X[NR], Y[NR], RMQ[20][3*NR];
short minn[NR], maxx[NR], st[NR], dr[NR], lg[3*NR], solutie[NR];
char s[NR];

void preprocesare () {
    short var;
    for (int i=1; i<=N; ++i) { //stanga
        int CH=s[i] - 'a' + 1; var=1;
        for (int j=CH; j<=26; ++j)
            var=max(var, maxx[j]);
        st[i]=var; maxx[CH]=i;
    }

    for (int i=n; i>=1; --i) { //dreapta
        int CH=s[i] - 'a' + 1; var=N;
        for (int j=CH; j>=1; --j)
            if (minn[j]!=0) var=min(var, minn[j]);
        dr[i]=var; minn[CH]=i;
    }
}
void logaritmi () {
    for (int i=2; i<=2*n+1; ++i)
        lg[i]=lg[i/2] + 1;
}
void suffixArrays () {
    RMQ[0][++n]='$';
    for (int i=1; i<=N; ++i)
        RMQ[0][2*N+1-i+1]=RMQ[0][i];
    n=2*N+1;

    for (int i=1; i<=n; ++i)
        RMQ[0][n+i]='$';

    for (int i=1; i<=lg[N]; ++i) {
        for (int j=1; j<=n; ++j) {
            var[j].nr1=RMQ[i-1][j];
            var[j].nr2=RMQ[i-1][j+(1<<(i-1))];
            var[j].i=j;
        }
        sort (var+1, var+n+1, cmp);

        int VV=0;
        for (int j=1; j<=n; ++j) {
            if (var[j].nr1!=var[j-1].nr1 || var[j].nr2!=var[j-1].nr2)
                ++VV;

            RMQ[i][var[j].i]=VV;
        }
    }
}
int LCP (int I, int J) {
    int sol=0;
    if (I>J) swap(I, J);

    for (int i=lg[N]; i>=0 && I<=N && J<=n; --i)
        if (RMQ[i][I]==RMQ[i][J]) {
            I+=(1<<i);
            J+=(1<<i);
            sol+=(1<<i);
        }
    return sol;
}
void make_aux (int st, int dr) {
    LX=0;
    for (int i=1; i<=N; ++i)
        if (i<st || dr<i) X[++LX]=s[i];
}
bool verif (int ci, int cs) {
    int k=0; LY=0;
    for (int i=ci; i<=cs; ++i) Y[++LY]=s[i];

    for (int i=2; i<=LY; ++i) {
        while (k && Y[k+1]!=Y[i])
            k=pi[k];
        if (Y[k+1]==Y[i]) ++k;
        pi[i]=k;
    }
    k=0;
    for (int i=1; i<=LX; ++i) {
        while (k && Y[k+1]!=X[i])
            k=pi[k];
        if (Y[k+1]==X[i]) ++k;
        if (k==LY) return 1;
    }

    return 0;
}
int main ()
{
    f.getline (s+1, NR); n=strlen(s+1); N=n;
    for (i=1; i<=n; ++i)
        RMQ[0][i]=s[i];
    preprocesare (); logaritmi (); suffixArrays ();
    f>>Q;
    for (int q=1; q<=Q; ++q) {
        f>>poz; ST=st[poz]; DR=dr[poz]; SOL=0;
        if (solutie[poz]) {
            g<<solutie[poz]<<" ";
            continue;
        }

        make_aux(ST, DR);

        //caut binar lungimea maxima a unui palindrom
        ci=1; cs=(DR-ST+1)/2; sol=0; //impar
        if ((DR-ST+1)%2==1) ++cs;
        while (ci<=cs) {
            mij=(ci + cs)/2; ok=0;
            for (int i=ST+mij-1; i<=DR-mij+1; ++i) {//mijlocul
                int L=LCP(i, n-i+1);
                if (L>=mij && verif(i-mij+1, i+mij-1)) {ok=1; break; }
            }
            if (ok) ci=mij+1, sol=mij;
                else cs=mij-1;
        }
        SOL=max(SOL, (short)(2*sol-1));

        ci=1; cs=(DR-ST+1)/2; sol=0; //par
        while (ci<=cs) {
            mij=(ci + cs)/2; ok=0;
            for (int i=ST+mij-1; i<=DR-mij; ++i) {//mijlocul
                int L=LCP(i+1, n-i+1);
                if (L>=mij && verif(i-mij+1, i+mij)) {ok=1; break; }
            }
            if (ok) ci=mij+1, sol=mij;
                else cs=mij-1;
        }
        SOL=max(SOL, (short)(2*sol));
        solutie[poz]=SOL;

        g<<solutie[poz]<<" ";
    }
    return 0;
}
