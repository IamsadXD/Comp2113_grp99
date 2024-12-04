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
    void applyPowerUp(int &lives, int& barLength, bool& reset);
    std::string getPowerUp() const;

private:
    Type type;
    std::string lastEffect; // Store the last applied effect
};

#endif // POWERUP_H