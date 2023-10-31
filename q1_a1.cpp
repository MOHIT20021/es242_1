#include<iostream>
using namespace std;

void print_a(int a[],int n){
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void generate_1(int a[],int n , int k , int b[],int idx,int g){
if (k==0){
    return;
}

for (int i=g;i<n-k+1;i++){
    b[idx]=a[i];
    generate_1(a,n,k-1,b,idx+1,i+1);
    if (k==1){
    print_a(b,idx+1);
    cout<<" "<<endl;
    }
}
}
void pint(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n";
    }
}
// void pint(int ,int );
void change(int a[],int n){
    if (a[0]>4){
        return ;
    }
    for(int i=0;i<n;i++){
        a[i]=a[i]+1;
    }
    pint(a,n);
    cout<<endl;
    change(a,n);

}



int main(){
const int n=4;
int a[n]={2,1,6,5};
// int i=0;
// const int k = 1;
// int buf[k];
// generate_1(a,n,k,buf,i,i);
// pint(a,n);
change(a,n);
// pint(a,n);

}
