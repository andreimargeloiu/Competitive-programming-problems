# include <fstream>
# include <cstring>
# include <algorithm>
using namespace std;
ifstream f("dp.in");
ofstream g("dp.out");
int i,j,n,cs,l,ok,o;
char s[105],v1[105],v2[105];
int mutare (int k)
{
    int i,poz=-1;
    for (i=k; i<l; ++i)
        v2[++poz]=v1[i];
    for (i=0; i<k; ++i)
        v2[++poz]=v1[i];
    if (strcmp(v1,v2)>0) return 0;
        else return 1;
}
int main ()
{
    f.getline(s,105);
    n=strlen(s);
    while (cs!=n)
    {
        for (i=n-1; i>=cs; --i)
        {
            ok=1; //pp ca nu am gasit
            if (i==cs)
            {
                cs=i+1;
                g<<"("<<s[i]<<")";
                break;
            }
            //fac vectorul
            int poz=-1;
            for (j=cs; j<=i; ++j)
                v1[++poz]=s[j];
            v1[++poz]='\0'; v2[poz]='\0';

            l=poz;
            //pt fiecare miscare circulara
            for (o=1; o<=l-1; ++o)
                ok=min(ok,mutare(o));

            if (ok)
            {
                cs=i+1; g<<"(";
                for (o=0; o<l; ++o)
                    g<<v1[o];
                g<<")";
                break;
            }
        }
    }
    return 0;
}
