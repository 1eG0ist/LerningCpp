#include <iostream>
#include <random>
#include <fstream>
#include <string>


int main() {

    // write something in txt file
    std::ofstream file_in("test.txt", std::ios_base::out);
    if(file_in.is_open()) {
        file_in << "hello world!!";
        file_in.close();
        std::cout << "you wrote the data to the file correctly" << std::endl;
    }


    // read something from txt file
    std::ifstream file_out("test.txt");
    if (file_out.is_open()) {
        char first_str[100];
        file_out.getline(first_str, 100);
        file_out.close();
        std::cout << first_str;
    }
    return 0;
}