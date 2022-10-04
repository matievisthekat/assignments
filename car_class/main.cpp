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

    void accelerate() {
      speed += 10;
    }

    void brake() {
      speed -= 10;
    }
};

int main() {
  Car myCar = { 2006, "ryder" };

  cout << "accelerating..." << endl;
  for (int i = 0; i < 5; i++) {
    myCar.accelerate();
    cout << "speed: " << myCar.getSpeed() << endl;
  }

  cout << endl;

  cout << "braking..." << endl;
  for (int i = 0; i < 5; i++) {
    myCar.brake();
    cout << "speed: " << myCar.getSpeed() << endl;
  }

  return 0;
}