# include <fstream>
# include <algorithm>
# include <vector>
# define NR 205
using namespace std;
ifstream f("angrenaj.in");
ofstream g("angrenaj.out");
struct elem
{
    int y;
    long long na, nb;
}E;
struct elem2
{
    long long p,q;
}a[NR];
vector <elem> v[NR];
int i,j,n,m,urm,mort;
int ap[NR];
long long na,nb,NA1,NB1,NA2,NB2,A,B,CMMDC;
long long cmmdc (long long a, long long b)
{
    long long R;
    while (b!=0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
void DFS (int k)
{
    if (mort) return;
    ap[k]=1;
    for (int i=0; i<v[k].size() && !mort; ++i)
    {
        urm=v[k][i].y; na=v[k][i].na; nb=v[k][i].nb;
        if (! ap[urm]) //acum o pun in miscare
        {
            a[urm].p=a[k].p*na*(-1); a[urm].q=a[k].q*nb;
            CMMDC=cmmdc(a[urm].p, a[urm].q);
            a[urm].p/=CMMDC;
            a[urm].q/=CMMDC;

            DFS (urm);
        }
        else { //doar verific
                 NA1=a[k].p*na*(-1); NB1=a[k].q*nb;
                 CMMDC=cmmdc (NA1, NB1);
                 NA1/=CMMDC; NB1/=CMMDC;

                 NA2=a[urm].p; NB2=a[urm].q;
                 CMMDC=cmmdc (NA2, NB2);
                 NA2/=CMMDC; NB2/=CMMDC;

                 if ((double)NA1/NB1 != (double)NA2/NB2) mort=1;
             }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>A>>B>>na>>nb;
        E.y=B; E.na=na; E.nb=nb; v[A].push_back(E);
        E.y=A; E.na=nb; E.nb=na; v[B].push_back(E);
    }
    a[1].p=1; a[1].q=1;

    DFS (1);
    if (mort)
    {
        for (i=1; i<=n; ++i)
            g<<"0 1\n";
        return 0;
    }

    for (i=1; i<=n; ++i)
    {
        if (ap[i]) g<<a[i].p<<" "<<a[i].q<<"\n";
              else g<<"0 1\n";
    }


    return 0;
}
