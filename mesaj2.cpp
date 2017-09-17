# include <bits/stdc++.h>
# define NR 1505
using namespace std;
ifstream f("mesaj2.in");
ofstream g("mesaj2.out");
int i,j,n,m,L,l,I;
short URM[130][NR], urm[130], minn[NR];
char S[NR], s[NR];
void procesare () {
    for (int i=1; i<=127; ++i)
        urm[i]=L+1;

    for (int i=L+1; i>=1; --i) {
        if (i!=L+1) urm[S[i]]=i;
        for (int j=1; j<=127; ++j)
            URM[j][i]=urm[j];
    }

    for (int i=1; i<=L; ++i)
        minn[i]=L+1;
}
void update (char *word) {
    int poz,VV,j;
    char *p;
    for (int i=1; i<=L; ++i) {
        j=i-1; p=word;

        while (*p  && j<minn[i]) {
            j=URM[(int)(*p)][j+1];
            ++p;
        }

        if (minn[i] > j) minn[i]=j;
    }
}
int query () {
    int sol=0;

    for (int i=1; i<=L && minn[i]<=L; i=minn[i]+1)
        ++sol;

    return sol;
}
int main ()
{
    f.getline (S+1, NR); L=strlen(S+1);
    procesare ();
    f>>n; f.get();
    for (i=1; i<=n; ++i) {
        f.getline(s+1, NR);
        update (s+1);
        g<<query ()<<"\n";
    }

    return 0;
}
