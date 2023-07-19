#include<bits/stdc++.h>
#include <string>
#include <math.h>
#define ll long long
using namespace std;

// search in a rotated sorted array
int search(int A[], int l, int h, int key){
        while(l<=h){
            int mid=l+(h-l)/2;
            if(A[mid]==key){
                return mid;
            }
            else if(A[l]<=A[mid]){
                if(key<=A[mid] && key>=A[l]){
                    h=mid-1;
                }
                else l=mid+1;
            }
            else if(A[mid]<=A[h]){
                if(key>=A[mid] && key<=A[h]){
                    l=mid+1;
                }
                else h=mid-1;
            }
        }
        return -1;
}



int main(){
    
}