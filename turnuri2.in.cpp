# include <fstream>
# include <vector>
# include <algorithm>
# include <cstring>
# define NR 1000005
# define inf  1000000005
using namespace std;
ifstream f("turnuri2.in");
ofstream g("turnuri2.out");
int i,j,n,m,k,VV;
int H[NR], ant[NR], st[NR], dreapta[NR], K[NR], stanga[NR];
int main ()
{
    f>>n;
    H[0]=H[n+1]=inf;
    for (i=1; i<=n; ++i) //citim si facem la stanga
    {
        f>>H[i]>>K[i]; stanga[i]=dreapta[i]=K[i];
        while (VV>0 && H[i]>=H[st[VV]])
            --VV;

        ant[i]=st[VV];
        st[++VV]=i;
    }
    //la stanga
    for (i=1; i<=n; ++i)
    {
        if (i>1) stanga[i]=max(stanga[i], K[i-1]);
        k=i-1;
        while (H[k]<=H[i])
        {
            stanga[i]=max(stanga[i], stanga[k]);
            k=ant[k];
        }
    }

    //la dreapta
    VV=0; st[VV]=n+1;
    for (i=n; i>=1; --i)
    {
        while (VV>0 && H[i]>=H[st[VV]])
            --VV;

        ant[i]=st[VV];
        st[++VV]=i;
    }

    for (i=n; i>=1; --i)
    {
        if (i<n) dreapta[i]=max(dreapta[i], K[i+1]);
        k=i+1;
        while (H[k]<=H[i])
        {
            dreapta[i]=max(dreapta[i], dreapta[k]);
            k=ant[k];
        }
    }

    for (i=1; i<=n; ++i)
        g<<max(K[i], max(stanga[i], dreapta[i]))<<"\n";

    return 0;
}
