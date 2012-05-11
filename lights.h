#ifndef LIGHTS_H
#define LIGHTS_H

class lights
{
public:
    lights();

    float pos[];
    float diffuse[];
    float mat[];
    float shin[];
    int active;
};

#endif // LIGHTS_H
