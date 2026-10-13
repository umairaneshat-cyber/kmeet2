#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans;
    vector<int> nums;
    int t,n,x;
    cin>>t;
    while(t>0){
    cin>>n;
    cin>>x;
    int max=0;
    int k=0;
    nums.push_back(0);
    for(int i=1;i<=n;i++){
    cin>>k;
    nums.push_back(k);
    }
    max=2*(x-nums[n]);
    nums.push_back(x);
    for(int i=0;i<=n;i++){
    max=max>nums[i+1]-nums[i]?max:nums[i+1]-nums[i];
    }
    ans.push_back(max);
    nums.clear();
    t--;
}
for(int x:ans){
    cout<<x<<endl;
}
return 0;
}