# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1000005
# define sigma 53
using namespace std;
ifstream f("incantatii.in");
ofstream g("incantatii.out");
int i,j,n,m,l,R;
long long P[15], v[NR], nr;
char s[15];
void puteri () {
    P[0]=1;
    P[1]=sigma;
    for (i=2; i<=10; ++i)
        P[i]=P[i-1]*sigma;
}
int main ()
{
    f>>n; f.get(); puteri ();
    for (i=1; i<=n; ++i) {
        f.getline (s+1, 10); nr=0;
        for (j=1; j<=9; ++j) {
            if (s[j]=='\0') break;
            if ('A'<=s[j] && s[j]<='Z') nr+=(s[j]-'A'+1)*P[9-j];
                                   else nr+=(s[j]-'a'+27)*P[9-j];
        }
        v[i]=nr;
    }

    sort (v+1, v+n+1);
    for (i=1; i<=n; ++i) {
        for (j=9; j>=0; --j)
            if (v[i]>=P[j]) {
                R=v[i]/P[j]; v[i]-=R*P[j];

                if (R<=26) g<<(char)('A'+R-1);
                      else g<<(char)('a'+R-27);
            }
        g<<"\n";
    }


    return 0;
}
