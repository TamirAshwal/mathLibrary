#include <stdio.h>
#include <errno.h>
#include "../include/allMathFunctions.h"
#include "geometry.h"
point createPoint(double x, double y){
    point p;
    p.x = x;
    p.y = y;
    return p;
}
circle createCircle(point a, double radios){
    circle c;
    c.a = a;
    c.radios = radios;
    return c;
}
point getPoint(){
    double x,y;
    scanf("%lf",&x);
    scanf("%lf",&y);
    point p;
    p.x = x;
    p.y = y;
    return p;
}
squareShape createSquare(point p1, point p2){
    // p1 and p2 are the 2 points on the diagonal
    squareShape s;
    s.a = p1;
    s.b = p2;
    s.area = squareArea(p1, p2);
    s.perimeter = squarePerimeter(p1, p2);
    s.side = squareSide(p1, p2);
    return s;
}
double squareArea(point p1, point p2){
    double length = distance(p1, p2);
    return divide(square(length), 2);


}
double squarePerimeter(point p1, point p2){
    return 4 * squareSide(p1, p2);

}
double distance(point p1, point p2){
    double distance = squareRoot(add(square(sub(p2.x, p1.x)), square(sub(p2.y, p1.y))));
    return distance;
}
double squareSide(point p1, point p2){
    return sinFunction(degreesToRadian(45)) * distance(p1, p2);
}
double calculateCircleArea(circle c){
    return square(c.radios) * PI;
}
double calculateCircleCircumference(circle c){
    return (2 * PI * c.radios);
}