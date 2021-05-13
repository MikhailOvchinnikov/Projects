
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <boost/align.hpp>

class Ork;

class Knight
{
private:
    std::string name = "Vladimir";
    int health;
    int strength = 150;
public:
    Knight(int health) : health(health)
    {
        std::cout << "Knight got " << health << " health" << std::endl;
    }

    void strike(Ork& enemy);
    void set_health(int g_damage);

    int get_health()
    {
        return health;
    }
};

class Ork
{
private:
    std::string name = "Rudaman";
    int health;
    int strength = 120;
public:
    Ork(int health) : health(health)
    {
        std::cout << "Ork got " << health << " health" << std::endl;
    }

    void strike(Knight& enemy);
    void set_health(int g_damage);

    int get_health()
    {
        return health;
    }
};

void Knight::strike(Ork& enemy)
{
    int h = enemy.get_health();
    int damage = strength + rand() % strength * 0.25 - rand() % strength * 0.5;
    enemy.set_health(damage);
}
void Ork::strike(Knight& enemy)
{
    int h = enemy.get_health();
    int damage = strength + rand() % strength * 0.25 - rand() % strength * 0.5;
    enemy.set_health(damage);
}
void Ork::set_health(int g_damage)
{
    health = health - g_damage;
    if (health < 0)
    {
        health = 0;
        std::cout << "Knight WON!" << std::endl;
    }
}
void Knight::set_health(int g_damage)
{
    health = health - g_damage;
    if (health < 0)
    {
        health = 0;
        std::cout << "Ork WON!" << std::endl;
    }
}


int main()
{
    std::string command;
    srand(time(NULL));
    Knight knight(300);
    Ork ork(400);

    while ((knight.get_health() != 0) && (ork.get_health() != 0))
    {
        std::cout << "Who strikes? \"Ork\" or \"Knight\" else write \"end\"" << std::endl;
        std::cin >> command;


        if (command == "end")
        {
            std::cout << "THE END, HEROES SURVIVED!" << std::endl;
            break;
        }
 
        if (command == "Ork")
        {
            ork.strike(knight);
        }
        else if (command == "Knight")
        {
            knight.strike(ork);
        }
        else
        {
            std::cout << "wrong command" << std::endl;
        }

        std::cout << "Health of Knight: " << knight.get_health() << std::endl;
        std::cout << "Health of Ork: " << ork.get_health() << std::endl;

    }
}

