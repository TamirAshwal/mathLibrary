#include <stdio.h>
#include <errno.h>
#include "../include/allMathFunctions.h"

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
double roundCheck(double x){
    if(x == (int) x){
        return x;
    }
    else if(absoluteValue(x - (int) x) >= 0.5){
        x = (double) (int) (x);
        if(x < 0) {
            return x - 1;
        }
        else {
            return x + 1;
        }
    }
    return (double) (int) x;
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
double root(double radicand, double index){
    if(radicand == 0){
        return 0;
    }
    double guess = 1;
    while(absoluteValue(radicand - power(guess, (int)index)) > EPSILON){
        guess = guess - divide(power(guess,(int) index) - radicand,(index) *
                power(guess, (int) index - 1) );
    }
    return guess;
}
double eFunction(double x){
    if(x == 0){
        return 1;
    }
    double res = 0;
    for(int i = 0; i < 20; i++ ){
        res += divide(power(x, i), factorial(i));
    }
    return res;
}
//double lnFunction(double x) {
//    if (x <= 0) {
//        errno = EDOM;
//        printf("x should be greater then 0\n");
//        return 0.0;
//    }
//
//    // Decompose the double
//    int64_t i = *(int64_t*)&x;
//    int exp = ((i >> 52) & 0x7FF) - 1023; // Extract exponent
//    i = (i & 0xFFFFFFFFFFFFF) | 0x3FF0000000000000;
//    double f = *(double*)&i;
//
//    // Range reduction
//    double z;
//    if (f > 1.4142135623730950488) {
//        f *= 0.5;
//        exp++;
//        z = (f - 1) / (f + 1);
//    } else {
//        z = (f - 1) / (f + 1);
//    }
//
//    // Polynomial approximation
//    double z2 = z * z;
//    double r = z * (2 + z2 * (0.666666666666 + z2 * (0.4 + z2 * 0.285714285714)));
//
//    // Combine results
//    return exp * 0.6931471805599453 + 2 * r;
//}