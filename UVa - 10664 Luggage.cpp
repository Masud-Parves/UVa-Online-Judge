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
#define all(a)  a.begin(), a.end()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define mx  550
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define NOT_VISITED 0
#define IS_VISITED 1
#define D(x) cout<<#x " = "<<(x)<<endl



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
vector< int > v;

int DP[25][150];

int cal(int pos, int sum)
{

    if(sum==0)
        return 1;
    if(pos==v.size())
        return 0;

    int &res=DP[pos][sum];
    if(res!=-1)
        return res;
    int p=0,q=0;
    if(sum-v[pos]>=0)
        p=cal(pos+1,sum-v[pos]);

    q=cal(pos+1, sum);

    res=p|q;
    return res;
}



int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;

    getchar();
    TEST_CASE(t)
    {
        string str;
        getline(cin,str);
        stringstream ss;
        ss<<str;
        int val;
        int sum=0;
        while(ss>>val)
        {
            v.pb(val);
            sum+=val;
        }

        if(sum & 1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            memset(DP, -1, sizeof DP);
            if(cal(0,sum/2))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }
        v.clear();
    }


    return 0;
}

