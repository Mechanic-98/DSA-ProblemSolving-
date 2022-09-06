#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NearestGreaterToRight(vector<int> &v){
    vector<int> ans; 
    stack<int> st;  // linearly increasing stack
    int n = v.size();
    
    for(int i = 2*n -1; i>= 0; i--){
        while(!st.empty() && st.top() >= v[i%n]){
            st.pop();
        }
        
        if(i < n){
           if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top()); 
        }
        
        st.push(v[i%n]);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    vector<int> v;
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    
    vector<int> ans = NearestGreaterToRight(v);
    
    for(auto ele: ans){
        cout<<ele<<" ";
    }
}