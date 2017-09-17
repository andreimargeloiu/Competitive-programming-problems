# include <fstream>
# include <algorithm>
# include <cstring>
# define INF 999999999
# define NR 105
# define sigma 26
using namespace std;
ifstream f("bilete.in");
ofstream g("bilete.out");
int i,j,n,m,x,y,l,ci,cs,minim,k,len;
short minn[NR][NR][sigma], a[NR];
char s[NR];
int main ()
{
    f.getline (s+1, NR); l=strlen(s+1);
    for (i=1; i<=l; ++i) {
        if (s[i]!=s[i-1]) {
            a[++n]=s[i]-'A'+1;
        }
    }

    //minn[i][j][k] - numarul minim de mutari pt a forma biletele dintre i si j
    //                avand ca fundatie culoarea k

    for (i=1; i<n; ++i)
        for (k=1; k<=sigma; ++k)
            if (a[i]==k) minn[i][i][k]=0;
                    else minn[i][i][k]=1;
    for (len=1; len<=n; ++len)
        for (ci=1; ci+len<=n; ++ci) {
            for (k=1; k<=sigma; ++k) {
                cs=ci+len;
                if (a[cs]==k) minn[ci][cs][k]=minn[ci][cs-1][k];
                else { // punem un nou strat
                         minim=INF;
                         for (j=ci; j<=cs-1; ++j)
                         {
                            minim=min(minim, minn[ci][j][k] + minn[j+1][cs-1][a[cs]]);
                            ++x;
                         }

                         minn[ci][cs][k]=1+minim;
                     }

                i+=0;
            }
        }
    g<<x<<"\n";
    g<<min(1+minn[1][n][a[n]], 1+minn[1][n][a[1]])<<"\n";


    return 0;
}
