#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<stack>
#include<algorithm>
#include<ctime>
#include<math.h>
using namespace std;
clock_t Start,End;
/*void A_h1(const vector<vector<int> > &start, const vector<vector<int> >
&target);
void A_h2(const vector<vector<int> > &start, const vector<vector<int> >
&target);
void IDA_h1(const vector<vector<int> > &start, const vector<vector<int> >
&target);
void IDA_h2(const vector<vector<int> > &start, const vector<vector<int> >
&target);*/
void A_h1(const int start[5][5], const int target[5][5]);
void A_h2(const int start[5][5], const int target[5][5]);
void IDA_h1(const int start[5][5], const int target[5][5]);
void IDA_h2(const int start[5][5], const int target[5][5]);

int S[5][5];    //开始状态
int T[5][5];   //目标状态

//h1错位星球数
int counth1(const int a[5][5],const int b[5][5]){
    int h=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            if(a[i][j]!=b[i][j])h++;
        }
    return h;
}

//h2欧氏距离
int counth2(const int a[5][5],const int b[5][5]){
    int h=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            for(int p=0;p<5;p++)
                for(int q=0;q<5;q++){
                    if(a[i][j]==b[p][q]){
                        h+=sqrt(pow(i-p,2)+pow(j-q,2));
                    }
                }
    return h;
}
typedef struct _status{
    int status[5][5];
    _status *parent;
    _status *child;
    char step;
}status;

status NEXT[4];
//用于A*排序
bool Compare(const status &s1,const status &s2){
    int g1=0,g2=0,h1=0,h2=0;
    const status *ptr1=&s1;
    const status *ptr2=&s2;
    while(ptr1!=NULL){
        g1++;
        ptr1=ptr1->parent;
    }
    while(ptr2!=NULL){
        g2++;
        ptr2=ptr2->parent;
    }
    h1=counth1(s1.status,T);
    h2=counth1(s2.status,T);
    return (g1+h1)>(g2+h2);
}
//h2 A*排序
bool Compare2(const status &s1,const status &s2){
    int g1=0,g2=0,h1=0,h2=0;
    const status *ptr1=&s1;
    const status *ptr2=&s2;
    while(ptr1!=NULL){
        g1++;
        ptr1=ptr1->parent;
    }
    while(ptr2!=NULL){
        g2++;
        ptr2=ptr2->parent;
    }
    h1=counth2(s1.status,T);
    h2=counth2(s2.status,T);
    return (g1+h1)>(g2+h2);
}

//h1的f值
int h1_f(const status &s1){
    int g1=0,h1=0;
    const status *ptr1=&s1;
    while(ptr1!=NULL){
        g1++;
        ptr1=ptr1->parent;
    }
    h1=counth1(s1.status,T);
    return (g1+h1);
}

//h2的f值
int h2_f(const status &s1){
    int g1=0,h1=0;
    const status *ptr1=&s1;
    while(ptr1!=NULL){
        g1++;
        ptr1=ptr1->parent;
    }
    h1=counth2(s1.status,T);
    return (g1+h1);
}

//定位飞船位置
void xypos(status *temp,int &x,int &y){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(temp->status[i][j]==0){
                x=i;
                y=j;
                break;
            }
}

