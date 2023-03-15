#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int  main(){
    int n; cin>>n;
    int m; cin>>m;
    vector<int>vt;
    for(int i=0;i<n;++i){
        int x;   cin>>x;
        vt.push_back(x);
    }
    sort(vt.begin(), vt.end());
    long long sum=0;
    int i = n-1;
    while(i>=0 && sum<m){
        if(sum+vt[i]<=m){
            sum+=vt[i];
            --i;
        }
        else break;
    }
    cout<<sum;
    return 0;
}