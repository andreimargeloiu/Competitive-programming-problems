# include <fstream>
# include <algorithm>
# define NR 70000
using namespace std;
ifstream f("overdrive.in");
ofstream g("overdrive.out");
int i,j,n,v1,a[NR],VV1,VV2;
long long S, suma, ci, cs, mij, sol, a1[NR], a2[NR];

void submultimi (int k, int maxx)
{
    if (k==maxx+1)
    {
        if (maxx==v1) a1[++VV1]=suma;
        if (maxx==n) a2[++VV2]=suma;
    }
    else {
            submultimi (k+1, maxx); //nu il iau

            suma+=a[k];
            submultimi (k+1, maxx);  //il iau
            suma-=a[k];
         }
}

bool verifica (long long K)
{
    int I=VV2;

    for (i=1; i<=VV1; ++i) {
        while (I>=0 && a1[i] + a2[I]>K)
            --I;


        if (a1[i] + a2[I]<=K && S-a1[i]-a2[I]<=K) return 1; //solutie
    }
    return 0;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i];
        S+=a[i];
    }
    v1=n/2;

    submultimi (1, v1);
    submultimi (v1+1, n);

    sort (a1+1, a1+VV1+1);
    sort (a2+1, a2+VV2+1);

    ci=1; cs=S;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verifica (mij)) sol=mij, cs=mij-1;
            else ci=mij+1;
    }

    g<<sol<<"\n";



    return 0;
}
