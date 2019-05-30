#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
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
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2



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
const int maxn = (int)300+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
map < char , int >ci;
map < int , char > ic;
vector < int > g[100],res;
int n,inorder[100];
bool visited[100],f;
vector < char > cv;
void toposort(){


    for(int i=1 ; i<=n ; i++){
        if(inorder[i]==0 && !visited[i]){
            for(int k=0 ; k<g[i].size() ; k++){
                int v=g[i][k];
                inorder[v]--;
            }

            visited[i]=true;
            res.pb(i);
            toposort();

            res.pop_back();
            for(int k=0 ; k<g[i].size() ; k++){
                int v=g[i][k];
                inorder[v]++;
            }
            visited[i]=false;

        }
    }
        if(res.size()==n && n!=0){
            cout << ic[res[0]];
            for(int i=1 ; i<n ; i++){
                cout << " " << ic[res[i]];
            }cout << endl;
            //cout << endl;
            f=1;
            //cout <<"f : " << f <<endl;
        }
}

int main() {
    CIN
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t,done=1;
    cin >> t;

    cin.ignore();
    while(t--){
        string line;
        char x,c,y;
        getline(cin, line);
        getline(cin, line);

        //cout << "one : "<< line << endl;
        stringstream s1(line);
        getline(cin , line);
        //cout << "two : "<< line << endl;
        stringstream s2(line);

        while(s1>>c) cv.push_back(c);

        sort(all(cv));
        //cout <<"===="<< endl;
//        for(auto a:cv) cout<<a;
//        cout << endl;
        n=cv.size();
        int k=1;
        for(auto a:cv){
            ci[a]=k;
            ic[k]=a;
            k++;
        }


        while(s2>>x>> c >> y){
            int u,v;
            u=ci[x];
            v=ci[y];
            g[u].pb(v);
            inorder[v]++;
        }

        f=0;
        toposort();
        //cout << f <<"F " <<endl;
        if(f==0) cout <<"NO" << endl;
        if(t)cout << endl;

        memset(visited, 0, sizeof(visited));
        memset(inorder, 0, sizeof(inorder));
        res.clear();
        ic.clear();
        ci.clear();
        cv.clear();
        f1(i,n) g[i].clear();

    }
    return 0;
}

