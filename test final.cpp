# include <bits/stdc++.h>
# define NR 100
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int i,j,n,m,val,x,y,z,k;
char s[NR], *p, sol[NR], aux[NR];
int main ()
{
    f.getline (s, NR);
    p=strtok(s, " ");
    while (p) {
        strcpy(aux, p);
        if ('A'<=aux[0] && aux[0]<='Z')
        {   sol[k]=aux[0]; ++k; }
        p=strtok(NULL, " ");
    }
    g<<sol<<"\n";
    g<<"abc";

    return 0;
}
