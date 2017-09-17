# include <fstream>
# include <algorithm>
# include <vector>
# include <bitset>
# include <queue>
# define NR 185000
using namespace std;
ifstream f("albinuta.in");
ofstream g("albinuta.out");
struct elem
{
    int timp, nod;
}E;
queue <elem> q;
int i,j,n,m,x,y,k,cmmmc,Q,I,T,VV,H;
int L[55], a[55][55], st[NR];
bitset <NR> ap[55];

int cmmdc (int a, int b)
{
    int R=0;
    while (b>0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
void determinare ()
{
    int k,timp,urm;

    E.nod=1; E.timp=1;
    ap[1][1]=1; //ap[nod][timp]

    q.push(E);

    while (! q.empty())
    {
        E=q.front(); q.pop();

        k=E.nod; timp=E.timp;
        st[++VV]=k;

        //mergem in urmatorul
        if (timp==1) urm=a[k][1];
        else urm=a[k][1 + (timp-1)%L[k]];

        timp=timp+1;
        if (timp>cmmmc) timp-=cmmmc;

        if (ap[urm][timp]) //am gasit ciclul
        {
            I=urm; T=timp;

            E.nod=urm; E.timp=timp;
            st[++VV]=urm;
            break;
        }
        else { // inca mai incercam
                ap[urm][timp]=1;
                E.nod=urm; E.timp=timp;
                q.push(E);
             }
    }
}
int main ()
{
    f>>n>>Q;

    cmmmc=1;

    for (i=1; i<=n; ++i)
    {
        f>>L[i];
        cmmmc=cmmmc * L[i] / cmmdc(cmmmc, L[i]);

        for (j=1; j<=L[i]; ++j)
            f>>a[i][j];
    }

    determinare ();

    for (i=1; i<=VV; ++i)
        if (st[i]==I && i==T)
        {
            H=i;
            break;
        }

    for (i=1; i<=Q; ++i)
    {
        f>>x;
        if (x<=VV) g<<st[x]<<"\n";
        else g<<st[H + 1 + (x-H-1)%(VV-H)]<<"\n";
    }

    return 0;
}
