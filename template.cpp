#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<class T> // Template header
T median(vector<T> v) {
    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main() {
    try {
        // 测试整数向量
        cout << "=== 整数向量测试 ===" << endl;
        vector<int> int_vec = {5, 2, 8, 1, 9, 3};
        cout << "原始向量: ";
        for (int x : int_vec) {
            cout << x << " ";
        }
        cout << endl;
        cout << "中位数: " << median(int_vec) << endl << endl;

        // 测试浮点数向量
        cout << "=== 浮点数向量测试 ===" << endl;
        vector<double> double_vec = {3.5, 1.2, 4.8, 2.1, 5.9};
        cout << "原始向量: ";
        for (double x : double_vec) {
            cout << x << " ";
        }
        cout << endl;
        cout << "中位数: " << median(double_vec) << endl << endl;

        // 测试偶数个元素的向量
        cout << "=== 偶数个元素测试 ===" << endl;
        vector<int> even_vec = {10, 20, 30, 40};
        cout << "原始向量: ";
        for (int x : even_vec) {
            cout << x << " ";
        }
        cout << endl;
        cout << "中位数: " << median(even_vec) << endl << endl;

        // 测试单个元素的向量
        cout << "=== 单个元素测试 ===" << endl;
        vector<int> single_vec = {42};
        cout << "原始向量: " << single_vec[0] << endl;
        cout << "中位数: " << median(single_vec) << endl << endl;

        // 测试空向量（会抛出异常）
        cout << "=== 空向量测试 ===" << endl;
        vector<int> empty_vec;
        cout << "测试空向量..." << endl;
        cout << "中位数: " << median(empty_vec) << endl;

    } catch (const domain_error& e) {
        cout << "捕获异常: " << e.what() << endl;
    }

    return 0;
}
