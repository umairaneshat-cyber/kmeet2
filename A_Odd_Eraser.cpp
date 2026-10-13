#include <iostream>
#include <vector>
using namespace std;
int maxgcd(vector<int> arr,int n){
    
}
void solve() {
    // 1. Read input for a single test case
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return maxgcd(arr,n);
}
int main() {
    solve();
    return 0;
}
