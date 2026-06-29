class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;    
        for(auto i:patterns) {
            if(i.size() > word.size()) continue;
            else if(word.contains(i)){
                res++;               
            }
        }
        return res;
    }
};