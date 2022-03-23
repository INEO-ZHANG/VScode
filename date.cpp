#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

#define MAX 20

void Date(char a[]);

int main() {
    char s[MAX];
    cin.getline(s,MAX);
    Date(s);
    return 1;
}

void Date(char a[]){
    char hour[10], min[10], sec[10], day[10], mon[10], year[10];
    int i = 0, j = 0;
    for ( ; a[i] != ':'; i++) {
        hour[i] = a[i];
    }
    i++;
    for (j = 0; a[i] != ':'; i++) {
        min[j] = a[i];
        j++;
    }
    i++;
    for (j = 0; a[i] != ' '; i++) {
        sec[j] = a[i];
        j++;
    }
    i++;
    for (j = 0; a[i] != '.'; i++) {
        day[j] = a[i];
        j++;
    }
    i++;
    for (j = 0; a[i] != '.'; i++) {
        mon[j] = a[i];
        j++;
    }
    i++;
    for (j = 0; i<strlen(a); i++) {
        year[j] = a[i];
        j++;
    }
    long long nhour, nmin, nsec, nday, nmon, nyear;
    //字符串转换为数字
    nhour = atoi(hour);
    nmin = atoi(min);
    nsec = atoi(sec);
    nday = atoi(day);
    nmon = atoi(mon);
    nyear = atoi(year);
    //cout << nhour << ':' << nmin << ':' << nsec << ' ' << nday << '.' << nmon << '.' << nyear << endl;
    long long sumDay = 0;
    long long month[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    long long month1[12] = { 0,31,60,91,121,152,182,213,244,274,305,335 };
    if(((nyear%4==0)&&(nyear%100!=0))||nyear%400==0){  //闰年
        sumDay = month1[(nmon - 1)]  + (nday - 1) ;
    }
    else{
        sumDay = month[(nmon-1)] + (nday - 1);
    }
    
    for(i=2000;i<nyear;i++){
        if(((i%4==0)&&(i%100!=0))||i%400==0)
        sumDay+=366;
        else
        sumDay+=365;
    }
    int mhour, mmin, msec, mday, mmon, myear;
    myear = sumDay / 1000;
    mmon = ((sumDay % 1000) / 100) + 1;
    mday = ((sumDay % 1000) % 100) + 1;
    long long sumSec=0;
    sumSec=nhour*3600+nmin*60+nsec;
    mhour=sumSec/8640;
    mmin=(sumSec%8640)/86.4;
    msec=(sumSec%8640)/86.4;
    
    cout << mhour << ':' << mmin << ':' << msec << ' ' << mday << '.' << mmon << '.' << myear << endl;
    system("pause");
}