void holepos(status *temp,int &x,int &y){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(temp->status[i][j]<0){
                x=i;
                y=j;
                return;
            }
    x=-1;
    y=-1;
}
//状态的子状态,下一步可能性
int NEXTNUMBER(status *temp){
    int nextnumber=0;
    int x,y,hx,hy;
    xypos(temp,x,y);
    holepos(temp,hx,hy);
    if(hx==-1&&hy==-1){
        //不在最左边或者在第三行
        if(y>=1||x==2){
            status left=*temp;
            left.status[x][y]=left.status[x][(y+4)%5];
            left.status[x][(y+4)%5]=0;
            left.step='L';
            NEXT[nextnumber]=left;
            NEXT[nextnumber].parent=temp;
            nextnumber++;
        }
        //不在最右边或者在第三行
        if(y<=3||x==2){
            status right=*temp;
            right.status[x][y]=right.status[x][(y+1)%5];
            right.status[x][(y+1)%5]=0;
            right.step='R';
            NEXT[nextnumber]=right;
            NEXT[nextnumber].parent=temp;
            nextnumber++;
        }
        //不在最上边或者在第三列
        if(x>=1||y==2){
            status up=*temp;
            up.status[x][y]=up.status[(x+4)%5][y];
            up.status[(x+4)%5][y]=0;
            up.step='U';
            NEXT[nextnumber]=up;
            NEXT[nextnumber].parent=temp;
            nextnumber++;
        }
        //不在最下边或者在第三列
        if(x<=3||y==2){
            status down=*temp;
            down.status[x][y]=down.status[(x+1)%5][y];
            down.status[(x+1)%5][y]=0;
            down.step='D';
            NEXT[nextnumber]=down;
            NEXT[nextnumber].parent=temp;
            nextnumber++;
        }
    }
    else{    
    //不在最左边和黑洞右边或者在第三行
    if((y>=1||x==2)&&!(x==hx&&y==(hy+1)%5)){
        status left=*temp;
        left.status[x][y]=left.status[x][(y+4)%5];
        left.status[x][(y+4)%5]=0;
        left.step='L';
        NEXT[nextnumber]=left;
        NEXT[nextnumber].parent=temp;
        nextnumber++;
    }
    //不在最右边和黑洞左边或者在第三行
    if((y<=3||x==2)&&!(x==hx&&y==(hy+4)%5)){
        status right=*temp;
        right.status[x][y]=right.status[x][(y+1)%5];
        right.status[x][(y+1)%5]=0;
        right.step='R';
        NEXT[nextnumber]=right;
        NEXT[nextnumber].parent=temp;
        nextnumber++;
    }
    //不在最上边和黑洞下边或者在第三列
    if((x>=1||y==2)&&!(y==hy&&x==(hx+1)%5)){
        status up=*temp;
        up.status[x][y]=up.status[(x+4)%5][y];
        up.status[(x+4)%5][y]=0;
        up.step='U';
        NEXT[nextnumber]=up;
        NEXT[nextnumber].parent=temp;
        nextnumber++;
    }
    //不在最下边和黑洞上边或者在第三列
    if((x<=3||y==2)&&!(y==hy&&x==(hx+4)%5)){
        status down=*temp;
        down.status[x][y]=down.status[(x+1)%5][y];
        down.status[(x+1)%5][y]=0;
        down.step='D';
        NEXT[nextnumber]=down;
        NEXT[nextnumber].parent=temp;
        nextnumber++;
    }
    }
    return nextnumber;
}
//打印函数
void PRINTPATH(status *goal){
    cout<<"path:";
    stack<char> result;
    status *p=goal;
    while(p!=NULL){
        result.push(p->step);
        p=p->parent;
    }
    result.pop();
    while(!result.empty()){
        cout<<result.top();
        result.pop();
    }
}
//遍历closeTable
int IncloseTable(status *temp,status *closeTable){
    int IN=0;
    status *cur=closeTable;
    while(cur!=NULL){
        if(counth1(cur->status,temp->status)==0){
            IN=1;
            break;
        }
        cur=cur->child;
    }
    return IN;
}
//遍历openTable
int InopenTable(vector<status> openTable,status *temp){
    int IN=0;
    for(int i=0;i<openTable.size();i++){
        if(counth1(openTable[i].status,temp->status)==0){
            IN=1;
            break;
        }
    }
    return IN;
}
//释放closeTable
void freeCloseTable(status *closeTable){
    status *cur;
    while(closeTable != NULL){
        cur = closeTable->child;
        free(closeTable);
        closeTable = cur;
    }

}
//启发函数h1的A*算法
void A_h1(const int start[5][5], const int target[5][5]){
    int step=0;
    vector<status>  openTable;
    status *closeTable = new status;
    status *cur=closeTable;
    status *temp;
    status root;
    status goal;
    root.parent=NULL;
    root.child=NULL;
    goal.parent=NULL;
    goal.child-NULL;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
        root.status[i][j]=start[i][j];
        goal.status[i][j]=target[i][j];
        }
    openTable.push_back(root);
    while(!openTable.empty()){
        temp=new status;
        *temp=openTable[openTable.size()-1];
        openTable.pop_back();
        step++;
        cur->child=temp;
        cur=cur->child;
        //目标
        if(counth1(temp->status,target)==0){
            //cout<<step;
            PRINTPATH(temp);
            freeCloseTable(closeTable);
            return;
        }
        int nextnumber=NEXTNUMBER(temp);
        for(int i=0;i<nextnumber;i++){
            if(IncloseTable(NEXT+i,closeTable))continue;
            if(InopenTable(openTable,NEXT+i))continue;
            if(temp->step=='L'&&NEXT[i].step=='R')continue;
            if(temp->step=='R'&&NEXT[i].step=='L')continue;
            if(temp->step=='U'&&NEXT[i].step=='D')continue;
            if(temp->step=='D'&&NEXT[i].step=='U')continue;
            openTable.push_back(NEXT[i]);
        }
        sort(openTable.begin(),openTable.end(),Compare);
    }
    cout<<"failed"<<endl;
    freeCloseTable(closeTable);
}

