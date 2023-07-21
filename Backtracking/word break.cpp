// word break
/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
    int f(int idx, string s, set<string> &st, vector<int> &dp){
        if(idx==s.size()){
            return 1;
        }
        string temp;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            temp.push_back(s[i]);
            if(st.find(temp)!=st.end()){
                if(f(i+1,s,st,dp)==1) return dp[idx]=1;
            }
        }
        return dp[idx]=0;

    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it: wordDict){
            st.insert(it);
        }
        int n=s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,st,dp);
    }
};