#include "Student.h"
#include <iostream>
#include <iomanip>
#include <numeric>

// 静态成员变量初始化
int Student::studentCount = 0;

// 默认构造函数
Student::Student() : name("未知"), age(0) {
    studentCount++;
    std::cout << "创建了一个学生对象（默认构造）" << std::endl;
}

// 参数化构造函数
Student::Student(const std::string& name, int age) : name(name), age(age) {
    studentCount++;
    std::cout << "创建了学生对象: " << name << std::endl;
}

// 析构函数
Student::~Student() {
    studentCount--;
    std::cout << "销毁了学生对象: " << name << std::endl;
}

// 获取姓名
std::string Student::getName() const {
    return name;
}

// 获取年龄
int Student::getAge() const {
    return age;
}

// 获取成绩列表
std::vector<double> Student::getGrades() const {
    return grades;
}

// 设置姓名
void Student::setName(const std::string& name) {
    this->name = name;
}

// 设置年龄
void Student::setAge(int age) {
    if (age >= 0 && age <= 150) {
        this->age = age;
    } else {
        std::cout << "年龄输入无效！" << std::endl;
    }
}

// 添加成绩
void Student::addGrade(double grade) {
    if (grade >= 0.0 && grade <= 100.0) {
        grades.push_back(grade);
        std::cout << "为 " << name << " 添加了成绩: " << grade << std::endl;
    } else {
        std::cout << "成绩输入无效！应在0-100之间。" << std::endl;
    }
}

// 计算平均成绩
double Student::getAverageGrade() const {
    if (grades.empty()) {
        return 0.0;
    }
    
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

// 显示学生信息
void Student::displayInfo() const {
    std::cout << "\n=== 学生信息 ===" << std::endl;
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << " 岁" << std::endl;
    
    if (!grades.empty()) {
        std::cout << "成绩: ";
        for (size_t i = 0; i < grades.size(); ++i) {
            std::cout << std::fixed << std::setprecision(1) << grades[i];
            if (i < grades.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << "平均成绩: " << std::fixed << std::setprecision(2) 
                  << getAverageGrade() << std::endl;
    } else {
        std::cout << "暂无成绩记录" << std::endl;
    }
    std::cout << "=================" << std::endl;
}

// 获取学生总数（静态方法）
int Student::getStudentCount() {
    return studentCount;
} 