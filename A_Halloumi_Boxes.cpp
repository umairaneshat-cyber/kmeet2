#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k,t;
    cin>>t;
    while(t!=0){
    cin>>n;
    cin>>k;
    int x;
    vector<int> arr;
    for(int i=0;i<n;i++){
    cin>>x;
    arr.push_back(x);
    }
    int res=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
        res=0;
        break;
        }
    } 
   if(k>1)
   res=1;
    if(res==0)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
   t--; 
}
return 0;
}
