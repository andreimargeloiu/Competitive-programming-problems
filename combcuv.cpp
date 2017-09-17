# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 205
# define N 105
# define L 35
using namespace std;
ifstream f("combcuv.in");
ofstream g("combcuv.out");
int i,j,n,m,x,y,p,q,k,F,VV,ll,ok;
int l[N], a[L][L];
char S[NR], s[N][L];
int main ()
{
    f.getline(S+1, NR); ll=strlen(S+1);
    f>>n; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline (s[i]+1, L);
        l[i]=strlen(s[i]+1);
    }
    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
        {
            ok=0;
            for (k=1; k<=ll-l[i]-l[j]+1; ++k)
            {

                if (s[i][1]==S[k] || s[j][1]==S[k]) //daca e posibil ca sirul sa inceapa de aici
                {
                     F=k-1; a[0][0]=1;

                     for (p=0; p<=l[i]; ++p)
                         for (q=0; q<=l[j]; ++q)
                         {
                             if (p==0 && q==0) continue;
                             else {
                                      if ((p>0 && a[p-1][q]==1 && s[i][p]==S[F+p+q]) || (q>0 && a[p][q-1]==1 && s[j][q]==S[F+p+q]))
                                              a[p][q]=1;
                                         else a[p][q]=0;
                                  }
                         }
                     if (a[l[i]][l[j]]==1) ++VV, ok=1;
                }
                if (ok) break;
            }
        }
    g<<VV<<"\n";

    return 0;
}
