#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <list>
#include <format>
#include <chrono>
#include <thread>

struct Point {
    int x, y;
};

class Person {
public:
    std::string Name;
    std::string Race;
    int Age;
    Point Place;
    float Strength; // 0.5 - 1.5 (multiplier)
    float Damage;
    float Health;

    Person (std::string name, std::string race, int age, Point place, float strength, float damage, float health) {
        Name = name;
        Race = race;
        Age = age;
        Place = place;
        Strength= strength;
        Damage = damage;
        Health = health;
    }

    Person () {}

    std::string getInfo () {
        return "Name: " + Name + ", Race: " + Race + ", Age: " + std::to_string(Age) + ", Map(x):" + std::to_string(Place.x) + 
        ", Map(y): " + std::to_string(Place.y) + ", Strength: " + std::to_string(Strength) + ", Damage: " + std::to_string(Damage) + ", Health: " + std::to_string(Health);
    }
};

Person createPerson() {
    Person person;
    std::cout << "Person Name: ";
    std::cin >> person.Name; 
    std::cout << "Person Race: ";
    std::cin >> person.Race; 
    std::cout << "Person Age: ";
    std::cin >> person.Age;
    Point point;
    std::cout << "Person x coord: ";
    std::cin >> point.x;
    std::cout << "Person y coord: ";
    std::cin >> point.y;
    person.Place = point;
    std::cout << "Person Strength: ";
    std::cin >> person.Strength;
    std::cout << "Person Damage: ";
    std::cin >> person.Damage;
    std::cout << "Person Health: ";
    std::cin >> person.Health;
    return person;
}

int main() {
    std::list<Person> persons;
    std::string main_posibilities = "1 - Create person\n9 - Finish program\nEnter your choice: ";
    bool flag = true;

    while (flag) {
        system("cls");
        for (Person pers: persons){
            std::cout << pers.Name + ", ";
        }
        std::cout << std::endl;
        std::cout << main_posibilities;
        int answer;
        try {
            std::cin >> answer;
            switch (answer)
            {
                case 1:
                    persons.push_back(createPerson());
                    break;

                case 9:
                    flag = false;
                    break;
                
                default:
                    break;
            }
        } catch (const char* error_message)
        {
            std::cout << error_message << std::endl;
            std::chrono::milliseconds timespan(3000); // or whatever
            std::this_thread::sleep_for(timespan);
        }
        
    }

    
    return 0;
}