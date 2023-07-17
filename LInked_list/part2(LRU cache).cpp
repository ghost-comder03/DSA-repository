#include <bits/stdc++.h>
using namespace std;

//design and implement a LRU  cache

class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };

    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node *> m;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }

    void addnode(node *newnode){
        node *temp=head->next;
        newnode->prev=head;
        newnode->next=temp;
        head->next=newnode;
        temp->prev=newnode;

    }

    void deletenode(node *delnode){
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int GET(int key_) {
        if(m.find(key_)!=m.end()){
            node *resnode=m[key_];
            int res=resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_]=head->next;
            return res;
        }
        return -1;
    }
    
    void SET(int key_, int value_) {
        if(m.find(key_)!=m.end()){
            node *found=m[key_];
            m.erase(key_);
            deletenode(found);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value_));
        m[key_]=head->next;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

