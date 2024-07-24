#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "allMathFunctions.h"
int main(){
    printf("%f\n", add(5,7));
    printf("%f\n", absoluteValue(5));
    double x = radianToDegrees(sinFunction(1));
    printf("%f\n", radianToDegrees(sinFunction(1)));
    printf("%f", degreesToRadian(x));


    return 0;
}