//h2 A*
void A_h2(const int start[5][5], const int target[5][5]){
    int step=0;
    vector<status>  openTable;
    status *closeTable = new status;
    status *cur=closeTable;
    status *temp;
    status root;
    status goal;
    root.parent=NULL;
    root.child=NULL;
    goal.parent=NULL;
    goal.child-NULL;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
        root.status[i][j]=start[i][j];
        goal.status[i][j]=target[i][j];
        }
    openTable.push_back(root);
    while(!openTable.empty()){
        temp=new status;
        *temp=openTable[openTable.size()-1];
        openTable.pop_back();
        step++;
        cur->child=temp;
        cur=cur->child;
        //目标
        if(counth1(temp->status,target)==0){
            //cout<<step;
            PRINTPATH(temp);
            freeCloseTable(closeTable);
            return;
        }
        int nextnumber=NEXTNUMBER(temp);
        for(int i=0;i<nextnumber;i++){
            if(IncloseTable(NEXT+i,closeTable))continue;
            if(InopenTable(openTable,NEXT+i))continue;
            if(temp->step=='L'&&NEXT[i].step=='R')continue;
            if(temp->step=='R'&&NEXT[i].step=='L')continue;
            if(temp->step=='U'&&NEXT[i].step=='D')continue;
            if(temp->step=='D'&&NEXT[i].step=='U')continue;
            openTable.push_back(NEXT[i]);
        }
        sort(openTable.begin(),openTable.end(),Compare2);
    }
    cout<<"failed"<<endl;
    freeCloseTable(closeTable);
}
//
void IDA_h1(const int start[5][5], const int target[5][5]){
    int step=0;
    int fmax=0;         //每次的深度限制
    vector<status>  openTable;
    status *closeTable = new status;
    status *cur=closeTable;
    status *temp;
    status root;
    status goal;
    root.parent=NULL;
    root.child=NULL;
    goal.parent=NULL;
    goal.child-NULL;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
        root.status[i][j]=start[i][j];
        goal.status[i][j]=target[i][j];
        }
    fmax=h1_f(root);
    openTable.push_back(root);
    while(!openTable.empty()){
        temp=new status;
        *temp=openTable[openTable.size()-1];
        openTable.pop_back();
        step++;
        cur->child=temp;
        cur=cur->child;
        //目标
        if(counth1(temp->status,target)==0){
            //cout<<step;
            PRINTPATH(temp);
            freeCloseTable(closeTable);
            return;
        }
        if(h1_f(*temp)>fmax){
            fmax+=h1_f(*temp);  //提高深度限制
            *temp=root;
            continue;
        }
        int nextnumber=NEXTNUMBER(temp);
        for(int i=0;i<nextnumber;i++){
            if(IncloseTable(NEXT+i,closeTable))continue;
            if(InopenTable(openTable,NEXT+i))continue;
            if(temp->step=='L'&&NEXT[i].step=='R')continue;
            if(temp->step=='R'&&NEXT[i].step=='L')continue;
            if(temp->step=='U'&&NEXT[i].step=='D')continue;
            if(temp->step=='D'&&NEXT[i].step=='U')continue;
            openTable.push_back(NEXT[i]);
        }
        sort(openTable.begin(),openTable.end(),Compare);
    }
    cout<<"failed"<<endl;
    freeCloseTable(closeTable);
}

