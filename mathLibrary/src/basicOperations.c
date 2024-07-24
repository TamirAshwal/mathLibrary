#include <stdio.h>
#include <errno.h>
#include "../include/allMathFunctions.h"
#include "../include/basicOperations.h"
#include "../include/linearAlgebra.h"
double add(double x, double y){
    return x +y;
}
double sub(double x, double y){
    return x- y;
}
double multiply(double x, double y){
    return x * y;
}
double divide (double x, double y){
    if(y == 0){
        errno = EDOM;
        printf("division by zero\n");
        return 0.0;
    }
    return x / y;
}
double factorial(int num){
    if(num == 0){
        return 1;
    }
    double res = 1;
    for(int i = 1; i <= num; i++){
        res *=i;
    }
    return res;
}
double absoluteValue(double x){
    if(x < 0){
        return (x *= -1);
    }
    else{
        return x;
    }
}
double square(double num){
    double res = num * num;
    return res;
}
double power(double base, int exponent){
    double res = 1;
    for(int i = 1; i <= exponent; i++){
        res *= base;
    }
    return res;
}
double squareRoot(double num){
    if(num == 0){
        return 0;
    }
    double guess = 1;
    while(absoluteValue(num - square(guess)) > EPSILON){
        guess = (0.5*(guess + (num / guess)));
    }
    return guess;
}