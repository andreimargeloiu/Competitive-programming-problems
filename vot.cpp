# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("vot.in");
ofstream g("vot.out");
vector <int> vect[1005];
struct elem
{
    char v1[100],v2[100];
}a[1005];
int i,j,n,m,v[1005],nr1,nr2,VV,nrsol,ok,ap[1005];
char s[105],*p,var[1005][55];
bool cmp (int x, int y)
{
    if (strcmp(var[x],var[y])>=0) return 0;
        else return 1;
}
void citire()
{
    f>>n; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline(s, 105);
        p=strtok(s,"-");
            strcpy(a[i].v1,p);

        strcpy(var[i],p); v[i]=i;

        p=strtok(NULL,"\0");
            strcpy(a[i].v2,p);
    }
    sort (v+1, v+n+1, cmp);
}
int cb (char s[100])
{
    int mij,ci=1,cs=n;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (strcmp(var[v[mij]],s)==0) return mij;
        if (strcmp(var[v[mij]],s)>0) cs=mij-1;
                                else ci=mij+1;
    }
}
void CULEGE (int k)
{
    ap[k]=-1; ++nrsol;
    if (ap[vect[k][0]]==VV) CULEGE(vect[k][0]);
}
void DFS (int k)
{
    if (!ok) return ;
    ap[k]=VV;
    if (ap[vect[k][0]]==VV)
    {
        CULEGE (vect[k][0]);
        ok=0;
        return ;
    }
    if (ap[vect[k][0]]!=-1) DFS (vect[k][0]);
}
int main ()
{
    citire();

    for (i=1; i<=n; ++i)
    {
        nr1=cb (a[i].v1);
        nr2=cb (a[i].v2);
        vect[nr1].push_back(nr2);
    }
    for (i=1; i<=n; ++i)
    {
        if (ap[i]!=-1)
        {
            ++VV; ok=1;
            DFS(i);
        }
    }
    g<<nrsol<<"\n";

    return 0;
}
