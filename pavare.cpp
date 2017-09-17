# include <fstream>
# include <algorithm>
# include <queue>
# define inf 9999999
using namespace std;
ifstream f("pavare.in");
ofstream g("pavare.out");
struct elem
{
    int l, nr;
}a[1<<16];
struct elem2
{
    int L, nr;
}E;
queue <elem2> q;
int i,j,n,m,K,VV,x,y,stari,k;
int mat[155][1<<16], l[155], pt[20];
void back (int k, int l, int nr)
{
    if (k==m+1)
    {
        ++VV;
        a[VV].l=l; a[VV].nr=nr;
    }
    else if (k<=m)
    {
        //lasam liber
        back (k+1, l, nr);

        //punem piesa aici
        back (k+2, l + pt[k] + pt[k+1], nr+1);
    }
}
void BFS ()
{
    int i,j;

    E.L=1; E.nr=l[1];
    mat[1][l[1]]=0;
    q.push(E);

    while (! q.empty())
    {
        E=q.front(); q.pop();
        i=E.L; j=E.nr;

        if (i>n) continue;

        if (mat[i+1][l[i+1]]<mat[i][j])
        {
            mat[i+1][l[i+1]]=mat[i][j];

            E.L=i+1; E.nr=l[i+1];
            q.push(E);
        }


        int act=(j | l[i]);

        for (k=1; k<=VV; ++k) //pentru fiecare linie noua pe care dorim sa o punem
        {
            if ((act & a[k].l)==0 && (l[i+1] & a[k].l)==0) // daca putem sa punem o noua linie
            {
                if (mat[i+1][l[i+1] | a[k].l] < mat[i][j]+a[k].nr)
                {
                    mat[i+1][l[i+1] | a[k].l] = mat[i][j]+a[k].nr;

                    E.L=i+1; E.nr=(l[i+1] | a[k].l);
                    q.push(E);
                }
            }
        }
    }
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=20; ++i)
        pt[i]=(1<<i);
    for (i=1; i<=K; ++i)
    {
        f>>x>>y;
        l[x]+=(pt[y]);
    }

    for (i=1; i<=n; ++i)
        for (j=0; j<=pt[m+1]; ++j)
            mat[i][j]=-inf;

    back(1, 0, 0);
    BFS ();

    g<<mat[n+1][0]<<"\n";

    return 0;
}
