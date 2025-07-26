#ifndef MATHUTILS_H
#define MATHUTILS_H

namespace MathUtils {
    // 基本数学运算
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // 高级数学函数
    double power(double base, double exponent);
    double factorial(int n);
    bool isPrime(int n);
    
    // 常量
    extern const double PI;
    extern const double E;
}

#endif // MATHUTILS_H 