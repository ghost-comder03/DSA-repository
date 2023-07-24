#include<bits/stdc++.h>
#include <string>
#include <math.h>
#define ll long long
using namespace std;

//tree node definitions
struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}


//linkedList definitions

struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};


// Checking number prime or not

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

//gcd of numbers

int gcd(int a, int b)
{
    int result = min(a, b); // Find Minimum of a nd b
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result; // return gcd of a nd b
}

// lcm of numbers

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


//checking if string is palindrome or not
bool isPalindrome(string s){
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}


void solv(){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a,a+3);
    if(a[2]+a[1]>=10){
        cout<<"YES"<<endl;

    }
    else cout<<"NO"<<endl;


    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solv();
    }

    return 0;
}


 


	

	

	

	
	
	
 
	            

   
