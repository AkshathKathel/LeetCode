class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr = i;
            while(st.top()!=-1 &&(heights[curr]<=heights[st.top()])){
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& heights, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<=n-1;i++){
            int curr = i;
            while(st.top()!=-1 &&(heights[curr]<=heights[st.top()])){
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> next;
        vector<int> prev;
        int n = heights.size();

        next = nextSmallerElement(heights,n);
        prev = prevSmallerElement(heights,n);
        int area = INT_MIN;
        for(int i = 0;i<n;i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
};