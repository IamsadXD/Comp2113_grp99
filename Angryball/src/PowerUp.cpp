#include "../include/PowerUp.h"
#include <iostream>
#include <cstdlib> 

PowerUp::PowerUp(Type type) : type(type), lastEffect("None") {}

void PowerUp::applyPowerUp(int &lives, int &barLength, bool &reset)
{
    int randomEffect = rand() % 2; // Randomly choose an effect (0, or 1)

    switch (randomEffect)
    {
    case 0:
        if (lives == 3){
            break;
        }
        lives += 1; // Increase lives by 1
        lastEffect = "Regen Lives";
        break;
    case 2:
        if (barLength > 60){
            break;
        }
        barLength += 1 + rand() % 5; // Randomly increase bar length from 1 to 5
        lastEffect = "Longer Power Bar";
        break;
    }
}

std::string PowerUp::getPowerUp() const
{
    return lastEffect;
}
