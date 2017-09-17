# include <bits/stdc++.h>
# define NR 100
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int i,j,n,m,val,aux,x,y,z;
char s[NR], s2[NR], s3[NR], t[NR], *p, sol;
int main ()
{
    f.getline (s, NR);
    p=strtok(p, ' ');
    while (p) {
        if ('A'<=p[0] && p[0]<='Z')
            sol[++k]=p[0];
        p=strtok(NULL, ' ');
    }
    g<<sol<<"\n";

    return 0;
}
