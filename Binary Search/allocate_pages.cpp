/*You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.*/



#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    bool possible(int A[], int N, int M, int mid){
        int countSt=1;
        int pages=0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            if(A[i]+pages>mid){
                countSt++;
                pages=0;
            }
            pages+=A[i];
        }
        if(countSt<=M) return true;
        return false;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int sum=0;
        if(M>N) return -1;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int start=A[0],end=sum;
        int res=-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(possible(A,N,M,mid)){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
};



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}