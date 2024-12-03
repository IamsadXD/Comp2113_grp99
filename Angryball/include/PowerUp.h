#ifndef POWERUP_H
#define POWERUP_H

#include <string>

class PowerUp
{
public:
    enum class Type
    {
        IncreaseBallSize,
        ControlledMovement,
        ExtraLives,
        LongerPowerBar
    };

    PowerUp(Type type);
    void applyEffect();
    std::string getName() const;

private:
    Type type;
};

#endif // POWERUP_H
