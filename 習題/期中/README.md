
### 來源說明:

> 此專案是我去參考學習同學sum的函式庫,以此建立的;
除去sum部分其餘 power(次方), sqrt(開根)均為自己寫的 

---
### 測驗

main.c
```
#include <stdio.h>
#include "sum.h"
#include "pow.h"
#include "sqrt.h"

int main(void)
{
    int a=20;
    int b=17;
    printf("%d+%d=%d\n",a,b,sum(a,b));

    int c=2;
    int d=4;
    printf("%d^%d=%d\n",c,d,power(c,d));

    double e = 36.00;
    double i = sqrt(e);
    if (i ==-1)
    {
        printf("wrong!");
    }
    else printf(" The root of %f=%f\n", e, i);

}
```
結果:
```
PS C:\Users\rossan\Desktop\系統> gcc -o program pow.c sum.c sqrt.c main.c 
                               >> ./main.c
PS C:\Users\rossan\Desktop\系統> ./program
20+17=37
2^4=16
The root of 36.000000=6.000000
```
