#include <iostream>
#include <stack>
using namespace std;

int* stockSpan(int *price, int size)  {
	// Write your code here
    int *ans = new int[size];
    stack<pair<int,int>> st;

    // NearestGreaterToLeft
    for(int i=0; i<size; i++){
        while(!st.empty() && st.top().first < price[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans[i] = i - (-1);
        } else {
            ans[i] = i - st.top().second;
        }
        
        st.push({price[i],i});
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}