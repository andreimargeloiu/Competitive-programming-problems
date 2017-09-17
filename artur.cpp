# include <algorithm>
# include <iostream>
# include <fstream>
# include <vector>
# include <queue>
# define NR 10005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct elem {
    int x,y,x2,y2,i;
}a[NR];
bool cmp (elem x, elem y) {
    if (x.x >= y.x) return 0;
               else return 1;
}
vector <int> v[NR];
queue <int> q;
int i,j,n,mx,y,X,Y;
int grad[NR];
long long A,B,C;
void sortaret () {
    int k,i;
    while (! q.empty()) {
        k=q.front(); q.pop();
        cout<<k<<" ";

        for (i=0; i<v[k].size(); ++i) {
            --grad[v[k][i]];
            if (grad[v[k][i]]==0) q.push(v[k][i]);
        }
    }
    cout<<"\n";
}
int main ()
{
    cin>>n;
    for (i=1; i<=n; ++i) {
        cin>>a[i].x>>a[i].y>>a[i].x2>>a[i].y2;

        if (a[i].x > a[i].x2) {
            swap(a[i].x, a[i].x2);
            swap(a[i].y, a[i].y2);
        }

        a[i].i=i;
    }

    sort (a+1, a+n+1, cmp);

    for (i=1; i<=n; ++i) {
        for (j=i+1; j<=n; ++j) {
            if (a[j].x > a[i].x2) break;

            X=a[i].x2 - a[i].x;
            Y=a[i].y2 - a[i].y;

            A=Y; B=(-X); C=(1LL*a[i].y*X - 1LL*a[i].x*Y);

            if (A*a[j].x + B*a[j].y + C==0) {
                if (a[i].y<a[j].y)  v[a[i].i].push_back(a[j].i);
                               else v[a[j].i].push_back(a[i].i);
            }
            else if (A*a[j].x + B*a[j].y + C < 0) v[a[i].i].push_back(a[j].i);
                                        else v[a[j].i].push_back(a[i].i);
        }
    }

    //sortaret
    for (i=1; i<=n; ++i) {
        for (j=0; j<v[i].size(); ++j)
            ++grad[v[i][j]];
    }
    for (i=1; i<=n; ++i)
        if (grad[i]==0) q.push(i);

    sortaret ();

    return 0;
}
