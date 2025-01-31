#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

BinaryTree* Tree(BinaryTree* root){
    int data;
    
    cout<<"enter data: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new BinaryTree(data);

    cout<<"enter data for inserting in left of: "<<data<<endl;
    root->left=Tree(root->left);
    cout<<"enter data for inserting in right of: "<<data<<endl;
    root->right=Tree(root->right);
    return root;
}

void level_order_traversal(BinaryTree* root){
    queue<BinaryTree*> q;
    q.push(root);
    q.push(NULL);//separator

    while(!q.empty()){
        BinaryTree* temp=q.front();
        
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }  
    }
}

//left root right
void inorder_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    inorder_traversal(temp->left);
    cout<<temp->data<<" ";
    inorder_traversal(temp->right);
}

//left right root
void post_order_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    post_order_traversal(temp->left);
    
    post_order_traversal(temp->right);
    cout<<temp->data<<" ";
}

//root left right 
void pre_order_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    cout<<temp->data<<" ";
    pre_order_traversal(temp->left);
    
    pre_order_traversal(temp->right);
}

int height(BinaryTree* root){
    if(root==NULL){
        return 0;
    }

    int l=height(root->left);
    int r=height(root->right);
    int ans =max(l,r)+1;
    return ans;
}

vector<int> spiral_traversal(BinaryTree* root){
    bool ori=true;//left to right
    vector<int> ans;
    if (root==NULL){
        return ans;      
    }
    queue<BinaryTree*> q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            BinaryTree* Front=q.front();
            q.pop();

            int index=ori?i:size-i-1;
            temp[index]=Front->data;

            if(Front->left){
                q.push(Front->left);
            }
            if(Front->right){
                q.push(Front->right);
            }
        }
        ori=!ori;
        for(auto i:temp){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> verticalTraversal(BinaryTree* node){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<BinaryTree*,pair<int,int>>> q;
    vector<int> ans;
    if(node==NULL){
        return ans;
    }

    q.push(make_pair(node,make_pair(0,0)));
    while(!q.empty()){
        pair<BinaryTree*,pair<int,int>> temp=q.front();
        q.pop();
        BinaryTree* front_node=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(front_node->data);
        if(front_node->left){
            q.push(make_pair(front_node->left,make_pair(hd-1,lvl+1)));
        }
        if(front_node->right){
            q.push(make_pair(front_node->right,make_pair(hd+1,lvl+1)));
        }
    }
    cout<<"map";
    for(auto i:nodes){
        cout<<i.first<<" ";
        for(auto j:i.second){
            cout<<j.first<<" ";
            for(auto z:j.second){
                cout<<z<<" ";
            }
            // for(auto k:j.second){
                
            //     ans.push_back(k);
            // }
        }
        cout<<endl;
    }
    
    
    return ans;
    

}
int main(){

    BinaryTree* root=NULL;
    root=Tree(root);//binary tree created
    // level_order_traversal(root);
    // inorder_traversal(root);
    // post_order_traversal(root);
    // pre_order_traversal(root);

    // cout<<"height of the given binary tree is: "<<height(root)-1;

    // vector<int> res=spiral_traversal(root);
    // for(auto i:res){
    //     cout<<i<<" ";
    // }

    vector<int> ans=verticalTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
   return 0; 
}
