//
//  main.cpp
//  NTPU_Algorithm_期末2-2
//
//  Created by Keng on 07/01/2017.
//  Copyright © 2017 Keng. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;
//參數上限： n:vertex<=50 m:edge<=200
bool map[51][51];
double w[51][51];
bool check[51];
int d[51];
int parent[51];
void initialize(){

    for(int i=1;i<=50;i++){
        check[i]=false;
        d[i]=INT_MAX;
        parent[i]=0;
        for(int j=1;j<=50;j++){
            map[i][j]=false;
            w[i][j]=INT_MAX;
        }
    }
}
void input(int e){
    int start,end,weight;
    for(int i=0;i<e;i++){
        cin>>start;
        cin>>end;
        cin>>weight;
        map[start][end]=true;
        w[start][end]=weight;
    }
}
bool is_selectAll(int v){
    
    for(int i=1;i<=v;i++){
        if(check[i]==false){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    
    int vertex,edge;
    int initial_point;
    int select_point=0;
    int cmp_weight;
    //initial each data in algorithm
    initialize();
    //input
    cin>>vertex;
    cin>>edge;
    input(edge);
    cin>>initial_point;
    //set the shortest of initial point value to 0
    d[initial_point]=0;
    
    //each time it will check whether the check table all be checked
    while(!is_selectAll(vertex)){
       //choose the uncheck vertex the minimum distance to be target vertex using for comparison
        int temp_min=INT_MAX;
        for(int i=1;i<=vertex;i++){
            if(!check[i]){
                if(d[i]>=0&&d[i]<temp_min){
                    temp_min=d[i];
                    select_point=i;
                }
            }
        }
        check[select_point]=true;
        //compare the each vertex connected to select point with the shortest distance table , if it is we will update the table
        for(int i=1;i<=vertex;i++){
            if(map[select_point][i]){
                cmp_weight=d[select_point]+w[select_point][i];
                if(cmp_weight<d[i]){
                    d[i]=cmp_weight;
                    parent[i]=select_point;
                }
            }
        }
    }
    //print output
    for(int i=1;i<=vertex;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=vertex;i++){
        cout<<parent[i]<<" ";
    }

    return 0;
}
