# include <fstream>
# include <cstring>
# include <algorithm>
# define lmax 5005
# define nmax 105
# define alpha 28
using namespace std;
ifstream f("search.in");
ofstream g("search.out");
int i,j,n,m,lvl,VV,l,o,k,ant;
int ap[nmax][lmax][alpha]; // a[i][j][k] - pe ce pozitie apare litera k dupa pozitia j in numarul i
int st[nmax][lmax];
char ch, s[lmax];
void preprocesare ()
{
    int i,j,o;
    for (i=1; i<=n; ++i)
    {
        f.getline (s+1, lmax); l=strlen(s+1);
        for (j=l; j>=1; --j)
        {
            k=s[j]-'a'+1;
            for (o=1; o<=alpha; ++o)
                ap[i][j][o]=ap[i][j+1][o];

            ap[i][j][k]=j;
        }
    }
}
void avansare (int k)
{
    int i; ++lvl;
    if (lvl>lmax) return;
    for (i=1; i<=n; ++i)
    {
        ant=st[i][lvl-1];
        if ((ant==0 && lvl==1) || ant) st[i][lvl]=ap[i][ant+1][k];
    }
}
void sterge ()
{
    for (int i=1; i<=n; ++i)
        st[i][lvl]=0;
    --lvl;
}
int main ()
{
    f>>n>>m; f.get();

    preprocesare ();

    for (o=1; o<=m; ++o)
    {
        f>>ch; f.get();
        if (ch=='-') sterge ();
        else avansare (ch-'a'+1);

        VV=0;
        for (i=1; i<=n; ++i)
            if (st[i][lvl]) ++VV;

        g<<VV<<"\n";
    }

    return 0;
}
