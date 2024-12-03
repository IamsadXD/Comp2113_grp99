#include "PowerUp.h"
#include <iostream>

PowerUp::PowerUp(Type type) : type(type) {}

void PowerUp::applyEffect()
{
    switch (type)
    {
    case Type::IncreaseBallSize:
        // Logic to increase the ball size
        break;
    case Type::ControlledMovement:
        // Logic to allow controlled movement of the ball
        break;
    case Type::ExtraLives:
        // Logic to increase the player's lives
        break;
    case Type::LongerPowerBar:
        // Logic to increase the length of the power bar
        break;
    }
}

std::string PowerUp::getName() const
{
    switch (type)
    {
    case Type::IncreaseBallSize:
        return "Increase Ball Size";
    case Type::ControlledMovement:
        return "Controlled Movement";
    case Type::ExtraLives:
        return "Extra Lives";
    case Type::LongerPowerBar:
        return "Longer Power Bar";
    default:
        return "Unknown Power-Up";
    }
}
