# include <iostream>
# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1005
using namespace std;
ifstream f("marko.in");
ofstream g("marko.out");
int i,j,n,m,x,y,l,L,ok,solutie;
int a[NR][NR];
int cif[]={0,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
char S[NR], s[1000005],ch;
int main ()
{
    cin>>n; cin.get();
    for (i=1; i<=n; ++i) {
        cin.getline (s+1, 1000005);
        l=strlen(s+1); a[i][0]=min(1000, l);
        for (j=1; j<=a[i][0]; ++j)
            a[i][j]=cif[s[j]-'a'+1]+'0';
    }

    cin.getline (S+1, NR); L=strlen(S+1);
    for (i=1; i<=n; ++i) {
        if (a[i][0]>=L) {
            ok=1;

            for (j=1; j<=min(L, a[i][0]) && ok; ++j)
                if (S[j]!=a[i][j]) ok=0;

            solutie+=ok;
        }
    }

    cout<<solutie<<"\n";

    return 0;
}
