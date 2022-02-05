#include <iostream>
#include <vector>
using namespace std;

vector<int>x;
vector<int>y;

void fnumber(int num){
  if(num==1){
    return;
  }
  int i=2;
  start:
  if(num%i==0){
    x.push_back(i);
  }
  else{
    i++;
    goto start;
  }
  fnumber(num/i);
}
void snumber(int num){
  if(num==1){
    return;
  }
  int i=2;
  start:
  if(num%i==0){
    y.push_back(i);
  }
  else{
    i++;
    goto start;
  }
  snumber(num/i);
}

int main() {
  int fnum,snum;
  cout<<"Enter the first number: ";
  cin>>fnum;
  cout<<"Enter the second number: ";
  cin>>snum;
  fnumber(fnum);
  snumber(snum);
  int count=1;
  if(x.size() == y.size()){
   for(int i=0 ; i<x.size() ; i++){
     count*= (x[i] == y[i])? x[i] : x[i]*y[i]; 
   }
  }
  else if(x.size() > y.size()){
    int i;
    for(i=0 ; i<y.size() ; i++){
      count*= (x[i] == y[i])? x[i] : x[i]*y[i];
    }
    for(int j=i ; j<x.size() ; j++){
      count*x[j];
    }
  }
  else if(y.size() > x.size()){
    int i;
    for(i=0 ; i<x.size() ; i++){
      count*= (x[i] == y[i])? x[i] : x[i]*y[i];
    }
    for(int j=i ; j<y.size() ; j++){
      count*=y[j];
    }
  }
  cout<<"\nLeast Common Multiple: "<<count<<endl;
}
