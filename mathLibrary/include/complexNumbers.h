#ifndef MATHLIBRARY_COMPLEXNUMBERS_H
#define MATHLIBRARY_COMPLEXNUMBERS_H
typedef struct complexNumber{
    double real;
    double imaginary;
}complexNumber;
complexNumber createNum(double real, double imaginary);
void printNum(complexNumber num);
void printReal(double real);
void printImaginary(double imaginary, int caseToPrint );
complexNumber addComplexNumber(complexNumber num1, complexNumber num2);
complexNumber subtractComplexNumber(complexNumber num1, complexNumber num2);
complexNumber conjugate(complexNumber a);
complexNumber complexMultiplication(complexNumber num1, complexNumber num2);
int imaginaryCase(complexNumber num1, complexNumber num2);
complexNumber divideComplexNumbers(complexNumber num1, complexNumber num2);
double conjugateMultiplication(complexNumber num1);

#endif //MATHLIBRARY_COMPLEXNUMBERS_H
