#include "PowerDown.h"
#include <iostream>

PowerDown::PowerDown(Type type) : type(type) {}

void PowerDown::applyEffect()
{
    switch (type)
    {
    case Type::ExtremeSpeeds:
        // Logic to increase ball speed dramatically
        break;
    case Type::ShorterPowerBar:
        // Logic to decrease the length of the power bar
        break;
    case Type::DecreaseBallSize:
        // Logic to reduce the ball size
        break;
    case Type::ReduceLives:
        // Logic to decrease player's lives
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
    case Type::DecreaseBallSize:
        return "Decrease Ball Size";
    case Type::ReduceLives:
        return "Reduce Lives";
    default:
        return "Unknown Power-Down";
    }
}
