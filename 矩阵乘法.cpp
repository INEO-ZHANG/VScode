#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<math.h>
#include<time.h>
using namespace std;

int N = (1 << 8);

void gemm_baseline(float *A, float *B, float *C);

int main()  {
    float *A,*B,*C;
    time_t t;
    srand((unsigned)time(&t));
    A=new float[N*N];
    B=new float[N*N];
    C=new float[N*N];
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            A[i*N+j]=(float)(rand())/((float)(RAND_MAX/10));
            B[i*N+j]=(float)(rand())/((float)(RAND_MAX/10));
        }
    clock_t start,end;
    start=clock();
    gemm_baseline(A,B,C);
    end=clock();
    double T=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"time="<<T<<endl;
    return 0;
}

void gemm_baseline(float *A,float *B,float *C){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++){
                C[i*N+j]+=A[i*N+k]*B[k*N+j];
            }
}