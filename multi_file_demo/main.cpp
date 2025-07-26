#include <iostream>
#include <vector>
#include <memory>
#include "Student.h"
#include "MathUtils.h"

void demonstrateStudentClass() {
    std::cout << "\n========== 学生类演示 ==========" << std::endl;
    
    // 创建学生对象
    Student student1("张三", 20);
    Student student2("李四", 19);
    
    // 添加成绩
    student1.addGrade(85.5);
    student1.addGrade(92.0);
    student1.addGrade(78.5);
    
    student2.addGrade(88.0);
    student2.addGrade(95.5);
    
    // 显示学生信息
    student1.displayInfo();
    student2.displayInfo();
    
    // 显示学生总数
    std::cout << "\n当前学生总数: " << Student::getStudentCount() << std::endl;
}

void demonstrateMathUtils() {
    std::cout << "\n========== 数学工具演示 ==========" << std::endl;
    
    // 基本运算
    double a = 10.5, b = 3.2;
    std::cout << "基本运算演示:" << std::endl;
    std::cout << a << " + " << b << " = " << MathUtils::add(a, b) << std::endl;
    std::cout << a << " - " << b << " = " << MathUtils::subtract(a, b) << std::endl;
    std::cout << a << " * " << b << " = " << MathUtils::multiply(a, b) << std::endl;
    std::cout << a << " / " << b << " = " << MathUtils::divide(a, b) << std::endl;
    
    // 高级函数
    std::cout << "\n高级函数演示:" << std::endl;
    std::cout << "2 的 8 次方 = " << MathUtils::power(2, 8) << std::endl;
    std::cout << "5! = " << MathUtils::factorial(5) << std::endl;
    
    // 质数检测
    std::cout << "\n质数检测:" << std::endl;
    for (int i = 10; i <= 20; ++i) {
        std::cout << i << (MathUtils::isPrime(i) ? " 是质数" : " 不是质数") << std::endl;
    }
    
    // 常量使用
    std::cout << "\n数学常量:" << std::endl;
    std::cout << "π = " << MathUtils::PI << std::endl;
    std::cout << "e = " << MathUtils::E << std::endl;
    
    // 异常处理演示
    std::cout << "\n异常处理演示:" << std::endl;
    try {
        MathUtils::divide(10, 0);
    } catch (const std::runtime_error& e) {
        std::cout << "捕获异常: " << e.what() << std::endl;
    }
    
    try {
        MathUtils::factorial(-5);
    } catch (const std::invalid_argument& e) {
        std::cout << "捕获异常: " << e.what() << std::endl;
    }
}

void demonstrateSmartPointers() {
    std::cout << "\n========== 智能指针演示 ==========" << std::endl;
    
    // 使用智能指针管理学生对象
    std::vector<std::unique_ptr<Student>> students;
    
    students.push_back(std::make_unique<Student>("王五", 21));
    students.push_back(std::make_unique<Student>("赵六", 22));
    
    // 为学生添加成绩
    students[0]->addGrade(90.0);
    students[0]->addGrade(87.5);
    
    students[1]->addGrade(93.0);
    students[1]->addGrade(89.5);
    
    // 显示所有学生信息
    std::cout << "\n使用智能指针管理的学生信息:" << std::endl;
    for (const auto& student : students) {
        student->displayInfo();
    }
    
    std::cout << "\n当前学生总数: " << Student::getStudentCount() << std::endl;
}

int main() {
    std::cout << "==================================" << std::endl;
    std::cout << "    C++ 多文件协同开发演示程序    " << std::endl;
    std::cout << "==================================" << std::endl;
    
    // 演示学生类
    demonstrateStudentClass();
    
    // 演示数学工具
    demonstrateMathUtils();
    
    // 演示智能指针
    demonstrateSmartPointers();
    
    std::cout << "\n========== 程序结束 ==========" << std::endl;
    std::cout << "最终学生总数: " << Student::getStudentCount() << std::endl;
    
    return 0;
} 