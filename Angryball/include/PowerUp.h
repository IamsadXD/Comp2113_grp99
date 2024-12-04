#ifndef POWERUP_H
#define POWERUP_H

#include <string>

class PowerUp
{
public:
    enum class Type
    {
        ControlledMovement,
        RegenLives,
        LongerPowerBar
    };

    PowerUp(Type type);
    void applyEffect(int &lives, int& barLength);
    std::string getName() const;

private:
    Type type;
};

#endif // POWERUP_H