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
    long long sumSec = 0;
    long long month[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    long long month1[12] = { 0,31,60,91,121,152,182,213,244,274,305,335 };
    if((nyear-2000)%4==0){  //闰年
        sumSec = ((nyear - 2000) / 4) * 126230400  + month1[(nmon - 1)] * 86400 + (nday - 1) * 86400 + nhour * 3600 + nmin * 60 + nsec;
    }
    else if ((nyear - 2000) % 4 == 1) {                  //平年1
        sumSec = ((nyear - 2000) / 4) * 126230400 + 31622400 + month[(nmon - 1)] * 86400 + (nday - 1) * 86400 + nhour * 3600 + nmin * 60 + nsec;
    }
    else if ((nyear - 2000) % 4 == 2) {                  //平年2
        sumSec = ((nyear - 2000) / 4) * 126230400 + 63158400 + month[(nmon - 1)] * 86400 + (nday - 1) * 86400 + nhour * 3600 + nmin * 60 + nsec;
    }
    else {                  //平年3
        sumSec = ((nyear - 2000) / 4) * 126230400 + 94694400 + month[(nmon - 1)] * 86400 + (nday - 1) * 86400 + nhour * 3600 + nmin * 60 + nsec;
    }
    int mhour, mmin, msec, mday, mmon, myear;
    myear = sumSec / 100000000;
    mmon = ((sumSec % 100000000) / 10000000) + 1;
    mday = (((sumSec % 100000000) % 10000000) / 100000) + 1;
    mhour = (((sumSec % 100000000) % 10000000) % 100000) / 10000;
    mmin = ((((sumSec % 100000000) % 10000000) % 100000) % 10000) / 100;
    msec = ((((sumSec % 100000000) % 10000000) % 100000) % 10000) % 100;
    cout << mhour << ':' << mmin << ':' << msec << ' ' << mday << '.' << mmon << '.' << myear << endl;
}
