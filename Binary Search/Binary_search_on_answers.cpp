// Agressive Cows problem
/*You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool possible(int mid, vector<int>&stalls,int k)
    {
        int i,j,temp=stalls[0],count=1;
        for(i=1;i<stalls.size();i++)
        {
            if(stalls[i]-temp>=mid)
            {
                  temp=stalls[i];
                  count++;
            }
            if(count==k)
            return true;
        }
        return false;
          
          
          
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int start=1,end=stalls[n-1]-stalls[0];
        int res=-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(possible(mid,stalls,k)){
                res=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return res;
    
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}