# include <fstream>
# include <algorithm>
# define NR 105
using namespace std;
ifstream f("circuit.in");
ofstream g("circuit.out");
int i,j,n,m,x,y,K,L,I,J,tip;
int dx[]={-1,-1,0,1,1,1,0,-1}, dx1[]={-1,0,1,0};
int dy[]={0,1,1,1,0,-1,-1,-1}, dy1[]={0,1,0,-1};
bool ap[NR][NR];
int c[NR*NR], C[NR*NR], X[35000], Y[35000];
void curata ()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            ap[i][j]=0;
}
bool verif1 (int l, int c, int x, int y)
{
    int lv, cv, i;
    for (i=0; i<9; ++i)
    {
        lv=l+dx[i]; cv=c+dy[i];
        if (lv==x && cv==y) return 1;
    }
    return 0;
}
bool verif2 (int l, int c, int x, int y)
{
    int lv, cv, i;
    for (i=0; i<4; ++i)
    {
        lv=l+dx1[i]; cv=c+dy1[i];
        if (lv==x && cv==y) return 1;
    }
    return 0;
}
bool circuit ()
{
    int i,j,ok,I,J,Iant=-5, Jant=-5;

    if (c[1]!=c[L]) return 0;
    C[1]=-5; sort (C+1, C+L+1);
    for (i=1; i<=L; ++i)
        if (C[i]==C[i-1]) return 0;

    I=X[c[1]]; J=Y[c[1]];
    ap[I][J]=1;

    for (i=2; i<=L; ++i)
    {
        if (verif1(I, J, X[c[i]], Y[c[i]])) i+=0;
            else return 0;
        if (verif2(Iant, Jant, X[c[i]], Y[c[i]])) return 0;

        Iant=I; Jant=J;
        I=X[c[i]]; J=Y[c[i]];
        ap[I][J]=1;
    }

    return 1;
}
void fill (int x, int y)
{
    int lv=0, cv=0;
    ap[x][y]=1;
    for (int i=0; i<4; ++i)
    {
        lv=x+dx1[i]; cv=y+dy1[i];
        if (ap[lv][cv]==0) fill(lv, cv);
    }
}
int suma ()
{
    int i,j,S=0;
    for (i=1; i<=n; ++i)
    {
        if (! ap[i][1]) fill(i, 1);
        if (! ap[i][m]) fill(i, m);
    }
    for (j=1; j<=m; ++j)
    {
        if (! ap[1][j]) fill(1, j);
        if (! ap[n][j]) fill(n, j);
    }

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (!ap[i][j]) ++S;

    return S;
}
int main ()
{
    f>>tip>>n>>m;

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            f>>x;
            X[x]=i; Y[x]=j;
        }

    //bordam
    for (i=0; i<=n+1; ++i)
        ap[i][0]=ap[i][m+1]=-1;
    for (i=0; i<=m+1; ++i)
        ap[0][i]=ap[n+1][i]=-1;

    f>>K;
    for (i=1; i<=K; ++i)
    {
        curata ();
        f>>L;
        for (j=1; j<=L; ++j)
           {f>>c[j]; C[j]=c[j];}

        if (circuit ()) //daca formeaza circuit
        {
            if (tip==1) g<<"1\n";
                   else g<<suma()<<"\n";
        }
        else { //daca nu are circuit
                 if (tip==1) g<<"0\n";
                       else  g<<"-1\n";
             }
    }

    return 0;
}
