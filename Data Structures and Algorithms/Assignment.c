#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double toRadians(double degree)
{
    return degree * (PI / 180.0);
}

double toDegrees(double radian)
{
    return radian * (180.0 / PI);
}

int main()
{
    int N;
    scanf("%d", &N);

    if (N < 2 || N > 1000)
    {
        printf("Invalid number of mediums\n");
        return 1;
    }

    double *refractive_indices = (double *)malloc(N * sizeof(double));
    if (refractive_indices == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &refractive_indices[i]);

        if (refractive_indices[i] < 1.0 || refractive_indices[i] > 2.5)
        {
            printf("Invalid refractive index\n");
            free(refractive_indices);
            return 1;
        }
    }

    double theta1;
    scanf("%lf", &theta1);

    if (theta1 < 0 || theta1 >= 90)
    {
        printf("Invalid angle of incidence\n");
        free(refractive_indices);
        return 1;
    }

    double theta_incident = toRadians(theta1);

    for (int i = 0; i < N - 1; i++)
    {
        double n1 = refractive_indices[i];
        double n2 = refractive_indices[i + 1];

        double sin_theta2 = (n1 * sin(theta_incident)) / n2;

        if (sin_theta2 >= 1.0)
        {
            printf("Layer %d to Layer %d:Total internal reflection occurs\n", i + 1, i + 2);
            free(refractive_indices);
            return 0;
        }

        // Calculate the angle of refraction in radians
        double theta2 = asin(sin_theta2);

        // Print the angle of refraction in degrees
        printf("Layer %d to Layer %d:Angle of refraction:%.2f degrees\n", i + 1, i + 2, toDegrees(theta2));

        // Update the incident angle for the next boundary
        theta_incident = theta2;
    }

    // Free the allocated memory
    free(refractive_indices);

    return 0;
}