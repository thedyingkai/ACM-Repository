#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Course {
    double gain;
    int cred;
    int dif;
};
double m(int n,int M,vector<int>&cre,vector<int>&dif){
    vector<Course> courses(n);
    for(int i=0;i<n;++i) courses[i]={100.0*cre[i]/dif[i],cre[i],dif[i]};
    sort(courses.begin(),courses.end(),[](const Course&a,const Course&b){return a.gain>b.gain;});
    double totalScore=0.0;
    for (const auto&course:courses) {
        int days=min(M,course.dif);
        double score=min(1.0,(double)days/course.dif)*100*course.cred;
        totalScore += score;
        M-=days;
        if(M==0) break;
    }
    return totalScore;
}
int main(){
    int n,M;
    cin>>n>>M;
    vector<int> cre(n), dif(n);
    for(int i=0;i<n;++i) cin>>cre[i];
    for(int i=0;i<n;++i) cin>>dif[i];
    double res=m(n,M,cre,dif);
    cout<<fixed<<setprecision(4)<<res<<endl;
    return 0;
}