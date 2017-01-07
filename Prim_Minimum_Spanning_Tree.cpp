//
//  main.cpp
//  NTPU_Algorithm_期末2-1
//
//  Created by Keng on 07/01/2017.
//  Copyright © 2017 Keng. All rights reserved.
//

#include <iostream>
#include <limits.h>

using namespace std;

bool map[51][51];
bool check[51];
double w[51][51];
double output[51];
void initialize(){
    for(int i=1;i<=50;i++){
        check[i]=false;
        output[i]=INT_MAX;
        for(int j=1;j<=50;j++){
            map[i][j]=false;
            w[i][j]=INT_MAX;
        }
    }
}
void input(int e){
    int start,end,weight;
    for(int i=1;i<=e;i++){
        cin>>start;
        cin>>end;
        cin>>weight;
        map[start][end]=true;
        map[end][start]=true;
        w[start][end]=weight;
        w[end][start]=weight;
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
    int temp_point,parent=0,select_point=0;
    int sum=0;
    
    //initialize
    initialize();
    //input
    cin>>vertex;
    cin>>edge;
    input(edge);
    cin>>initial_point;
    
    check[initial_point]=true;
    output[initial_point]=0;
    
    //whether all vertex has been choose
    while (!is_selectAll(vertex)) {
        double temp_min=INT_MAX;
        for(int i=1;i<=vertex;i++){
            //find if it has been connect
            if(check[i]){
                temp_point=i;
                //find minimum_point
                for(int j=1;j<=vertex;j++){
                    if((!check[j])&&temp_min>w[temp_point][j]){
                        temp_min=w[temp_point][j];
                        select_point=j;
                        parent=temp_point;
                        
                    }
                }
            }
        }
        check[select_point]=true;
        output[select_point]=parent;
        sum+=temp_min;
        cout<<"value: "<<temp_min<<" "<<"point: "<<output[select_point]<<endl;
    }
    //print
    for(int i=1;i<=vertex;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl<<sum<<endl;

    return 0;
}
