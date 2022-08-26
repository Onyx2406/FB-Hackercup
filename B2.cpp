#include <bits/stdc++.h>

using namespace std;

#define ll              long long int
#define rep0(i,n)       for(int i=0;i<n;i++)
#define rep1(i,n)       for(int i=1;i<=n;i++)
#define repl(i,a,b)     for(int i=a; i<b; i++)
#define rep11(i,a,b)    for(int i=a; i<=b; i++)
#define vi              vector<int>
#define vl              vector<ll>
#define vs              vector<string>
#define unmap           unordered_map<int,int> m;
#define pb              push_back
#define popb            pop_back
#define mp              make_pair
#define all(c)          c.begin(),c.end()
#define fastio()            ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define tc              ll tc;  cin>>tc;  while(tc--) 

const int N = 2e5 + 11;
/*--------------------------------------------------------------------------------------------------------------------------*/

int pow(int a,int b){if(!b){return 1;}int ans=pow(a,b/2); ans*=ans; if(b%2){return ans*=a;}return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}int lcm(int a,int b){return a/gcd(a,b)*b;}
int add(int a,int b,int m){return (a+b)%m;}
int sub(int a,int b,int m){return ((a-b)%m+m)%m;}
int mul(int a,int b,int m){return ((a%m)*(b%m))%m;}
/*--------------------------------------------------------------------------------------------------------------------------*/

void sort_dec(int &a ,int &b , int &c) //to sort a,b,c in decreasing order
{
    if (a<b) swap(a,b);
    if (a<c) swap(a,c);
    if (b<c) swap(b,c);
}
/*--------------------------------------------------------------------------------------------------------------------------*/

bool is_prime(int n){// This will check if given n is prime or not 
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i*i<=n;i=i+6){
        if (n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
/*--------------------------------------------------------------------------------------------------------------------------*/

// This will give prime factorization of 'n'
// 0(sqrt(n)/log(n))
// count of prime numbers is from 1 to n => (n/log(n))
vector<int> prime_fact(int n){
    vector<int> p,unique_p;
    if(n%2==0){
        unique_p.pb(2);
        while(n%2==0){
            p.pb(2),n/=2;
        }
    }
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            unique_p.pb(i);
            while(n%i==0){
                n/=i,p.pb(i);
            }
        }
    }
    if(n>1) p.pb(n),unique_p.pb(n);
//     return unique_p;
    return p;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i = 1; i<=n; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
/*--------------------------------------------------------------------------------------------------------------------------*/

ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
/*--------------------------------------------------------------------------------------------------------------------------*/

ll rootSqrt(ll x)
{
    // Base cases
    if (x == 0 || x == 1)
    return x;

    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    ll i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}
/*--------------------------------------------------------------------------------------------------------------------------*/

int32_t main()
{
    fastio()
    int T;
    cin>>T;
    int t=1;
    while(T--)
    {
        ll n,m;
        char a[10005][10005];
        int x=0;
        cin>>n>>m;
        int res1=0;

        rep0(i,n)
        {
            rep0(j,m)
            {
                cin>>a[i][j];
                if(a[i][j] == '^')
                {
                    x++;
                }
                if(a[i][j] == '#')
                {
                    res1++;
                }
            }
        }
        if(n == 1 && x!=0)
        {
            cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;
        }
        if(m == 1 && x!=0)
        {
            cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;
        }
        if(x == 0)
        {
            cout<<"Case #"<<t<<": "<<"Possible"<<endl;
            rep0(i,n)
            {
                rep0(j,m)
                {
                    cout<<a[i][j];
                }
                cout<<endl;
            }
            t++;
            continue;
        }
        int yes=0;
        rep0(i,n)
        {
            rep0(j,m)
            {
                int res=0;
                if(a[i][j] == '^')
                {
                    if(i>0){
                    if(a[i-1][j] == '#')
                    {
                        res++;
                    }}
                    if(j<m)
                    {
                    if(a[i][j-1] == '#')
                    {
                        res++;
                    }}
                    if(j+1<m)
                    {
                    if(a[i][j+1] == '#')
                    {
                        res++;
                    }}
                    if(i+1<n)
                    {
                    if(a[i+1][j] == '#')
                    {
                        res++;
                    }}
                    if(res >= 3)
                    {
                        yes=1;
                        break;
                    }
                }
            }
        }
        
        if(yes) {cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;}

        if(a[0][1] == '#' || a[1][0] == '#' && a[0][0] == '^')
        {
            cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;
        }
        if(a[n-2][0] == '#' || a[n-1][1] == '#' && a[0][m-1] == '^')
        {
            cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;
        }
        if(a[0][m-2] == '#' || a[1][m-1] == '#' && a[n-1][0] == '^')
        {
            cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;
        }
        if(a[n-1][m-2] == '#' || a[n-2][m-1] == '#' && a[n-1][m-1] == '^')
        {
            cout<<"Case #"<<t<<": "<<"Impossible"<<endl;  t++; continue;
        }

        int p=0,q=0,r=0,s=0;

        if(a[0][1] == '#' || a[1][0] == '#')
        {
            p=1;
        }
        if(a[n-2][0] == '#' || a[n-1][1] == '#')
        {
            q=1;
        }
        if(a[0][m-2] == '#' || a[1][m-1] == '#')
        {
            r=1;
        }
        if(a[n-1][m-2] == '#' || a[n-2][m-1] == '#')
        {
            s=1;
        }
        // cout<<a[1][m-1]<<endl;
        // cout<<r<<endl;
        rep0(i,n)
        {
            rep0(j,m)
            {
                if(i == 0 && j == 0 && a[0][0] == '.' && p != 0)
                {
                    continue;
                }
                if(i == n-1 && j == 0 && a[n-1][0] == '.' && q != 0)
                {
                    continue;
                }
                if(i == 0 && j == m-1 && a[0][m-1] == '.' && r != 0)
                {
                    continue;
                }
                if(i == n-1 && j == m-1 && a[n-1][m-1] == '.' && s != 0)
                {
                    continue;
                }
                if(i-1 >= 0 && a[i-1][j] != '#')
                {
                    if(i-1 == 0 && j == 0 && p == 0)
                    {
                        a[i-1][j]='^';
                    }
                }
                if(i+1 < n && a[i+1][j] != '#')
                {
                    if(i+1 == n-1 && j == 0 && q == 0)
                    {
                        a[i+1][j]='^';
                    }
                }
                if(j-1 >= 0 && a[i][j-1] != '#')
                {
                    if(j-1 == 0 && i == 0 && r == 0)
                    {
                        a[i][j-1]='^';
                    }
                }
                if(j+1 < m && a[i][j+1] != '#')
                {
                    if(i == 0 && j == m-1 && s == 0)
                    {
                        a[i][j+1]='^';
                    }
                }
                if(a[i][j] == '.')
                {
                    a[i][j]='^';
                }
            }
        }

        cout<<"Case #"<<t<<": "<<"Possible"<<endl;
        rep0(i,n)
        {
            rep0(j,m)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
        t++;

    }
  return 0;
}
