class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            else{
                
                if(!st.empty()){
                    char check = st.top();
                    if(ch == ')' && check == '('
                    || ch == '}' && check == '{'
                    || ch == ']' && check == '[')
                    {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                 }
                 else{
                     return false;
                 }
            }
        }  
        if(st.empty()){
            return true;
        } 
        else{
            return false;
        }
    }
};