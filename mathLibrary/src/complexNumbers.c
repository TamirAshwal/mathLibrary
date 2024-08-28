#include <stdio.h>
#include <errno.h>
#include "../include/allMathFunctions.h"
#include "complexNumbers.h"
complexNumber createNum(double real, double imaginary){
    complexNumber num;
    num.real = real;
    num.imaginary = imaginary;
    return num;
}

void printNum(complexNumber num){
    int imaginaryCase;
    //
   if(num.real == 0 && num.imaginary == 0) {
       printf("0");
       printf("\n");
       return;
   }
   //only imaginary part i
   else if(num.real == 0 && num.imaginary == 1){
       printImaginary(num.imaginary, 1);
       printf("\n");
       return;
   }
   //only imaginary part  -i
   else if(num.real == 0 && num.imaginary == -1){
       printImaginary(num.imaginary, 2);
       printf("\n");
       return;
   }
   // only imaginary case bi
   else if(num.real == 0 && num.imaginary != 0){
       printImaginary(num.imaginary, 5);
       printf("\n");
       return;
   }
   // only real part
   else if(num.real != 0 && num.imaginary == 0){
       printReal(num.real);
       printf("\n");
       return;
   }
   else if(num.real != 0 && num.imaginary == 1){
       printReal(num.real);
       printImaginary(num.imaginary, 3);
       printf("\n");
       return;
   }
   else if(num.real != 0 && num.imaginary == -1){
       printReal(num.real);
       printImaginary(num.imaginary, 4);
       printf("\n");
       return;
   }
   else {
       printReal(num.real);
       printImaginary(num.imaginary, 5);
       printf("\n");
       return;
   }
}
void printReal(double real){
    printf("%.2lf ", real);
    return;
}
void printImaginary(double imaginary, int caseToPrint){
    switch (caseToPrint) {
        case 1:
            printf("i");
            break;
        case 2:
            printf("-i");
            break;
        case 3:
            printf("+ i");
            break;
        case 4:
            printf("- i");
            break;
        case 5:
            if(imaginary > 0){
                printf("+ %.2lfi", imaginary);
            }
            else{
                // multiply by -1 so it won't print minus sign twice
                printf("- %.2lfi", imaginary*=-1);
            }
            break;
    }
}
complexNumber addComplexNumber(complexNumber num1, complexNumber num2){
    complexNumber result;
    result.real = num1.real + num2. real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}
complexNumber subtractComplexNumber(complexNumber num1, complexNumber num2){
    complexNumber result;
    result.real = num1.real - num2. real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}
complexNumber conjugate(complexNumber a){
    a.imaginary *= -1;
    return a;
}
double conjugateMultiplication(complexNumber num1){
    // (a + bi) * (a * - bi) = a^2 + b^2
    return (square(num1.real)) + (square(num1.imaginary));

}
complexNumber complexMultiplication(complexNumber num1, complexNumber num2){
    complexNumber newNum;
    int caseToCheck = imaginaryCase(num1, num2);
    switch (caseToCheck) {
        case 1:
            // both y1 and y2 are 0
            newNum.real = num1.real * num2.real;
            newNum.imaginary = (num1.real * num2.imaginary) + (num2.real * num1.imaginary);
            return newNum;
        case 2:
            // (y1 < 0 && y2 > 0) or (y1 > 0 && y2 < 0)
            newNum.real = (num1.real * num2.real) + absoluteValue(num1.imaginary * num2.imaginary);
            newNum.imaginary = (num1.real * num2.imaginary) + (num2.real * num1.imaginary);
            return newNum;
        case 3:
            newNum.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
            newNum.imaginary = (num1.real * num2.imaginary) + (num2.real * num1.imaginary);
            return newNum;
    }
}
int imaginaryCase(complexNumber num1, complexNumber num2) {
    double y1 = num1.imaginary;
    double y2 = num2.imaginary;
    if (y1 == 0 || y2 == 0) {
        return 1;
    }
    else if ((y1 < 0 && y2 > 0) || (y1 > 0 && y2 < 0)) {
        return 2;
    }
    // both y1 and y2 are bigger than 0 or smaller then 0
    else{
        return 3;
    }
}
complexNumber divideComplexNumbers(complexNumber num1, complexNumber num2){
    complexNumber newNum;
    double denominator = conjugateMultiplication(num2);
    complexNumber num3 = complexMultiplication(num1, conjugate(num2));
    newNum.real = divide(num3.real, denominator);
    newNum.imaginary = divide(num3.imaginary, denominator);
    return newNum;
}
