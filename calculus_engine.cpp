#include<iostream>
#include<cmath>

float funct(float x);
double derivative(double x, double h);
double integral(double lower_bound, double upper_bound, double n);
double max_pt(int lower_bound, int upper_bound, double step);
double min_pt(int lower_bound, int upper_bound, double step);

int main() {
    std::cout.precision(4);
    std::cout<<max_pt(1,5,0.1);
}
float funct(float x)
{
    return exp(x)*sin(x)*cos(x);
}
double derivative(double x, double h)
{
    float f1;
    f1=(funct(x+h)-funct(x))/h;
    return f1;
}
double integral(double lower_bound, double upper_bound, double n) {
    double step = (upper_bound-lower_bound)/n;
    double upper_area {0};
    double lower_area {0};
    for (size_t i = lower_bound; i < upper_bound; i=i+step){
        upper_area = upper_area + (funct(i+step)*step);
        lower_area = lower_area + (funct(i)*step);
    }
    double area = (upper_area+lower_area)/2.0;
    return area;
}
double max_pt(int lower_bound, int upper_bound, double step) {
    double next;
    int range = upper_bound - lower_bound;
    double current = rand()%range + lower_bound;
    for (size_t i = 0; i<100; ++i){
        if (current+step <= upper_bound)
            next = current + step;
        else
            next = current;
        if (funct(next)>funct(current)) 
            current += step;
        else if (funct(next)>funct(current))
            current -= step;
        else
            return funct(current);

    }
    return funct(current);
}
double min_pt(int lower_bound, int upper_bound, double step) {
    double next;
    int range = upper_bound - lower_bound;
    double current = rand()%range + lower_bound;
    for (size_t i = 0; i<100; ++i){
        if (current+step <= upper_bound)
            next = current + step;
        else
            next = current;
        if (funct(next)<funct(current)) 
            current += step;
        else if (funct(next)>funct(current))
            current -= step;
        else
            return funct(current);
    }
    return funct(current);
}