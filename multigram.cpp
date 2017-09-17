# include <fstream>
# include <iostream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
//ifstream f("multigram.in");
//ofstream g("multigram.out");
int i,j,n,m,ci,cs,mij,sol,D;
int ap[30], ap2[30], a[NR], AP[30];
char S[NR];
bool bun (int K) {
    memset (ap, 0, sizeof(ap));

    int i, j, nr=n/K;
    for (i=1; i<=K; ++i) ++ap[S[i]];

    for (j=2; j<=nr; ++j) {
        memset (ap2, 0, sizeof(ap2));

        for (i=(j-1)*K+1; i<=j*K; ++i)
            ++ap2[S[i]];

        for (i=1; i<=26; ++i)
            if (ap[i] != ap2[i]) return 0;
    }

    return 1;
}
void aparitii()
{
    int ok;
    for (int i=1; i<=n; ++i) {
        ok=1;
        for (j=1; j<=26 && ok; ++j)
            if (AP[j]!=0 && AP[j]%i!=0) ok=0;

        if (ok && n%i==0) a[++D]=n/i;
    }
    sort (a+1, a+D+1);
}
int main () {
    cin.getline (S+1, NR); n=strlen(S+1);
    for (i=1; i<=n; ++i) {
        S[i]=S[i]-'a'+1;
        ++AP[S[i]];
    }

    aparitii ();

    for (i=1; i<=D && a[i]<n; ++i) {
        if (bun(a[i])) {
            for (int j=1; j<=a[i]; ++j)
                cout<<(char)(S[j]+'a'-1);
            cout<<"\n";

            return 0;
        }
    }

    cout<<"-1\n";

    return 0;
}
