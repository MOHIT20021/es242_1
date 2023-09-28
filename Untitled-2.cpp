
#include<iostream>
using namespace std;


int max_num(int* a,int n,int k=INT_MAX){
    int max=INT_MIN;
    int max_idx=-1;
    for (int i=0; i<n;i++){
        if (a[i]>max && a[i]<=k){
            max=a[i];
            max_idx=i;
        
    }   
    }return max_idx;
}
void order(int *a,int *t,int n ,int start){
    int m;
    for (int i=start;i<n;i++){
    m=max_num(t,6);
    a[i]=t[m];
    t[m]=-1;
    }
}
int smallest(int* a,int n,int idx,int* t,int t_idx){

    if (idx-1>=0){
        t[t_idx]=a[idx];
        t_idx++;

        if (a[idx]>=a[idx-1]){
   
            smallest(a,n,idx-1,t,t_idx);
            }
        
        // elif 
        else if ((n-idx)==t_idx){
            int temp=a[idx-1];
      
            int w=max_num(t,n,temp);

            a[idx-1]=t[w];
            t[w]=temp;
            order(a,t,n,idx);

        }


        }
        return *a;
    

    }



int main(){

    int a[4]={6,6,6,5};
    int t[6]={-1,-1,-1,-1,-1,-1};
    int size=0;
    int idx=3;
    smallest(a,4,idx,t,size);

 
}