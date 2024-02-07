class Solution {
public:
    int firstUniqChar(string s) {
        map<char,pair<int, int>> uniq;
        for(char a = 'a';a<='z';a++){
            uniq[a] = {0,0};
        }
        int index=0;
        for(char a: s){
            uniq[a].first++;
            uniq[a].second = index++;
        }
        for(char a:s){
            if(uniq[a].first == 1){
                return uniq[a].second;
            }
        }
        return -1;
    }
};