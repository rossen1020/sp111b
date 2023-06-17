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
