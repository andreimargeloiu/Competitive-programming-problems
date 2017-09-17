# include <fstream>
# include <algorithm>
# include <cstring>
# define alpha 26
# define NR 1605
# define inf 999999999
using namespace std;
ifstream f("mesaj.in");
ofstream g("mesaj.out");
int i,j,n,m,k,ok,minn,last,poz;
int a[NR], L[NR], ant[NR][alpha+2], var[alpha+2];
char mat[NR][25], s[NR];
int main ()
{
    f>>n>>m; f.get();
    f.getline(s+1, NR);

    for (i=1; i<=n; ++i)
    {
        f.getline (mat[i]+1, NR);
        L[i]=strlen(mat[i]+1);
    }
    // preprocesam pozitia fiecarei litere anterioare in vectorul var
    for (i=1; i<=m; ++i)
    {
        for (j=1; j<=alpha; ++j)
            ant[i][j]=var[j];

        var[s[i]-'a'+1]=i;
    }

    for (i=1; i<=m; ++i) // fiecare pozitie
    {
        a[i]=a[i-1]+1;
        for (j=1; j<=n; ++j) // fiecare cuvant
        {
            if (L[j]>i) continue;
            if (L[j]==1) // o litera
            {
                if (s[i]==mat[j][1]) a[i]=min (a[i], a[i-1]);
                                else a[i]=min (a[i], a[i-1]+1);
            }
            else // are minim 2 litere
            {
                if (mat[j][L[j]]==s[i]) // daca cuvantul ala se termina pe pozitia i
                {
                    ok=1;
                    poz=ant[i][mat[j][L[j]-1]-'a'+1];

                    for (k=L[j]-1; k>=1; --k)
                    {
                        last=poz;
                        if (poz==0) {ok=0; break;}
                        poz = ant[poz][mat[j][k-1]-'a'+1];
                    }

                    if (ok) a[i]=min(a[i], a[last-1]+i-last+1-L[j]);
                }
                else a[i]=min(a[i], a[i-1]+1);
            }
        }
    }

    g<<a[m]<<"\n";

    return 0;
}
