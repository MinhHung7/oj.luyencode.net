#include<stdio.h>
const int count = 8;
int money [] = {200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000};
void in(int n,int i){
    printf("%d %d", i, n);
}
void changeMoney(int n, int i){
    while(money[i] > n && i<count){
        ++i;
    }
    if(money[i]<=n && i<count){
        int tien = n;
        while(i<count){
            for(int h = n/money[i];h>=1;--h){
                n = tien;
                if(i==count-1 && h<n/money[i]) break;
                printf("%d %d ", h, money[i]);
                n-=h*money[i];
                int j=i+1;
                while(n!=0){
                    while(money[j] > n){
                        ++j;
                    }
                    if(money[j]<=n){
                        in(money[j],n/money[j]);
                        n-=n/money[j]*money[j];
                    }
                    ++j;
                }
                printf("\n");
            }
            ++i;
            n=tien;
        }
    }
}
int main(){
    int loop = 1;
    int n = 0;
    do{
        printf("Nhap so tien muon doi: ");
        scanf("%d",&n);
        ++loop;
    }
    while(loop <= 5 && n<=2000);
    if(loop>5){
        printf("Stopped program!!");
    }
    else{
        changeMoney(n,0);
    }
    return 0;
}