# include <fstream>
# include <cstring>
# define NR 10005
# define alpha 30
# define mod 666013
using namespace std;
ifstream f("cuvant.in");
ofstream g("cuvant.out");
int i,j,n,m,o,t,VV,L,x,k;
int ap[35], nr[35], c[1005][1005], a[30][1005];
char s[NR];
void combinari ()
{
    c[0][0]=1;
    for (int i=1; i<=1000; ++i)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1; j<i; ++j)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
}
int main ()
{
    f>>t; f.get();
    combinari ();
    for (o=1; o<=t; ++o)
    {
        f.getline (s+1, NR); n=strlen(s+1);
        f>>L; f.get();
        //init
        memset (ap, 0, sizeof(ap));
        memset (nr, 0, sizeof(nr));

        for (i=1; i<=n; ++i)
        {
            x=s[i]-'a'+1;
            ++ap[x];
        }
        VV=0;
        for (i=1; i<=alpha; ++i)
            if (ap[i]) nr[++VV]=min(ap[i], L);
        for (i=0; i<=28; ++i) a[i][0]=1;
        for (i=1; i<=VV; ++i)
            for (j=1; j<=L; ++j)
                a[i][j]=0;

        //a[i][j] = numarul de moduri de a scrie un cuvant de lungime j cu primele
        //          i litere disponibile
        //incepem dinamica
        for (i=1; i<=VV; ++i)
            for (j=1; j<=L; ++j)
                for (k=0; k<=nr[i]; ++k)
                    a[i][j]=(1LL*a[i][j]+1LL*a[i-1][j-k]*c[j][k])%mod;

        g<<a[VV][L]<<"\n";
    }

    return 0;
}
