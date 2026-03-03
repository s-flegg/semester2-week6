#include <stdio.h>
#include <stdlib.h>

int get_speed_limit() {
  char input[20];
  int speed_limit;

  // Get user input for speed limit
  printf("Enter the speed limit: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &speed_limit);
  }
  return speed_limit;
}

int get_drivers_speed() {
  char input[20];
  int driver_speed;

  // Get user input for driver's speed
  printf("Enter the driver's speed: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &driver_speed);
  }
  return driver_speed;
}

void fine (speed_limit, driver_speed) {
  int fine = 0;

  // Determine if the driver is speeding
  if (driver_speed > speed_limit) {
    int excess_speed = driver_speed - speed_limit;

    // Calculate fine based on how much over the limit
    if (excess_speed <= 10) {
      fine = 50;
    } else if (excess_speed <= 20) {
      fine = 100;
    } else {
      fine = 200;
    }

    printf("Fine: $%d\n", fine);
  } else {
    printf("No fine needed.\n");
  }
}

int main() {
  int limit = get_speed_limit();
  int driver = get_drivers_speed();
  fine(limit, driver);
  return 0;
}