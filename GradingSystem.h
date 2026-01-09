#ifndef GRADINGSYSTEM_H
#define GRADINGSYSTEM_H

class GradingSystem
{
public:
    static float assignMarks(float similarity)
    {
        if (similarity > 60)
            return 50;
        return 80;
    }
};

#endif