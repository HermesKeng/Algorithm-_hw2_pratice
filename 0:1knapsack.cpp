//
//  main.cpp
//  Ntpu_Algorithm_期末2-4
//
//  Created by Keng on 07/01/2017.
//  Copyright © 2017 Keng. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <iomanip>
using namespace std;
//參數範圍 n:vertex<=50 m:edge<=200
double map[51][51];

void initial(){
    for(int i=1;i<=50;i++){
        for(int j=1;j<=50;j++){
            map[i][j]=INT_MAX;
        }
    }
}
void input(int v,int e){
    int start,end,weight;
    
    for(int i=1;i<=e;i++){
        cin>>start;
        cin>>end;
        cin>>weight;
        map[start][end]=weight;
    }
}
void print(int v){
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<setw(5)<<map[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(int argc, const char * argv[]) {
    
    int vertex,edge;
    //initialize table
    initial();
    //input data
    cin>>vertex;
    cin>>edge;
    input(vertex,edge);
    //run loop for each vertex to be midpoint
    //if "d[i][midpoint]+d[midpoint][j]<d[i][j]" means the shortest distance 'i' to 'j' have the new shortest path through midpoint
    for(int midpoint=1;midpoint<=vertex;midpoint++){
        for(int i=1;i<=vertex;i++){
            for(int j=1;j<=vertex;j++){
                if(i==j){
                    map[i][j]=0;
                }else{
                    if(map[i][midpoint]+map[midpoint][j]<map[i][j]){
                        map[i][j]=map[i][midpoint]+map[midpoint][j];
                    }
                }
            }
        }
    }
    //output
    print(vertex);
    return 0;
}
