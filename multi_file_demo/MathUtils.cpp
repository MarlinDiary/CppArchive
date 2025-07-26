#include "MathUtils.h"
#include <cmath>
#include <stdexcept>

namespace MathUtils {
    // 常量定义
    const double PI = 3.14159265358979323846;
    const double E = 2.71828182845904523536;
    
    // 基本数学运算实现
    double add(double a, double b) {
        return a + b;
    }
    
    double subtract(double a, double b) {
        return a - b;
    }
    
    double multiply(double a, double b) {
        return a * b;
    }
    
    double divide(double a, double b) {
        if (b == 0) {
            throw std::runtime_error("除数不能为零！");
        }
        return a / b;
    }
    
    // 高级数学函数实现
    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }
    
    double factorial(int n) {
        if (n < 0) {
            throw std::invalid_argument("阶乘的参数不能为负数！");
        }
        if (n == 0 || n == 1) {
            return 1.0;
        }
        
        double result = 1.0;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
} 