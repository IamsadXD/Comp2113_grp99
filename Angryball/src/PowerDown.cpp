#include "../include/PowerDown.h"
#include <iostream>
#include <cstdlib> // For rand() and RAND_MAX

PowerDown::PowerDown(Type type) : type(type) {}

void PowerDown::applyEffect(int &speed, int& barLength)
{
    switch (type)
    {
    case Type::ExtremeSpeeds:
        {
            double min = 1.25;
            double max = 1.75;
            speed = speed * ( min + (max - min) * (static_cast<double>(rand()) / RAND_MAX)); // Random denominator from 1.25 to 1.75
            break;
        }
    case Type::ShorterPowerBar:
        barLength -= 1 + rand() % 5; // Decrease bar length from 1 to 5
        break;
    }
   
}

std::string PowerDown::getName() const
{
    switch (type)
    {
    case Type::ExtremeSpeeds:
        return "Extreme Speeds";
    case Type::ShorterPowerBar:
        return "Shorter Power Bar";
    default:
        return "Unknown Power-Down";
    }
}