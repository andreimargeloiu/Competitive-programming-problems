# include <cstdio>
# include <algorithm>
# include <cstring>
# include <vector>
# define NR 10005
# define L 50005
using namespace std;
vector <int> v[55];
int i,j,n,VV,l,m,niv,poz,ci,cs,mij;
int grad[55];
long long R[NR],st[NR],nr;
char s[L];
int numar (int &poz)
{
    int nr=0;
    while (s[poz]!=' ' && poz<l)
    {
        nr=nr*10+(s[poz]-'0');
        ++poz;
    }
    ++poz;
    return nr;
}
void DFS (int k, int tata)
{
    if (v[k].size()==1) nr=nr*2;
    else {
             nr=nr*2+1;
             for (int i=0; i<v[k].size(); ++i)
                if (v[k][i]!=tata) DFS (v[k][i], k);
         }
}
int main ()
{
    freopen ("strict.in", "r", stdin);
    freopen ("strict.out", "w", stdout);
    scanf ("%d %d\n", &n, &m);
    for (i=1; i<=n; ++i)
    {
        getline(s, L); l=strlen (s);
        //init
        for (j=1; j<=m; ++j) {grad[j]=0; v[j].clear();}

        j=0; VV=0;
        while (j<l)
        {
            if (s[j]=='0') {++VV; j+=2;}
            else {
                     ++VV;
                     int nr1=numar (j); ++grad[nr1]; ++grad[VV];
                     int nr2=numar (j); ++grad[nr2]; ++grad[VV];
                     v[VV].push_back(nr1);
                     v[nr1].push_back(VV);

                     v[VV].push_back(nr2);
                     v[nr2].push_back(VV);
                 }
        }
        for (j=1; j<=VV; ++j)
            if (grad[j]%2==0)
            {
                nr=0;
                DFS (j, 0);
                R[i]=nr;
                break;
            }
    }
    for (i=1; i<=n; ++i)
    {
        if (st[niv]<=R[i]) st[++niv]=R[i];
        else {
                 ci=1; cs=niv; poz=niv;
                 while (ci<=cs)
                 {
                     mij=(ci+cs)/2;
                     if (st[mij]<=R[i]) ci=mij+1;
                     else cs=mij-1, poz=mij;
                 }
                 st[poz]=R[i];
             }
    }
    printf ("%d\n", niv);
    return 0;
}
