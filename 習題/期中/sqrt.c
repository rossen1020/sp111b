#include "sqrt.h"

double sqrt(double e)
{
    if (e < 0.0)
    {
        return -1; 
    }

    double i = e / 2.0; 
    double m;

    do {
        double n= (i+ e/ i)/ 2;
        m= n- i;
        i= n;
    }while (m > 0.00000001 || m < -0.00000001);

    return i;
}
