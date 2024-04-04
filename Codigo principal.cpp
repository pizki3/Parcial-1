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
                    M[i][fil][col]=cont;}}}}}
                    
int *puntero(int N,int K0,int K1, int***& M,int Di0,int Di1){
    int* pun=new int[N];
    for (int i=0; i<N;i++){
        if (i>0 && Di1<Di0){
            pun[i]=M[i][K0-2][K1-2];}
        else{pun[i]=M[i][K0-1][K1-1];}}
    return pun;}
    
bool cumplimiento(int K[],int N,int pu[],int& Mala1,int& Mala2,int& malK){
    int j=0;
    for (int i=2;i<=N;i++){
        if (K[i]==1){
            if (pu[j]>pu[j+1]){
                j++;}
            else{Mala1=j;
                 Mala2=j+1;
                 malK=K[i];
                 return false;}}
        else if(K[i]==-1){
            if (pu[j]<pu[j+1]){
                j++;}
            else{Mala1=j;
                 Mala2=j+1;
                 malK=K[i];
                 return false;}}
        else {
            if (pu[j]==pu[j+1]){
                j++;}
            else{Mala1=j;
                 Mala2=j+1;
                 malK=K[i];
                 return false;}}}
    return true;}
    
            
int main(){
    int K[]={4,3,1,-1,1};
    int* Di;
    int* G;
    int Mala1,Mala2,malK;
    int N=(sizeof(K)/sizeof(K[0]))-1;
    int*** M=matrizM(N,K[0],K[1],Di,G);
    llenar(M,Di,N);
    int* pun=puntero(N,K[0],K[1],M,Di[0],Di[1]);
    bool cumple=cumplimiento(K,N,pun,Mala1,Mala2,malK);
    cout <<cumple<<Mala1<<Mala2<<malK<< endl;
    for (int i = 0; i < N; ++i) {
        cout << Di[i] <<G[i]<<pun[i]<< " ";}}
