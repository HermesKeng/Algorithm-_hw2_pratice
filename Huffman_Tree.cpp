//
//  main.cpp
//  Ntpu_Algorithm_期末1-4
//
//  Created by Keng on 09/01/2017.
//  Copyright © 2017 Keng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct node{
    node* left_ptr;
    node* right_ptr;
    int frequency;
    int no;
    string code;
};
typedef struct node Node;
vector<Node*>output;
bool compare(Node *a,Node *b){
    if(a->frequency>b->frequency){
        return false;
    }
    return true;
}
bool compare_id(Node *a,Node *b){
    if(a->no>b->no){
        return false;
    }
    return true;
}
Node *print(Node *tree,string s){
    tree->code=s;
    if(tree->left_ptr==NULL&&tree->right_ptr==NULL){
        cout<<tree->frequency<<" "<<tree->code<<endl;
        output.push_back(tree);
        return tree;
    }else{
        print(tree->left_ptr,s.append("1"));
        s.erase(s.end()-1);
        tree=print(tree->right_ptr,s.append("0"));
    }
}
void Huffman(vector<Node*>node){
    Node *mid=NULL;
    Node *ans=NULL;
    int i;
    while(node.size()!=1){
        sort(node.begin(),node.end(),compare);
        mid=new Node;
        mid->left_ptr=node[0];
        mid->right_ptr=node[1];
        mid->frequency=node[0]->frequency+node[1]->frequency;
        node.erase(node.begin());
        node.erase(node.begin());
        node.push_back(mid);
        /*
         for(i=0;i<node.size();i++){
         cout<<node[i]->frequency<<" ";
         }
         cout<<endl;
         */
    }
    ans=new Node;
    ans=node[0];
    node.erase(node.begin());
    print(ans,"");
    
    sort(output.begin(),output.end(),compare_id);
    for(i=0;i<output.size();i++){
        cout<<output[i]->code<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<Node*> node;
    Node *key;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        key=new Node;
        cin>>key->frequency;
        key->left_ptr=NULL;
        key->right_ptr=NULL;
        key->no=i;
        node.push_back(key);
    }
    Huffman(node);
    return 0;
}
