# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 1000005
using namespace std;
ifstream f("paranteze2.in");
ofstream g("paranteze2.out");
int a[NR],st[NR],i,j,n,m,niv;
long long sol;
char s[NR];
int main ()
{
    f.getline (s+1, NR); n=strlen(s+1);
    //nr[i]-numarul de subsecvente corecte care se termina in pozitia i
    for (i=1; i<=n; ++i)
    {
        if (s[i]=='(') st[++niv]=i;
        else { //  ')'
                 if (niv) {//trebuie sa calculam
                              a[i]=a[st[niv]-1]+1;
                              --niv;
                              sol+=a[i];
                          }
             }
    }
    g<<sol<<"\n";

    return 0;
}
