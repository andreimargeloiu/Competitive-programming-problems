# include <fstream>
# include <algorithm>
# include <cstring>
# include <vector>
# define NR 250
using namespace std;
ifstream f("pastila.in");
ofstream g("pastila.out");
vector <int> v1, v2;
int i,j,n,m,x,y,VV,t,mod,rr,l,S;
int mat[NR][105], a[NR], R[NR], uz[NR];
char s[NR];
void ProcesarePuteri3 ()
{
    mat[0][1]=mat[0][0]=1;
    for (int i=1; i<=210; ++i) {
        t=0; mat[i][0]=mat[i-1][0];

        for (j=1; j<=mat[i][0]; ++j) {
            t=t + mat[i-1][j]*3;
            mat[i][j]=t%10;
            t=t/10;
        }
        if (t) mat[i][++mat[i][0]]=t;
    }
}
void afisare (int k)
{
    for (int i=mat[k][0]; i>=1; --i)
        g<<mat[k][i];
}
int main ()
{
    f.getline (s+1, NR); l=strlen(s+1);
    // oglindim
    for (i=1; i<=l; ++i)
        a[i]=s[l-i+1] - '0';

    VV=-1;
    while (l)
    {
        S=0;
        for (i=1; i<=l; ++i)
            S+=a[i];
        mod=S-S/3*3;

        R[++VV]=mod;

        rr=0;
        //impartim numarul
        for (i=l; i>=1; --i) {
            rr=rr*10 + a[i];
            a[i]=rr/3;
            rr%=3;
        }
        while (l && a[l]==0) --l;
    }

    ProcesarePuteri3 ();

    //taler1 - pastila + gr
    //taler2 0 doar gr

    // acum avem descompunerea lui in baza 3
    for (i=0; i<=VV+1; ++i) {
        //daca e 3
        R[i+1]+=R[i]/3;
        R[i]%=3;

        if (R[i]==0) continue;
        else if (R[i]==1) v2.push_back(i);
        else if (R[i]==2) v1.push_back(i), ++R[i];

        R[i+1]+=R[i]/3; //poate e 3 acum
    }

    for (i=0; i<v1.size(); ++i) {
        afisare (v1[i]);
        g<<" ";
    }
    g<<"\n";

    for (i=0; i<v2.size(); ++i) {
        afisare (v2[i]);
        g<<" ";
    }
    g<<"\n";


    return 0;
}
