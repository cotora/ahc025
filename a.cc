#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cassert>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
//#include <atcoder/all>
#endif

using namespace std;
//using namespace atcoder;
#define INF 2e9
#define repi(n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define uset unordered_set
#define umap unordered_map
typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef vector<bool> vb;
typedef vector< vector<bool> > vvb;
typedef vector<double> vd;
typedef vector< vector<double> > vvd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct Edge{
    int to;
    ll w;
    Edge(int to,ll w):to(to),w(w){}
};

using Graph=vector<vector<Edge>>;

template <typename T>
bool chmin(T &x,T y){
    if(x>y){
        x=y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &x,T y){
    if(x<y){
        x=y;
        return true;
    }
    return false;
}

template <typename T>
string toBinary(T x){
    string res="";
    while(x!=0){
        if(x&1){
            res="1"+res;
        }
        else{
            res="0"+res;
        }
        x=x>>1;
    }
    return res;
}

int toDecimal(string s){
    int res=0;
    int d=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            res+=d;
        }
        d*=2;
    }
    return res;
}

//O(logn)
ll pow_origin(ll x,ll n){
    ll ret=1;
    while(n>0){
        if(n&1)ret=ret*x;
        x=x*x;
        n>>=1;
    }
    return ret;
}

template <typename T>
void printVector(vector<T> &x){
    for(auto i : x)cout<<i<<" ";
    cout<<endl;
}

template <typename T>
void printVector2d(vector< vector<T> > &x){
    for(auto &i : x){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void printYesOrNo(bool x){
    cout<<(x ? "Yes" : "No")<<endl;
}

struct Item{

};

double eval(){

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(15);
    int N,D,Q;
    cin>>N>>D>>Q;
    //ランダムにD個に分ける
    vvi ss(D);
    for(int i=0;i<N;i++){
        ss[i%D].push_back(i);
    }
    vi ans(N);
    for(int i=0;i<D;i++){
        for(auto v : ss[i]){
            ans[v]=i;
        }
    }
    while(Q--){
        cout<<1<<" "<<1<<" "<<0<<" "<<1<<endl;
    }
    printVector(ans);
    return 0;
}