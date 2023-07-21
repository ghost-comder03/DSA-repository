//m coloring problem
/*Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.*/


#include <bits/stdc++.h>
using namespace std;



class Solution{
    bool safe(int node, bool graph[101][101], int color[], int col, int n){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, bool graph[101][101], int color[], int m, int n){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(safe(node,graph,color,i,n)){
                color[node]=i;
                if(solve(node+1,graph,color,m,n)) return true;
                color[node]=0;
            }
        }
        return false;
    }
public:
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n]={0};
        return solve(0,graph,color,m,n);
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}