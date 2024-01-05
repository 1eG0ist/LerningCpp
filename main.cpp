#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

void print(std::string var) {
    std::cout << var << std::endl;
}

int main() {
    //cstring area

    std::string str1 = "Hi";
    std::string str2 = "user";

    str1.append(str2); // str1 + str2
    print(str1);

    str1.pop_back();
    print(str1); // Hiuse

    str1.push_back('!');
    print(str1); // Hiuse!

    str1.resize(3);
    print(str1); // Hiu

    // math area
    std::cout << pow(2,3) << std::endl; // 8

    std::cout << abs(-10) << std::endl; // 10

    /*
        sin
        cos
        sqrt
        ceil - from 1.01 to 2
        floor - from 1.98 to 1
        round - from 1.42 to 1, from 1.63 to 2
    */


    
    return 0;
}