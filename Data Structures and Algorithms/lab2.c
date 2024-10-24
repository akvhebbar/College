/*Problem Statement:
You are tasked with simulating the behavior of particles in a 2D space using C programming. Each particle is
represented by its position (`x` and `y` coordinates as floats) and velocity (`vx` and `vy` components as floats).
Your goal is to write a program that does the following:
1. Define a structure named `Particle` with attributes for position and velocity components.
2. Declare an array of `Particle` structures to store information for a maximum of 4 particles.
3. Populate the array with sample data for 3 particles, including their positions and velocities.
4. Write a function `updateParticle` that takes a pointer to a `Particle` structure as its argument and updates the
particle's position based on its velocity. You can assume a constant time step for simplicity.
5. Write a function `printParticle` that takes a pointer to a `Particle` structure as its argument and displays the
particle's position and velocity in a formatted manner.
6. In the `main` function, simulate the movement of particles by repeatedly calling the `updateParticle` function
for each particle and then calling the `printParticle` function to display their updated information.
Provide the C code to implement the above scenario.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Particle
{
    float x, y;   // Position
    float vx, vy; // Velocity
};
void updateParticle(struct Particle *particle)
{
    particle->x += particle->vx;
    particle->y += particle->vy;
}
void printParticle(struct Particle *particle)
{
    printf("Position: (%.2f, %.2f)\n", particle->x, particle->y);
    printf("Velocity: (%.2f, %.2f)\n\n", particle->vx, particle->vy);
}
int main()
{
    // Seed the random number generator
    srand(time(NULL));
    struct Particle particles[4];
    // Generate random particles
    for (int i = 0; i < 3; i++)
    {
        particles[i].x = (float)(rand() % 100) / 10.0;      // Random position between 0 and 10
        particles[i].y = (float)(rand() % 100) / 10.0;      // Random position between 0 and 10
        particles[i].vx = (float)(rand() % 21 - 10) / 10.0; // Random velocity between -1 and 1
        particles[i].vy = (float)(rand() % 21 - 10) / 10.0; // Random velocity between -1 and 1
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Particle %d:\n", i + 1);
        printParticle(&particles[i]);
        for (int step = 1; step <= 5; step++)
        {
            updateParticle(&particles[i]);
            printf("After Step %d:\n", step);
            printParticle(&particles[i]);
        }
    }
    return 0;
}