#include<iostream>
#include<algorithm> 
using namespace std;
int a[105][105];
int n,m;
int ans[105][105];
int maxPath (int i, int j){
    if(i<0||i>=n|| j<0 || j>=m) return 0;
    if(ans[i][j]!=-100005){
        return ans[i][j];
    }
    ans[i][j] = max(maxPath(i-1, j-1), max(maxPath(i,j-1), maxPath(i+1,j-1))) + a[i][j];
    return ans[i][j];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans[i][j] = -100005;
        }
    }
    int mp = -100005;
    for(int i=0;i<n;++i){
        if(maxPath(i, m-1) > mp) mp = maxPath(i, m-1);
    }
    cout<<mp;
    return 0;
}