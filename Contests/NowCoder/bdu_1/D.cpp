#include<string>
#include<unordered_map>
#include<climits>
#include<iostream>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    unordered_map<char,int> w,tg;
    for(char c:t) tg[c]++;
    int l=0,r=0,m=0,mn=INT_MAX,st=0;
    while(r<s.size()){
        char R=s[r];
        if(tg.count(R)){
            w[R]++;
            if(w[R]==tg[R]) m++;
        }
        while(m==tg.size()){
            if(r-l+1<mn){
                mn=r-l+1;
                st=l;
            }
            char L=s[l];
            if(tg.count(L)){
                w[L]--;
                if(w[L]<tg[L]) m--;
            }
            l++;
        }
        r++;
    }
    cout<<(mn==INT_MAX?"":s.substr(st,mn));
}