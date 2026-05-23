#include<bits/stdc++.h>
using namespace std;

struct Activity{
   char name[10];
   int st;
   int ft;
};

int main(){
 int n;
 cout<<"Enter the number of activities: ";
 cin>>n;

 struct Activity act[n];

 for(int i=0;i<n;i++){
    cout<<"Enter the name of activity "<<i+1<< ": ";
    cin>> act[i].name;
     cout<<"Enter the start time of activity "<<i+1<< ": ";
    cin>> act[i].st;
     cout<<"Enter the finish of activity "<<i+1<< ": ";
    cin>> act[i].ft;
 }

 for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(act[i].ft > act[j].ft){
            Activity temp = act[i];
            act[i] = act[j];
            act[j] = temp;
        }
    }
 }
  vector<string> selected_activity;
  selected_activity.push_back(act[0].name);
  int count = 1;
  int last_ft = act[0].ft;

  for(int i=1;i<n;i++){
    if(act[i].st>=last_ft){
        selected_activity.push_back(act[i].name);
        count++;
        last_ft = act[i].ft;
    }
  }
  cout<<"Total no. of selected activities: "<< count << endl;
  cout<<"Selected activities: ";
  for(int i=0;i<selected_activity.size();i++){
    cout<<selected_activity[i];
  }
 }
