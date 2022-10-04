#include <iostream>
#include <string>
using namespace std;

class Car {
  private:
    int yearModel;
    string make;
    int speed;

  public:

    Car(int yearModel, string make) {
      Car::yearModel = yearModel;
      Car::make = make;
    }

    int getSpeed() {
      return speed;
    }

    int getYearModel() {
      return yearModel;
    }

    string getMake() {
      return make;
    }

    // increase speed by 10
    void accelerate() {
      speed += 10;
    }

    // decrease speed by 10
    void brake() {
      speed -= 10;
    }
};

int main() {
  Car myCar = { 2006, "ryder" };

  // call Car.accelerate() 5 times and print the speed after each call
  cout << "accelerating..." << endl;
  for (int i = 0; i < 5; i++) {
    myCar.accelerate();
    cout << "speed: " << myCar.getSpeed() << endl;
  }

  // just for formatting
  cout << endl;

  // call Car.brake() 5 times and print the speed after each call
  cout << "braking..." << endl;
  for (int i = 0; i < 5; i++) {
    myCar.brake();
    cout << "speed: " << myCar.getSpeed() << endl;
  }

  return 0;
}