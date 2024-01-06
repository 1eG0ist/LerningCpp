#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <list>
#include <format>
#include <chrono>
#include <thread>


/*Classic OOP in Cpp*/


class Building {
private:
    int year;
    std::string type;
public:
    Building(int year, std::string type) { // constructor
        this->year = year;
        this->type = type;
    }

    void get_info() {
        std::cout << "Type: " << type << ". Year: " << year << std::endl;
    }

    ~Building() { // destructor call when need to delete obj
        std::cout << "obj deleted" << std::endl;
    }

};


// Friendly functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class Car;
class Person;

class Person {
private:
    int age;
    std::string name;
public:
    Person(std::string name) {
        this->name = name;
    }

    friend void car_info(Car& car, Person& person);
};

class Car {
private:
    std::string name;
public:
    Car(std::string name) {
        this->name = name;
    }

    friend void car_info(Car& car, Person& person);
};

// discription of func which will be use like friend func in two other classes
void car_info(Car& car, Person& person) { 
    std::cout << "Person with name " << person.name << " have car " << car.name << std::endl;
}


// Friendly classes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class Owner;
class Dog {
private:
    int health = 100;
public:
    friend Owner;
};

class Owner {
public:
    void Damage(Dog& dog) {
        dog.health -= 20;
        std::cout << "Health of dog - " << dog.health << std::endl;
    }

    void Heal(Dog& dog) {
        dog.health += 10;
        std::cout << "Health of dog - " << dog.health << std::endl;
    }

    void Kill(Dog& dog) {
        dog.health = 0;
        std::cout << "Dog is dead" << std::endl;
    }
};


/* inheritance */


class PC {
protected:
    int diagonal;
    std::string os;
public:
    PC(int diag, std::string os) {
        this->diagonal = diag;
        this->os = os;
    }

    void get_info() {
        std::cout << "Diadgonal " << this->diagonal << std::endl << "os - " << os << std::endl;
    }
};

class LapTop: public PC {
private:
    float weight;
public:
    LapTop(int diag, std::string os, float weight): PC(diag, os) {
        this->diagonal = diag;
        this->os = os;
        this->weight = weight;
    }

    void get_info() {
        PC::get_info();
        std::cout << "Weight " << this->weight << std::endl;
    }
};


/* main section */


int main() {

    Building school(1994, "shkola");
    school.get_info();
   
    std::cout << std::endl;

    Car bmw("BMW");
    Person jhon("Jhon");
    car_info(bmw, jhon);

    std::cout << std::endl;

    Dog skuby;
    Owner alex;
    alex.Damage(skuby);
    alex.Damage(skuby);
    alex.Heal(skuby);
    alex.Heal(skuby);
    alex.Heal(skuby);
    alex.Kill(skuby);

    std::cout << std::endl;

    LapTop mac(16, "MAC", 1.9f);
    mac.get_info();
    
    return 0;
}