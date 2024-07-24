#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "../include/allMathFunctions.h"
#include "../include/basicOperations.h"
#include "../include/trigonometricFunctions.h"
double sinFunction(double x){
    double sum = 0;
    for(int i = 0; i < PRECISION; i++){
        double sign = power(-1, i);
        sum +=(sign / (factorial((2 * i) + 1))) * power(x, (2 * i) + 1);
    }
    return sum;
}
double cosFunction(double x){
    double sum = 0;
    for(int i = 0; i < PRECISION; i++){
        double sign = power(-1, i);
        sum += ((sign / factorial(2 * i)) * power(x, 2 * i));
    }
    return sum;
}
double radianToDegrees(double r){
    return (r * (180 / PI));
}
double degreesToRadian(double d){
    return (d * (PI / 180));
}