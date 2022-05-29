#include<iostream>
using namespace std;

int result[7][10]={0};
int input1[7]={1,1,0,0,0,0,0};
int input[10]={1,1,0,0,0,0,0,1,0,1};
int workerNum=7;
int cannot[10][10];
//1. 每个工人每周必须休息2天或2天以上
bool C1(int worker){
    int sumday=0;
        for(int j=0;j<7;j++){
            if(result[j][worker]==1){
                sumday++;
            }
        }
        if(sumday>5)return 0;
    return 1;
}

//2. 每个工人每周不可以连续休息3天(不考虑跨周情况)
bool C2(int worker,int day){
    if(day>2){
        int breakDay=0;
        for(int i=0;i<day-2;i++){
            if(result[i][worker]==0&&result[i+1][worker]==0&&result[i+2][worker]==0){
                return 0;
            }
        }
    }
    return 1;
}

//3. 周六周天也需要有人值班，即一周7天每天都要安排工人值班
//4. 每天至少要有3个人值班
//可以合起来
bool C3(int worker,int day){
    //if(day>0){
        int countWorker=0;
        //for(int i=0;i<day;i++){
            for(int j=0;j<workerNum;j++){
                if(result[day][j]==1)countWorker++;
            }
            if(countWorker+workerNum-worker<5) return 0;
        //}
    //}
    return 1;
}


//4. 每天至少要有一名级别为 senior 的工人值班
bool C4(int day){
    int flag=0;
    //for(int i;i<=day;i++){
        for(int j=0;j<workerNum;j++){
            if(result[day][j]==1&&input[j]==1){
                flag=1;
                continue;
            }
        }
        if(flag==0)return 0;
        //flag=0;
    //}
    return 1;
}

//5.不能同时工作
bool C5(int day){
    for(int i=0;i<=day;i++){
        for(int j=0;j<workerNum;j++){
            if(result[day][0]==1&&result[day][3]==1)return 0;
            if(result[day][1]==1&&result[day][2]==1)return 0;
            if(result[day][2]==1&&result[day][5]==1)return 0;
        }
    }
    return 1;
}

int find(int i){
    int worker=i%workerNum,day=i/7;
    if(i==7*workerNum)return 1;
    result[day][worker]=0;
    if(C1&&C2(worker,day)&&C3(worker,day)&&C4(day)&&C5(day)){
        if(find(i+1))
        return 1;
    }
    result[day][worker]=1;
    if(C1&&C2(worker,day)&&C3(worker,day)&&C4(day)&&C5(day)){
        if(find(i+1))
        return 1;
    }
    return 0;
}
int main(){
    int i=0;
    find(i);
    for(int x=0;x<7;x++){
        for(int y=0;y<workerNum;y++){
            if(result[x][y]==1)cout<<(y+1);
        }
        cout<<endl;
    }
}