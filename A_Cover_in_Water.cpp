#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans;
    vector<char> cells;
    int t,n,action1;
    cin>>t;
    char x;
    while(t>0){
        cin>>n;
        for(int i=0;i<n;i++){
        cin>>x;
        cells.push_back(x);   
        }
        char c;
        action1=0;
        if(n==1){
            if(cells[0]=='.')
            action1++;
        }
        else if (n==2){
        if(cells[0]=='.'&&cells[1]=='.')
        action1+=2;
        else if(cells[0]=='#'&&cells[1]=='.')
        action1++;
        else if(cells[0]=='.'&&cells[1]=='#')
        action1++;
        } 
        else{
    for(int i=0;i<n;i++){
        c=cells[i];
        if(c=='#')
        continue;
        if(i<(n-2)){
            if(cells[i]==cells[i+1]&&cells[i]==cells[i+2]){
                action1=2;
                break;
            }
            else{
            action1++;
            continue;
            }
        }
        action1++;
    } 
}
    ans.push_back(action1); 
    t--; 
    cells.clear();
    }
    for(int x:ans){
        cout<<x<<endl;
    }
    return 0;
}