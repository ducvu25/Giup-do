#include <stdio.h>

int main()
{
    int n;
    do{
        printf("Nhap so n: ");
        scanf("%d", &n);
    }while(n < 99 || n > 1000);
    int chan = 0, le = 0;
    while(n != 0){
        if(n%2 == 0)
            chan++;
        else
            le++;
        n/= 10;
    }
    printf("Co %d chu so chan va %d chu so le", chan, le);
    return 0;
}