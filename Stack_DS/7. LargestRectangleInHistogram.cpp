#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// for interview first discuss double pass
int largestRectangleAreaDoublePass(vector<int>& heights) {
        int ans = INT_MIN;
        stack<pair<int,int>> st; // {number,index}
        int n = heights.size();
        
        // NearestSmallerToLeft -> linearly increasing stack
        vector<int> left;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                left.push_back(i - (-1));
            } else {
                left.push_back(i - st.top().second);
            }
            
            st.push({heights[i], i});
        }
        
        st = {};
        
        cout<<"left: ";
        for(auto ele: left){
            cout<<ele<<" ";
        }
        cout<<'\n';
        
        //NearestSmallerToRight
        vector<int> right;
        for(int i =n-1; i>=0; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                right.push_back(n - i);
            } else {
                right.push_back(st.top().second - i);
            }
            
            st.push({heights[i], i});
        }
        
        reverse(right.begin(), right.end());
        
        cout<<"right: ";
        for(auto ele: right){
            cout<<ele<<" ";
        }
        cout<<'\n';
        
        for(int i=0; i<n; i++){
            int width = left[i] + right[i] - 1;
            int height = heights[i];
            ans = max(ans, width * height);
        }
        
        return ans;
    }

int largestRectangleAreaSinglePass(vector<int> & heights){
        stack<int> st; // linearly increasing stack
        int maxA = 0;
        int n = heights.size();

        for(int i=0; i<= n; i++){
            int currHeight = i == n ? 0 : heights[i];
            
            // check if currHeight becomes greater then heights[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while(!st.empty() && currHeight < heights[st.top()] ){
                int top = st.top();  st.pop();  // current element on which we are working
                
                int width = st.empty() ? i : i - st.top() - 1;
                int Area = heights[top] * width;
                maxA = max(maxA, Area);
            }
            // if it doesn't enter in while loop, it means it's an increasing sequence & we need to push index
            st.push(i);
        }

        return maxA;
}

int main() {
    int x;
    vector<int> v;
    while(cin>>x){
        v.push_back(x);
    }
    cout<<largestRectangleAreaDoublePass(v);
}