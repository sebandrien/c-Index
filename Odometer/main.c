#include <stdio.h>

void drive(double *odomPtr, double *fuelPtr, double mpg, double distance) {
    if (*fuelPtr * mpg < distance) {
        *odomPtr += (*fuelPtr) * mpg;
        *fuelPtr = 0;
    } else {
        *odomPtr += distance;
        *fuelPtr -= (distance / mpg);
    }
}

int main() {
    double odometer, fuelGauge, mpg, distance;

    printf("Enter odometer reading, fuel gauge reading, and mpg: ");
    scanf("%lf %lf %lf", &odometer, &fuelGauge, &mpg);

    while (1) {
        printf("Enter the distance you want to drive: ");
        scanf("%lf", &distance);

        drive(&odometer, &fuelGauge, mpg, distance);

        printf("Current reading odometer = %.2f, fuel = %.2f\n", odometer, fuelGauge);

        if (fuelGauge == 0) {
            printf("No more fuel!\n"); 
            break;
        }
    }
    return 0;
}
