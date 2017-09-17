# include <bits/stdc++.h>
# define NR 100005
# define sigma 30
using namespace std;
ifstream f("dorel.in");
ofstream g("dorel.out");
int i,j,n,m,ci,cs,mij,Q,poz,ST,DR,VV,LX,LY,ok;
int sol, SOL;
int pi[NR], X[NR], Y[NR], Lpar[NR], Limpar[NR], v[2*NR], P[2*NR];
int minn[sigma], maxx[sigma], st[NR], dr[NR], solutie[NR];
char s[NR];

void preprocesare () {
    int var;
    for (int i=1; i<=n; ++i) { //stanga
        int CH=s[i] - 'a' + 1; var=1;
        for (int j=CH; j<=sigma; ++j)
            var=max(var, maxx[j]);
        st[i]=var; maxx[CH]=i;
    }

    for (int i=n; i>=1; --i) { //dreapta
        int CH=s[i] - 'a' + 1; var=n;
        for (int j=CH; j>=1; --j)
            if (minn[j]!=0) var=min(var, minn[j]);
        dr[i]=var; minn[CH]=i;
    }
}
void manacher () {
    int CI=0, CS=0, mid=0, poz;
    for (i=1; i<=n; ++i) {
        v[++VV]='$';
        v[++VV]=s[i];
    }
    v[++VV]='$';
    for (i=1; i<=VV; ++i) {
        if (CS<i) {
            CI=CS=i; P[i]=1; mid=i;
            while (1<CI && CS<VV && v[CI-1]==v[CS+1]) {
                ++P[i];
                --CI; ++CS;
            }
        } else {
            int poz=mid - (i-mid);
            if (poz - P[poz] + 1==CI) {
                P[i]=P[poz]; mid=i;
                CI=i-(CS-i);
                while (1<CI && CS<VV && v[CI-1]==v[CS+1]) {
                    ++P[i];
                    --CI; ++CS;
                }
            } else P[i]=min(P[poz], CS-i+1);
        }
    }
    int lp=0, li=0;
    for (int i=2; i<VV; ++i) {
        if (v[i]=='$') Lpar[++lp]=P[i]/2;
                  else Limpar[++li]=P[i]/2;
    }
}
void make_aux (int st, int dr) {
    LX=0;
    for (int i=1; i<=n; ++i)
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
    f.getline (s+1, NR); n=strlen(s+1);
    preprocesare (); manacher ();
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
            for (int i=ST+mij-1; i<=DR-mij+1; ++i) //mijlocul
                if (Limpar[i]>=mij && verif(i-mij+1, i+mij-1)) {ok=1; break; }

            if (ok) ci=mij+1, sol=mij;
                else cs=mij-1;
        }
        SOL=max(SOL, 2*sol-1);

        ci=1; cs=(DR-ST+1)/2; sol=0; //par
        while (ci<=cs) {
            mij=(ci + cs)/2; ok=0;
            for (int i=ST+mij-1; i<=DR-mij; ++i) //mijlocul
                if (Lpar[i]>=mij && verif(i-mij+1, i+mij)) {ok=1; break; }

            if (ok) ci=mij+1, sol=mij;
                else cs=mij-1;
        }
        SOL=max(SOL, 2*sol);
        solutie[poz]=SOL;

        g<<solutie[poz]<<" ";
    }
    return 0;
}
