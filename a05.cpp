
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int celebrity(vector<vector<int>> &M){
        vector<pair<int,int>> ans(M.size());

    for(int i=0;i<M.size();i++){
        int flag=1;
        for(int j=0;j<M[0].size();j++){
        if(M[i][j]!=0){
        ans[j].second++;
        flag=0;
        }
        }
                ans[i].first=flag;
    }
    for(int i=0;i<M.size();i++){
        if(ans[i].first==1&&ans[i].second==M.size()-1)
        return i;
    }
    return -1; 
    }
int main(){
    vector<vector<int>> M={{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 1, 0}};
    cout<<celebrity(M);
    return 0;
}