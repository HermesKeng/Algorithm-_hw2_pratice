//
//  main.cpp
//  NTPU_Algorithm_期末2-3
//
//  Created by Keng on 07/01/2017.
//  Copyright © 2017 Keng. All rights reserved.
//

#include <iostream>
#include <limits.h>
//參數上限： n:vertex<=50 m:edge<=200
using namespace std;

double d[51];
int  parent[51];
int  start[201];
int  destination[201];
int  weight[201];
void initialize(){
    
    for(int i=1;i<=50;i++){
        d[i]=INT_MAX;
        parent[i]=0;
    }
    for(int i=1;i<=200;i++){
        start[i]=0;
        destination[i]=0;
        weight[i]=0;
    }
}
void input(int e){
    for(int i=1;i<=e;i++){
        cin>>start[i];
        cin>>destination[i];
        cin>>weight[i];
    }
}

int main(int argc, const char * argv[]) {
    int vertex,edge;
    int initial_point;
    //initialize data
    initialize();
    cin>>vertex;
    cin>>edge;
    //input data
    input(edge);
    cin>>initial_point;
    d[initial_point]=0;
    parent[initial_point]=0;
    //vertex-1 times must be able to find a minimum path
    for(int i=1;i<=vertex-1;i++){
        //we will run each edge to compare d[destination] wherther less than d[start] + w[start][end]
        //if it is, we will update distance table and store parent
        for(int j=1;j<=edge;j++){
            if(d[destination[j]]>d[start[j]]+weight[j]){
                d[destination[j]]=d[start[j]]+weight[j];
                parent[destination[j]]=start[j];
            }
        }
    }
    //do again to check if it is negative weight cycle
    for(int j=1;j<=edge;j++){
        if(d[destination[j]]>d[start[j]]+weight[j]){
            cout<<"There is a negative weight cycle in the graph"<<endl;
            return 0;
        }
    }
    //print answer
    for(int i=1;i<=vertex;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<=vertex;i++){
        cout<<parent[i]<<" ";
    }
    
    return 0;
}
