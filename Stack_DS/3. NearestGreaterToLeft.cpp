#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NearestGreaterToLeft(vector<int> &v){
    vector<int> ans; stack<int> st;
    int n = v.size();
    
    for(int i = 0; i< 2 * n ; i++){
        while(!st.empty() && st.top() <= v[i%n]){
            st.pop();
        }
        
        if(i >= n){
           if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top()); 
        }
        
        st.push(v[i%n]);
    }
    
    return ans;
}

int main() {
    vector<int> v;
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    
    vector<int> ans = NearestGreaterToLeft(v);
    
    for(auto ele: ans){
        cout<<ele<<" ";
    }
}