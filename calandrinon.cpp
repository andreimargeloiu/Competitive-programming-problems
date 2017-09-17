# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 3000005
using namespace std;
ifstream f("calandrinon.in");
ofstream g("calandrinon.out");
int i,j,n,m,VAR,ci,cs,sol,t,I;
int dif[NR], mars[NR], ap[200], last[200], luat[200];
char s[NR];
int main ()
{
    f.getline (s+1, NR); n=strlen(s+1);


    // dif[i]- cate sunt diferite la dreapta de i

    for (i=n; i>=1; --i) {
        dif[i]=dif[i+1];

        ++ap[s[i]];

        if (ap[s[i]]==1) {
           ++dif[i];
           last[s[i]]=i;
        }
    }

    memset (ap, 0, sizeof(ap));
    ci=1; cs=0; sol=dif[1];

    for (t=sol; t>=1; --t) {
        // adaug din dreapta
        while (cs<n) {
            if ((dif[cs+1] + VAR + mars[cs+1])==t) {
                  ++cs; VAR+=mars[cs];
                  ++ap[s[cs]];
            }
            else break;
        }

        // caut minimul
        for (i='a'; i<='z'; ++i)
            if (ap[i]>0 && luat[i]==0) { I=i; break; }

        while (s[ci]!=I) {
            --ap[s[ci]];
            ++ci;
        }
        luat[I]=1; ++ci;
        --VAR; VAR+=mars[ci];
        ++mars[last[I]+1];

        g<<(char)I;
    }

    return 0;
}
