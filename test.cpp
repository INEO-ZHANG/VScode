#include <iostream> 
#include<stdio.h>
#include<string.h>
#include<vector>
#include<fstream>
using namespace std;
int main(){
    vector<vector<int> > S;
    vector<int> s;
    fstream fin;
    fin.open("data/input00.txt",ios::in);
    if(!fin.is_open()){
        cout<<"cannot open the file!"<<endl;
        exit(1);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int temp;
            fin>>temp;
            s.push_back(temp);
        }
        S.push_back(s);
        s.clear();
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
}