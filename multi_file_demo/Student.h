#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int age;
    std::vector<double> grades;

public:
    // 构造函数
    Student();
    Student(const std::string& name, int age);
    
    // 析构函数
    ~Student();
    
    // 访问器方法（getter）
    std::string getName() const;
    int getAge() const;
    std::vector<double> getGrades() const;
    
    // 修改器方法（setter）
    void setName(const std::string& name);
    void setAge(int age);
    
    // 功能方法
    void addGrade(double grade);
    double getAverageGrade() const;
    void displayInfo() const;
    
    // 静态方法
    static int getStudentCount();
    
private:
    static int studentCount;
};

#endif // STUDENT_H 