# include <fstream>
# include <algorithm>
# define NR 1005
using namespace std;
ifstream f("case.in");
ofstream g("case.out");
struct casa {
     long long x, y;
}a[NR], v[15][NR], st[NR];
struct sat {
    long long x, y, x2, y2;
}S[NR];

int i,j,n,T,sate,VV,I,luati,sol,J;
long long x, y, x2, y2, X, Y, l;
int nr[15];

bool cmp (casa x, casa y) {
    long long dx1, dx2, dy1, dy2, det1, det2;

    dx1=x.x - v[J][1].x;
    dy1=x.y - v[J][1].y;

    dx2=y.x - v[J][1].x;
    dy2=y.y - v[J][1].y;

    det1=dy1*dx2;
    det2=dy2*dx1;

    if (det1!=det2) return det1 < det2;
    else {
        if (x.x != y.x) return x.x < y.x;
                   else return x.y > y.y;
    }
}
long double det (casa a, casa b, casa c) {
    return a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y;
}
int infasuratoare (int J) {
    VV=2;
    st[1]=v[J][1]; st[2]=v[J][2];
    for (int i=3; i<=nr[J]; ++i) {
        while (VV>2 && det(st[VV-1], st[VV], v[J][i])<0)
            --VV;
        st[++VV]=v[J][i];
    }
    return VV;
}
int main ()
{
    f>>T;
    f>>n>>sate;
    for (i=1; i<=n; ++i)
        f>>a[i].x>>a[i].y;

    for (i=1; i<=sate; ++i) {
        f>>S[i].x>>S[i].y>>l;
        S[i].x2 = S[i].x + l;
        S[i].y2 = S[i].y + l;
    }

    //verific fiecare casa in ce sat apartine
    for (i=1; i<=n; ++i) { //casa
        X=a[i].x;  Y=a[i].y;
        for (j=1; j<=sate; ++j) { //sat
            x=S[j].x; y=S[j].y; x2=S[j].x2; y2=S[j].y2;

            if (x<=X && X<=x2 && y<=Y && Y<=y2) {
                ++nr[j]; ++luati;
                v[j][nr[j]] = a[i];
                break;
            }
        }
    }
    if (T==1) {
        g<<n-luati<<"\n";
        return 0;
    }

    for (j=1; j<=sate; ++j) {
        //caut cel mai din stanga jos punct
        if (nr[j]<3) continue;
        I=1; J=j;
        for (i=1; i<=nr[j]; ++i) {
            if (v[j][i].y < v[j][I].y) I=i;
            else if (v[j][i].y == v[j][I].y && v[j][i].x < v[j][I].x) I=i;
        }
        swap (v[j][1], v[j][I]);
        sort (v[j]+2, v[j]+nr[j]+1, cmp);

        sol+=infasuratoare (J);
    }
    g<<sol<<"\n";


    return 0;
}
