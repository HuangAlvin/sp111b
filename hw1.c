#include <stdio.h>

// 函數 f(x)
double f(double x) {
    return x * x; // 這是一個簡單的函數，你可以更改為你要積分的函數
}

// 數值積分函數
double integrate(double a, double b, int n) {
    double h = (b - a) / n; // 區間寬度
    double sum = 0.0; // 積分結果的總和
    
    // 梯形法則
    for (int i = 1; i <= n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    sum += (f(a) + f(b)) / 2.0; // 加上首尾兩點的值
    sum *= h; // 乘以區間寬度
    
    return sum;
}

int main() {
    double a = 0.0; // 積分下界
    double b = 1.0; // 積分上界
    int n = 1000; // 區間劃分的數量
    
    double result = integrate(a, b, n); // 呼叫積分函數
    
    printf("積分結果: %lf\n", result);
    
    return 0;
}
