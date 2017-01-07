//
//  main.cpp
//  NTPU_Algorithm_期末1-3
//
//  Created by Keng on 07/01/2017.
//  Copyright © 2017 Keng. All rights reserved.
//

#include <iostream>
using namespace std;

struct activity{
    int start;
    int end;
    int _id;
};
typedef struct activity Activity;
void act_select(int n,Activity act[],int table[]){
    //first activity must add in the schedule
    int count=1;
    table[act[0]._id]=1;
    //i used for search activity start time
    //j used for compare with i starttime
    for(int i=1,j=0;i<=n;i++){
        if(act[i].start>=act[j].end){
            table[act[i]._id]=1;
            j=i;//use j for next target 
            count++;
        }
    }
    cout<<count<<endl;
    
    for(int i=0;i<n;i++){
        if(table[i]){
            cout<<i+1<<" ";
        }
    }
}
int main(int argc, const char * argv[]) {
    Activity act[1000];
    Activity temp;
    int table[1000];
    int n;
    //input & initialize array
    cin>>n;
    for(int i=0;i<n;i++){
        
        cin>>act[i].start;
        table[i]=0;
        act[i]._id=i;
    }
    for(int i=0;i<n;i++){
        cin>>act[i].end;
    }
    //according to activity end time,we need to sort it
    //the eariler time the activity ends, we can add more activity in the schedule
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(act[j].end<act[i].end){
                temp=act[i];
                act[i]=act[j];
                act[j]=temp;
            }
        }
    }
    act_select(n, act, table);
    return 0;
}
