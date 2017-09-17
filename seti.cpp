# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 600005
using namespace std;
ifstream f("seti.in");
ofstream g("seti.out");
struct elem {
    int nr1, nr2, i;
}var[NR];
bool cmp (elem x, elem y) {
    if (x.nr1 > y.nr1) return 0;
        else if (x.nr1==y.nr1 && x.nr2 >= y.nr2) return 0;
            else return 1;
}
int i,j,n,m,l,l2,ci,cs,VV;
int P[6][NR], ind[NR], lg[100];
char a[NR+50], s[2050], s2[100];

void logaritmi () {
    for (int i=2; i<=64; ++i)
        lg[i]=lg[i/2] + 1;
}
short identic (int k) {
    for (int i=1; i<=l2; ++i)
        if (s2[i] < a[ind[k]+i-1]) {
            return -1;
        }
        else if (s2[i] > a[ind[k]+i-1]) {
            return 1;
        }

    return 0;
}
int inferior () {
    int ci=1, cs=l, mij, i, sol=0;
    while (ci<=cs) {
        mij=(ci+cs)/2;

        if (identic (mij)<=0) cs=mij-1, sol=mij;
                         else ci=mij+1;
    }
    if (identic(sol)==0) return sol;
                      else return 0;
}
int superior () {
   int ci=1, cs=l, mij, i, sol=0,ok;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        ok=identic (mij);
        if (ok<0) cs=mij-1;
             else ci=mij+1, sol=mij;
    }
    if (identic(sol)==0) return sol;
                      else return 0;
}
int main ()
{
    logaritmi ();

    f>>n; f.get();
    for (i=1; i<=n; ++i) {
        f.getline (s+1, 2050);
        j=1;
        while (s[j]!='\0') {
            a[++l]=s[j];
            ++j;
        }
    }
    for (i=1; i<=64; ++i)
        a[l+i]='$';

    //suffix array
    for (i=1; i<=l; ++i)
        P[0][i]=a[i];

    for (j=1; j<=4; ++j) {
        for (i=1; i<=l; ++i) {
            var[i].nr1=P[j-1][i];
            var[i].nr2=P[j-1][i+(1<<(j-1))];
            var[i].i=i;
        }
        sort (var+1, var+l+1, cmp);

        VV=0;
        for (i=1; i<=l; ++i) {
            if (j==4) ind[i]=var[i].i;

            if (var[i].nr1!=var[i-1].nr1 || var[i].nr2!=var[i-1].nr2)
                ++VV;

            P[j][var[i].i]=VV;
        }
    }
    f>>m; f.get();
    for (i=1; i<=m; ++i) {
        f.getline (s2+1, 100); l2=strlen(s2+1);

        ci=inferior ();
        cs=superior ();
        if (ci!=0) g<<cs-ci+1<<"\n";
              else g<<"0\n";
    }

    return 0;
}
