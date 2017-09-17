# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("cumpanit.in");
ofstream g("cumpanit.out");
int i,j,n,m,VV,K,R,S;
int st[100],st2[100];
long long a,b,mat[100][100],sol[10000];
int prim[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,49};
void init ()
{
    int i,j;
    for (i=1; i<=n; ++i)
    {
        long long nr=1;
        for (j=1; j<=50; ++j)
        {
            nr=nr*prim[i];
            if (nr>b) break;
            mat[i][j]=nr;
        }
    }
}
void generare (int k)
{
    int i;
    if (k==K && K>1)
    {
        st2[k]=R;
        long long NR=1;
        for (i=1; i<=K; ++i)
        {
            NR=NR*mat[st[i]][st2[i]];
            if (NR>b) break;
        }
        if (a<=NR && NR<=b) sol[++VV]=NR;
        st2[k]=0;
    }
    else
    {
        for (i=1; i<=R; ++i)
        {
            if (! mat[st[k]][i]) break;
            st2[k]=i; R-=i;
            if (R) generare(k+1);
            st2[k]=0; R+=i;
        }
    }
}
void back (int k)
{
    int i;
    if (k==K+1)
    {
        R=S;
        generare (1);
    }
    else {
             for (i=st[k-1]+1; i<=n; ++i)
             {
                 if (S+prim[i]>50) break;

                 st[k]=i; S+=prim[i];
                 back(k+1);
                 st[k]=0; S-=prim[i];
             }
         }
}
int main ()
{
    f>>a>>b; n=15;
    init();
    for (i=1; i<=n; ++i)
        if (a<=mat[i][prim[i]] && mat[i][prim[i]]<=b) sol[++VV]=mat[i][prim[i]];

    for (K=2; K<=5; ++K)
        back(1);

    sort(sol+1, sol+VV+1);
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<"\n";

    return 0;
}