//IDA_h2
void IDA_h2(const int start[5][5], const int target[5][5]){
    int step=0;
    int fmax=0;         //每次的深度限制
    int smax=500;
    vector<status>  openTable;
    status *closeTable = new status;
    status *cur=closeTable;
    status *temp;
    status root;
    status goal;
    root.parent=NULL;
    root.child=NULL;
    goal.parent=NULL;
    goal.child-NULL;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
        root.status[i][j]=start[i][j];
        goal.status[i][j]=target[i][j];
        }
    fmax=h2_f(root);
    openTable.push_back(root);
    while(!openTable.empty()){
        temp=new status;
        *temp=openTable[openTable.size()-1];
        if(h2_f(*temp)>fmax||step>smax){
            smax+=h2_f(*temp);
            fmax+=h2_f(*temp);  //提高深度限制
            //openTable.clear();
            //openTable.push_back(root);
            vector<status>::iterator it;
            *temp=openTable[openTable.size()/2];
            for(it=openTable.begin();it!=openTable.end();it++){
                if(counth1((*it).status,openTable[openTable.size()/2].status)==0){
                    openTable.erase(it);
                    break;
                }
            }
            step=0;
        }else{
        openTable.pop_back();
        }
        step++;
        cur->child=temp;
        cur=cur->child;
        //目标
        if(counth1(temp->status,target)==0){
            cout<<step;
            PRINTPATH(temp);
            freeCloseTable(closeTable);
            return;
        }
        int nextnumber=NEXTNUMBER(temp);
        for(int i=0;i<nextnumber;i++){
            if(IncloseTable(NEXT+i,closeTable))continue;
            if(InopenTable(openTable,NEXT+i))continue;
            if(temp->step=='L'&&NEXT[i].step=='R')continue;
            if(temp->step=='R'&&NEXT[i].step=='L')continue;
            if(temp->step=='U'&&NEXT[i].step=='D')continue;
            if(temp->step=='D'&&NEXT[i].step=='U')continue;
            openTable.push_back(NEXT[i]);
        }
        sort(openTable.begin(),openTable.end(),Compare2);
    }
    cout<<"failed"<<endl;
    freeCloseTable(closeTable);
}
int main(int argc, char *argv[]){
    char *F_name;
    string IN_name,OUT_name;
    if(argc==4){
    F_name=argv[1];
    IN_name=argv[2];
    OUT_name=argv[3];
    }
    else{
        cout<<"输入参数不足"<<endl;
        exit(1);
    }

    //读文件
    /*vector<vector<int>> S;
    vector<int> s;*/
    fstream fin;
    fin.open(("data/"+IN_name),ios::in);
    if(!fin.is_open()){
        cout<<"cannot open the file!"<<endl;
        exit(1);
    }
    /*for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int temp;
            fin>>temp;
            s.push_back(temp);
        }
        S.push_back(s);
        s.clear();
    }*/
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            fin>>S[i][j];
        }
    }
    fin.close();

    fstream fin1;
    fin1.open(("data/"+OUT_name),ios::in);
    if(!fin1.is_open()){
        cout<<"cannot open the file!"<<endl;
        exit(1);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            fin1>>T[i][j];
        }
    }
    /*for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //cout<<argc;
    //cout<<F_name<<endl<<IN_name<<endl<<OUT_name<<endl;
    char A1[]="A_h1";
    char A2[]="A_h2";
    char IDA1[]="IDA_h1";
    char IDA2[]="IDA_h2";
    Start=clock();
    if(!strcmp(F_name,A1)){
        cout<<"use A_h1 ";
        A_h1(S,T);
    }
    if(!strcmp(F_name,A2)){
        cout<<"use A_h2 ";
        A_h2(S,T);
    }
    if(!strcmp(F_name,IDA1)){
        cout<<"use IDA_h1";
        IDA_h1(S,T);
    }
    if(!strcmp(F_name,IDA2)){
        cout<<"use IDA_h2";
        IDA_h2(S,T);
    }
    End=clock();
    double sumTime=(double)(End-Start)/CLOCKS_PER_SEC;
    cout<<" "<<sumTime<<"s"<<endl;
    cout<<" "<<sumTime*1000<<"ms"<<endl;
}
