#include<iostream>
#include<cmath>

double funct(double x);
double derivative(double x, double h);
double integral(double lower_bound, double upper_bound);
double max_pt(int lower_bound, int upper_bound, double step);
double min_pt(int lower_bound, int upper_bound, double step);

int main() {
    std::cout.precision(4);
    std::cout<<derivative(2,0.001)<<std::endl;
    std::cout<<integral(-2,2)<<std::endl;
    std::cout<<max_pt(1,5,0.1)<<std::endl;
    std::cout<<min_pt(1,5,0.1)<<std::endl;
}
inline double funct(double x)
{
    return exp(x)*sin(x)*cos(x);
}
double derivative(double x, double h)
{
    double f1;
    f1=(funct(x+h)-funct(x))/h;
    return f1;
}
double integral(double lower_bound, double upper_bound) {
    double step = (upper_bound-lower_bound)/100;
    double upper_area {0};
    double lower_area {0};
    double current, next;
    for (size_t i = 0; i < 100; ++i){
        current = lower_bound + (step*i);
        next = lower_bound+(step*(i+1));
        upper_area += (funct(next)*step);
        lower_area += (funct(current)*step);
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
