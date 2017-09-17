# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 1005
using namespace std;
ifstream f("expresie.in");
ofstream g("expresie.out");
int i,j,n,m,VV,S;
char s[NR];
int numar ()
{
    int nr=0;
    while ('0'<=s[VV] && s[VV]<='9')
        { nr=nr*10+s[VV]-'0'; ++VV; } //include trecerea de ]
    return nr;
}
int base ()
{
    int nr=0;
    if (s[VV]=='[') //e un nou [
    {
        while (s[VV]=='[')
        {
            ++VV; //trec direct peste '['
            nr+=base();
        }
        ++VV; //sa trec de ]
    }
    else //este numar
    {
        nr=numar();
        ++VV; //trec de la un nou [
    }
    return nr/2;
}
int main ()
{
    f.getline(s+1, NR); n=strlen(s+1);
    VV=1;
    while (VV<=n)
    {
       ++VV; //trec direct peste '['
       S+=base ();
    }

    g<<S<<"\n";

    return 0;
}
