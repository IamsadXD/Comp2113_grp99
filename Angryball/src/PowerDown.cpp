#include "../include/PowerDown.h"
#include <iostream>
#include <cstdlib> // For rand() and RAND_MAX

PowerDown::PowerDown(Type type) : type(type), lastEffect("None") {}

void PowerDown::applyPowerDown(double &speed, int &barLength)
{
    int randomEffect = rand() % 2; // Randomly choose an effect (0 or 1)

    switch (randomEffect)
    {
    case 0:
        {
            if (speed < 5000){
                break;
            }
            double min = 1.25;
            double max = 1.75;
            speed = speed / (min + (max - min) * (static_cast<double>(rand()) / RAND_MAX)); // Increasing speed from 1.25 times to 1.75 times
            lastEffect = "Extreme Speeds";
            break;
        }
    case 1:
        barLength = barLength - (1 + rand() % 5); // Randomly decrease bar length from 1 to 5
        lastEffect = "Shorter Power Bar";
        break;
    }
}

std::string PowerDown::getPowerDown() const
{
    return lastEffect;
}