// Naive Solution => MLE
// O(N^2)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        for(int i=3;i<=s.size();i++) {
            for(int j=0;j<=s.size()-i;j++) {
                string sub = s.substr(j,i);
                if(sub.find("a") != string::npos && sub.find("b") != string::npos && sub.find("c") != string::npos) {
                    res++;
                }
            }            
        }
        return res;        
    }
};

// Naive Solution => TLE
// O(N^2)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int n=s.size();

        for(int i=3;i<=s.size();i++) {
            for(int j=0;j<=s.size()-i;j++) {
                int act=0,bct=0,cct=0;
                for(int k=j;k<j+i;k++) {
                    if(s[k]=='a') act++;
                    if(s[k]=='b') bct++;
                    if(s[k]=='c') cct++;
                }
                if(act>0 && bct>0 && cct>0) {
                    res++;
                }
            }
        }        
        return res;
    }
};

// Optimized Solution TC O(N) SC O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> ct(3,0);
        int left=0,res=0;
        for(int right = 0;right<s.size();right++) {
            ct[s[right] - 'a']++;
            while(ct[0]>0 && ct[1]>0 && ct[2]>0) {
                res+=s.size()-right;
                ct[s[left]-'a']--;
                left++;
            }
        }
        return res;                
    }
};

// Optimized Solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res=0;
        int la=-1,lb=-1,lc=-1;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='a') la=i;
            if(s[i]=='b') lb=i;
            if(s[i]=='c') lc=i;
            if(la!=-1 && lb!=-1 && lc!=-1) {
                int midx = min({la,lb,lc});
                res+=midx+1;
            }
        }
        return res;
    }
};