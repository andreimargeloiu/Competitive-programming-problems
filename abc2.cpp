# include <fstream>
# include <cstring>
# include <vector>
# include <algorithm>
# define mod 666013
using namespace std;
ifstream f("abc2.in");
ofstream g("abc2.out");
vector <unsigned int> h[mod];
int i,j,l,L,VV,r,ok;
unsigned int var,nr,p;
char s[10000005],ch[25];
void citeste ()
{
    unsigned int nr;
    f.getline(s+1, 10000005);
    L=strlen(s+1);
    while (f.getline(ch+1,25))
    {
        l=strlen(ch+1);
        nr=0;
        for (i=1; i<=l; ++i)
            nr=nr*3+(ch[i]-'a');

        //inserez
        r=nr%mod; ok=1;
        for (i=0; i<h[r].size(); ++i)
            if (h[r][i]==nr) {ok=0; break;}
        if (ok) h[r].push_back(nr);
    }
}
int main ()
{
    int i,r;
    unsigned int var=0,p=1;
    citeste();
    for (i=1; i<=l; ++i)
    {
        var=var*3+(s[i]-'a');
        p*=3;
    }
    p/=3; r=var%mod;
    if (find(h[r].begin(), h[r].end(), var)!=h[r].end()) ++VV;
    for (i=l+1; i<=L; ++i)
    {
        var=(var-(s[i-l]-'a')*p)*3+(s[i]-'a');
        r=var%mod;
        for (int j=0; j<h[r].size(); ++j)
            if (h[r][j]==var) {++VV; break;}
    }
    g<<VV<<"\n";

    return 0;
}
