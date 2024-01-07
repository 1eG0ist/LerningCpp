#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <list>
#include <format>
#include <chrono>
#include <thread>

/* func template */

template <typename T>
void print_arr(T* arr, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

/* class template */

template <class T>
class Arrays {
private:
    int len;
    T* arr;
public:
    Arrays(T* a, int len) {
        this->len = len;
        arr = new T[len];
        for(int i = 0; i < len; i++) *(arr + i) = *(a + i);
    }

    void print_arr() {
        for (int i = 0; i < this->len; i++) {
            std::cout << *(this->arr + i) << " ";
        }
        std::cout << std::endl;
    }

    ~Arrays() {
        delete[] arr;
    }
};

int main() {
    
    int arr1[] = {1, 4, 2, 5, 78, 3, 6, 2, 4};
    print_arr<int>(arr1, 9);

    float arr2[] = {5.34f, 6.234f, 1.2341f};
    print_arr<float>(arr2, 3);

    /* ~~~~~~~~~~~ */

    Arrays<int> obj1(arr1, 9);
    obj1.print_arr();

    Arrays<float> obj2(arr2, 3);
    obj2.print_arr();

    return 0;
}