# include <fstream>
# include <cstring>
using namespace std;
ifstream f("parantezare.in");
ofstream g("parantezare.out");
int i,j,l,k,x,m;
int ap[100005],st[100005];
char s[100005];
int main ()
{
    f.getline(s,100005);

    l=strlen(s);
    for (i=0; i<l; ++i)
    {
        if (s[i]=='(') st[++k]=i;
        else if (s[i]==')')
        {
            ap[st[k]]=i;
            --k;
        }
    }
    f>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x;
        g<<ap[x]<<" ";
    }
    g<<"\n";
    return 0;
}
