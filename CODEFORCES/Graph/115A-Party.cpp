#include<bits/stdc++.h>
using namespace std;

struct node{
    int n;
    vector<node*> childrens;
    node(int n):n(n){}
};

int findDepth(node* n , vector<bool>&visited){
    visited[n->n-1] = 1;
    
    if(n->childrens.empty()){
        return 0;
    }

    int height = INT_MIN;
    for(int i = 0 ; i<n->childrens.size() ; i++){
        if(!visited[n->childrens[i]->n-1]){
            int h = 1 + findDepth(n->childrens[i],visited);
            height = max(height , h);}
    }
    return height == INT_MIN ? 0 : height;
}

int main(){
    int n;
    cin>>n;
    vector<bool>visited(n , 0);
    vector<bool> isRoot(n, true);
    vector<node*>v;
    for(int i = 1 ; i<=n ; i++){
        node* nod = new node(i);
        v.push_back(nod);
    }
    for(int i = 0 ; i<n ; i++){
        int j;
        cin>>j;
        if(j==-1)continue;
        v[j-1]->childrens.push_back(v[i]);
        isRoot[i] = false;
    }
    int maxH = 0;
    for(int i =0 ; i<n ; i++){
        if(!visited[i] && isRoot[i]){
            maxH = max(maxH , findDepth(v[i] , visited));
        }
    }
    
    cout<<maxH+1<<endl;

}