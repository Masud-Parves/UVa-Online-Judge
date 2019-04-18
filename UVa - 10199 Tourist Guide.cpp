#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics : Cut Vertex / Articulation Point
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 1<<28

int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)100+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
int n,m;
vector < int > g[maxn];
vector < int > save;
map < string , int > s2i;
map < int , string > i2s;
bool visited[maxn],cnt[maxn];
int low_tym[maxn],dis_tym[maxn];
int timer;

void dfs(int u, int p=-1){

    visited[u]=true;
    low_tym[u]=dis_tym[u]=timer++;
    int child=0;
    for(int i=0 ; i<SZ(g[u]) ; i++){
        int v=g[u][i];
        if(v==u){
            continue;
        }

        if(visited[v]){
            low_tym[u] = min(low_tym[u], dis_tym[v]);
        }
        else {

            dfs(v,u);

            if(p!=-1 && dis_tym[u]<=low_tym[v]){
                cnt[u]=1;
            }

            low_tym[u]=min(low_tym[u], low_tym[v]);
            child++;
        }
    }

    if(p==-1 && child > 1){
        cnt[u]=1;
    }

}


void Cut_Vertex(){
    f0(i,maxn){
        visited[i]=false;
        dis_tym[i]=-1;
        low_tym[i]=INF;
        cnt[i]=false;
    }
    timer=0;
    f1(i,n){
            if(!visited[i]){
                dfs(i);
            }
        }

}


int main() {
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s,u,v;
    int T=0;
    bool blank=false;

    while(cin >> n && n!=0){
        f0(i,n+1) g[i].clear();

        f1(i,n){
            cin >> s;
            s2i[s]=i;
            i2s[i]=s;
        }

        cin >> m;

        int x,y;
        while(m--){
            cin >> u >> v;
            x=s2i[u];
            y=s2i[v];
            g[x].pb(y);
            g[y].pb(x);
        }

        Cut_Vertex();
        vector < string > ans;
        f1(i,n){
            if(cnt[i]) ans.pb(i2s[i]);
        }

        sort(all(ans));
        if(blank) cout << endl;
        blank=true;
        cout << "City map #"<<++T<<": "<<ans.size()<<" camera(s) found"<< endl;
        f0(i,SZ(ans)) cout << ans[i] << endl;
        ans.clear();

    }

    return 0;
}



