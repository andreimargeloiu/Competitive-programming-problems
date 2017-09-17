# include <fstream>
# include <cstring>
# include <algorithm>
using namespace std;
ifstream f("palc.in");
ofstream g("palc.out");
int i,l,minn;
int a[500];
char s[205];
int verificare (int k)
{
    int i,ok=1;
    for (i=0; i<l/2; ++i)
        if (a[k+i]!=a[k+l-1-i]) ok=0;
    return ok;
}
int main ()
{
    f.getline(s,205);
    l=strlen(s);
    for (i=0; i<l; ++i)
        a[i+1]=a[i+l+1]=s[i];
    minn=999999;
    for (i=1; i<=l; ++i)
    {
        if (verificare (i))
        {
            minn=min(minn, min(i-1,l-i+1));
        }
    }
    if (minn==999999) g<<"-1\n";
        else g<<minn<<"\n";
    return 0;
}
