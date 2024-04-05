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
                    
int** puntero(int N,int K0,int K1, int***& M,int Di0,int Di1,int*& pos){
    pos=new int[N];
    int** pun=new int*[N];
    for (int i=0; i<N;i++){
        if (i>0 && Di1<Di0){
            pun[i]=&M[i][K0-2][K1-2];
            pos[i]=2;}
        else{pun[i]=&M[i][K0-1][K1-1];
             pos[i]=1;}}
    return pun;}
    
bool cumplimiento(int K[],int N,int**& pu,int& Mala1,int& Mala2,int& malK){
    int j=0;
    for (int i=2;i<=N;i++){
        if (K[i]==1){
            if (*pu[j]>*pu[j+1]){
                j++;}
            else{Mala1=j;
                 Mala2=j+1;
                 malK=K[i];
                 return false;}}
        else if(K[i]==-1){
            if (*pu[j]<*pu[j+1]){
                j++;}
            else{Mala1=j;
                 Mala2=j+1;
                 malK=K[i];
                 return false;}}
        else {
            if (*pu[j]==*pu[j+1]){
                j++;}
            else{Mala1=j;
                 Mala2=j+1;
                 malK=K[i];
                 return false;}}}
    return true;}

int girar(int***& M, int Mala,int Di[], int*& G){
    int Trans[Di[Mala]][Di[Mala]];
    for (int i=0;i<Di[Mala];i++){
        for(int j=0;j<Di[Mala];j++){
            Trans[i][j]=M[Mala][j][i];}}
    for (int i=Di[Mala]-1,u=0; i>=0;i--,u++){
        for (int j=0;j<Di[Mala];j++){
            M[Mala][u][j]=Trans[i][j];}}
    if (G[Mala]==3){
        G[Mala]=0;}
    else{G[Mala]++;}
    return 0;}

void Aumentar(int***&M,int Mala,int*& Di,int K0,int K1,int*& pos,int**& pun){
    int cont=0;
    for (int i=0;i<Di[Mala];i++){
        delete [] M[Mala][i];}
    delete [] M[Mala];
    Di[Mala]=Di[Mala]+2;
    pos[Mala]--;
    cout <<pos[Mala] << endl;
    M[Mala]=new int*[Di[Mala]];
    for (int Fil=0;Fil<Di[Mala];Fil++){
       M[Mala][Fil]=new int[Di[Mala]];}
    if (Mala==0){
        pun[Mala]=&M[Mala][K0-1][K1-1];}
    else {    
        pun[Mala]=&M[Mala][K0-pos[Mala]][K1-pos[Mala]];}
    for (int fil=0;fil<Di[Mala];fil++){
        for (int col=0;col<Di[Mala];col++){
           if (col==fil && col==(Di[Mala]/2)){}
           else{cont++;
                M[Mala][fil][col]=cont;}}}}
                
 void transfor(int***&M,int Mala1,int Mala2,int*& Di,int K0,int K1,int*& pos,int**& pun,int*& G,int Kmal){
     if (Kmal==0){
         if (Di[Mala1]>Di[Mala2]){
             while (Di[Mala1]>Di[Mala2]){
                 Aumentar(M,Mala2,Di,K0,K1,pos,pun);}}
         else if (Di[Mala1]<Di[Mala2]){
             while (Di[Mala1]<Di[Mala2]){
                 Aumentar(M,Mala1,Di,K0,K1,pos,pun);}}
         else {
          while (G[Mala1]!=0){
              girar(M,Mala1,Di,G);}
          while (G[Mala2]!=0){
              girar(M,Mala2,Di,G);}}}
     else if (Kmal==1){
         while (*pun[Mala1]<=*pun[Mala2]){
             for (int j=0;j<4;j++){
                 for (int i=0;i<4;i++){
                     girar(M,Mala2,Di,G);
                     if (*pun[Mala1]>*pun[Mala2]){
                         return;}}
                 if (*pun[Mala1]<=*pun[Mala2]){
                     girar(M,Mala1,Di,G);
                     if (*pun[Mala1]>*pun[Mala2]){
                         return;}}}
             if (*pun[Mala1]<=*pun[Mala2]){
                 cout <<*pun[Mala1]<< endl;
                 Aumentar(M,Mala1,Di,K0,K1,pos,pun);
                 if (*pun[Mala1]>*pun[Mala2]){
                         return;}}}}
     else {
         while (*pun[Mala1]>=*pun[Mala2]){
             for (int j=0;j<4;j++){
                 for (int i=0;i<4;i++){
                     girar(M,Mala2,Di,G);
                     if (*pun[Mala1]<*pun[Mala2]){
                         return;}}
                 if (*pun[Mala1]>=*pun[Mala2]){
                     girar(M,Mala1,Di,G);
                     if (*pun[Mala1]<*pun[Mala2]){
                         return;}}}
             if (*pun[Mala1]>=*pun[Mala2]){
                 cout <<*pun[Mala1]<< endl;
                 Aumentar(M,Mala2,Di,K0,K1,pos,pun);
                 if (*pun[Mala1]<*pun[Mala2]){
                         return;}}}}}
             
int* salida (int Di[],int N){
    int* X=  new int[N];
    int j=0;
    for (int i=N-1;i>=0;i--){
        X[j]=Di[i];
        j++;}
    return X;}
    
            
int main(){
    int K[]={4,3,1,-1,1};
    int* pos;
    int* Di;
    int* G;
    int Mala1,Mala2,malK;
    int N=(sizeof(K)/sizeof(K[0]))-1;
    int*** M=matrizM(N,K[0],K[1],Di,G);
    llenar(M,Di,N);
    int** pun=puntero(N,K[0],K[1],M,Di[0],Di[1],pos);
    bool cumple=false;
    while (cumple==false){
        cumple=cumplimiento(K,N,pun,Mala1,Mala2,malK);
        transfor(M,Mala1,Mala2,Di,K[0],K[1],pos,pun,G,malK);}
    int* X=salida(Di,N);
    cout << "X{";
    for (int i = 0; i < N; ++i) {
        cout << X[i];
        if (i==N-1){
            cout << '}' << endl;}
        else {cout << ",";}}
    cout << "G{";
    for (int i = N-1; i >=0; --i) {
        cout << G[i];
        if (i==0){
            cout << '}' << endl;}
        else {cout << ",";}}}
