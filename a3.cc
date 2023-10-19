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


int64_t get_rand_range( int min_val, int max_val ) {
    // 乱数生成器
    static mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    uniform_int_distribution<int> get_rand_uni_int( min_val, max_val );

    // 乱数を生成
    return get_rand_uni_int(mt64);
}

struct Items{
    vi a;
    Items(){
    }

    void add_item(int x){
        a.push_back(x);
    }

    bool send_random_item(Items &b){
        if(size()<=1)return false;
        int delete_num=get_rand_range(0,size()-1);
        int mitem=a[delete_num];
        a.erase(a.begin()+delete_num);
        b.add_item(mitem);
        return true;
    }

    bool send_back_item(Items &b){
        if(size()<=1)return false;
        int mitem=a[size()-1];
        a.pop_back();
        b.add_item(mitem);
        return true;
    }

    int size(){
        return (int)a.size();
    }

    void show_items(){
        cout<<"# : ";
        for(auto v : a){
            cout<<v<<" ";
        }
        cout<<endl;
        cout<<flush;
    }
};

int qcnt=0;
int N,D,Q;
vector<Items> ss;

char send_query(int l,int r){
    if(qcnt>=Q)return 'n';
    char res;
    cout<<ss[l].size()<<" "<<ss[r].size()<<" ";
    for(auto lv : ss[l].a){
        cout<<lv<<" ";
    }
    for(auto rv : ss[r].a){
        cout<<rv<<" ";
    }
    cout<<endl;
    cout<<flush;
    cin>>res;
    qcnt++;
    return res;
}

double eval(){

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(15);
    //値の入力
    cin>>N>>D>>Q;
    ss.resize(D);
    //ランダムにD個に分ける
    for(int i=0;i<N;i++){
        ss[i%D].add_item(i);
    }

    vi ans(N);  //答えの配列

    for(int k=0;k<Q;k++){
        int l=0;
        int r=0;
        while(l==r){
            l=get_rand_range(0,D-1);
            r=get_rand_range(0,D-1);
        //cout<<"# l : "<<l<<" r : "<<r<<endl;
        //cout<<"# "<<D<<endl;
        }
        //cout<<"# l : "<<l<<" r : "<<r<<endl;
        char res=send_query(l,r);
        //cout<<"# "<<res<<endl;
        if(res=='n')break;
        if(res=='<'){
            while(res=='<'){
                if(!ss[r].send_random_item(ss[l])){
                    break;
                }
                res=send_query(l,r);
                //cout<<"# "<<res<<endl;
            }
            //cout<<"# fjejffje"<<endl;
        }
        else if(res=='>'){
            while(res=='>'){
                if(!ss[l].send_random_item(ss[r])){
                    break;
                }
                res=send_query(l,r);
                //cout<<"# "<<res<<endl;
            }
        }
    }


    //答えの作成
    for(int i=0;i<D;i++){
        for(auto v : ss[i].a){
            ans[v]=i;
        }
    }
    printVector(ans);
    return 0;
}