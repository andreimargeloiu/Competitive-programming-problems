# include <bits/stdc++.h>
# define NR 100
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int i,j,n;
char s[NR], s1[NR], s2[NR];
int main ()
{
    f>>s;
    strncpy(s1, s, 5);
    g<<s1<<"\n";



    return 0;
}
