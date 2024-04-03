#include <iostream>
using namespace std;

int ***matrizM(int N, int K0, int K1, int*& Di, int*& G){
    int*** M= new int**[N];
    Di= new int[N];
    G= new int[N];
    int a,b;
    if (K0>=K1){
        a=K0;}
    else {a=K1;}
    for (int i=0;i<N;i++){
        if ((i==0 && a%2==0)||(i>0 && K0==K1 && a%2==0)){
            b=a+1;}
        else if (i>0 && a%2==0){
            b=a-1;}
        else{b=a;}
        M[i]=new int*[b];
        Di[i]=b;
        G[i]=0;
        for (int Fil=0;Fil<b;Fil++){
            M[i][Fil]=new int[b];}}
    return M;}
  
  
  
void llenar(int***& M,int*& Di, int N){
    for (int i=0;i<N;i++){
        int cont=0;
        for (int fil=0;fil<Di[i];fil++){
            for (int col=0;col<Di[i];col++){
                if (col==fil && col==(Di[i]/2)){}
                else{cont++;
                    M[i][fil][col]=cont;
                    cout <<M[i][fil][col]<< endl;}}}}}

int main(){
    int K[]={4,3,1,-1,1};
    int* Di;
    int* G;
    int N=(sizeof(K)/sizeof(K[0]))-1;
    int*** M=matrizM(N,K[0],K[1],Di,G);
    llenar(M,Di,N);
    for (int i = 0; i < N; ++i) {
        cout << Di[i] <<G[i]<< " ";}}
