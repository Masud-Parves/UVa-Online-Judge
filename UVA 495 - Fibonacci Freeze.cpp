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
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)

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
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
string fib[5001];

string add(string s1, string s2)
{

    string sum="";
    char ch;
    if(s1.size()<s2.size())
        swap(s1,s2);
    ///largest string s1
    int lenS1 = (int) s1.size(), lenS2=(int) s2.size();

    int ds=0,rem=0,carry=0;
    for(int i=0 ; i<lenS2 ; i++)
    {
        ds=s1[lenS1-i-1]-'0'+s2[lenS2-i-1]-'0'+carry;
        rem=ds%10;
        ch=rem+'0';
        sum+=ch;
        carry=ds/10;
    }
    int len=0;
    if(lenS1>lenS2)
    {
        len=lenS1-lenS2;
    }
    for(int i=len-1 ; i>=0 ; i--)
    {
        ds=s1[i]-'0'+carry;
        rem=ds%10;
        ch=rem+'0';
        sum+=ch;
        carry=ds/10;

    }
    if(carry!=0)
        sum+=carry+'0';
    reverse(all(sum));

    return sum;
}

void precalc()
{
    fib[0]="0";
    fib[1]="1";
    for(int i=2; i<5001; ++i)
    {
        fib[i] = add(fib[i-1],fib[i-2]);

    }
}
int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    precalc();
    int n;
    while(cin>>n){
        cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
    }
    return 0;
}

