#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <list>
#include <format>
#include <chrono>
#include <thread>

enum File_variants {
    open= 8 ,
    close,
    in_queue,
    deleted
};

struct File {
    float weight;
    std::string name;
    File_variants vars;
};

int main() {
    File my_file;
    my_file.weight = 1.9f;
    my_file.name = "test.txt";
    my_file.vars = File_variants::close;

    std::cout << my_file.vars; // 9, because open - 8, close - 9...
    
    return 0;
}