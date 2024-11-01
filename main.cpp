#include <bits/stdc++.h>
using namespace std;

double delta_f = 0.000001;
double delta_u = 5*0.0000001;
double delta_v = 1.8*0.0000001;
//линейная функция phi= 1 + x не даёт погрешности
double delta_psi = 1.8*0.0000001;
double factorial(int k){
    int num = 1;
    for(int i = 1; i <= k; i++){
        num = num * i;
    }
    return num;
}

double power(double x, int k){
    double mn = x;
    if (k == 0)
        return 1;
    else{
        for(int i = 0; i < k-1; i++)
            mn = mn * x;
    }
    return mn;
}
/*double expon(double x){
    double SUM = 0;
    double k = 0;
    while (abs(SUM) >= delta_u){
        double summand = (power(x,k)/factorial(k));
        SUM += summand;
        k += 1.0;
    }
    return SUM;
}*/
double expon(double x){
    double sum = 0;
    int k = 0;
    double tempsum;
    double summand;
    do {
        summand = power(x,k)/factorial(k);
        k += 1;
        tempsum = sum;
        sum += summand;
    } while (abs(tempsum-sum) > delta_u);
    return sum;
}
double cosinus(double x){
    double SUM = 0;
    int k = 0;
    double tempsum;
    double summand;
    do {
        summand = power(-1, k) * (power(x,2*k) / factorial(2*k));
        k += 1;
        tempsum = SUM;
        SUM += summand;
    } while (abs(tempsum-SUM) > delta_v);
    return SUM;
}
double line(double x){
    return 1 + x;
}
double squareroot(double x){
    double new_num = x;
    double prev_num = 0;
    do {
        prev_num = new_num;
        new_num = (prev_num + x / prev_num) / 2.0;
    } while (abs(new_num-prev_num) > delta_psi);
    return new_num;
}
double zx(double x){
    return((cosinus(squareroot(1+x)))*expon(line));
}
double ideal_zx(double x){
    return(exp(1+x)*cos(sqrt(1+x)));
}
int main(){
    //cout<<fixed<<setprecision(12)<<sqrt(2)<<endl<<fixed<<setprecision(12)<<squareroot(2);
    // x = 0.01(0.005)0.06
    cout<<"|x____|phi(x)________|delta(phi)___________|ideal(phi)________|ideal_delta(phi)____________|psi(x)________|delta(psi)___________|ideal(psi)________|ideal_delta(psi)____________|u(x)________|delta(u)_________|ideal(u)________|ideal_delta(u)________|v(x)________|delta(v)________|ideal(v)________|ideal_delta(v)________|z(x)________|delta(z)________|ideal(z)________|ideal_delta(z)"<<endl;
    for (double x = 0.01; x <= 0.06; x += 0.005) {
        double mycos = cos(1)
        double stlsin =
        double mysqrt =
        double stlsqrt =

    }
}
