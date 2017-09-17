# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 505
using namespace std;
ifstream f("siruri2.in");
ofstream g("siruri2.out");
int i,j,n,m;
int a[NR][NR];
char s1[NR], s2[NR];
int minim (int a, int b, int c)
{
    return min(a, min(b, c));
}
int main ()
{
    f.getline (s1+1, NR); n=strlen(s1+1);
    f.getline (s2+1, NR); m=strlen(s2+1);

    //init
    for (i=1; i<=n; ++i)
    {
        a[i][0]=i;
        if ('A'<=s1[i] && s1[i]<='Z')
        {
            s1[i]=s1[i]-'A'+'a';
        }
    }
    for (i=1; i<=m; ++i)
    {
        a[0][i]=i;
        if ('A'<=s2[i] && s2[i]<='Z') s2[i]=s2[i]-'A'+'a';
    }
    for (j=1; j<=m; ++j)
    {
        for (i=1; i<=n; ++i)
        {
            if (s1[i]==s2[j]) a[i][j]=a[i-1][j-1];
            else {
                    //adaugam un element
                    a[i][j]=minim (a[i-1][j]+1, a[i][j-1]+1, a[i-1][j-1]+1);
                 }
        }
    }
    g<<a[n][m];

    return 0;
}
