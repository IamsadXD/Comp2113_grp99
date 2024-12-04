#include "../include/PowerUp.h"
#include <iostream>

PowerUp::PowerUp(Type type) : type(type) {}

void PowerUp::applyEffect(int &lives, int &barLength)
{
    switch (type)
    {
    case Type::ControlledMovement:
        // Logic to allow controlled movement of the ball
        break;
    case Type::RegenLives:
        lives++; // Increase the number of lives
        break;
    case Type::LongerPowerBar:
        barLength += 1 + rand() % 5; // Increase bar length from 1 to 5
        break;
    }
}

std::string PowerUp::getName() const
{
    switch (type)
    {
    case Type::ControlledMovement:
        return "Controlled Movement";
    case Type::RegenLives:
        return "Extra Lives";
    case Type::LongerPowerBar:
        return "Longer Power Bar";
    default:
        return "Unknown Power-Up";
    }
}