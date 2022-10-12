#include <iostream>
#include <functional>

class FuelGauge {
  int fuelInGallons = 0;

  public:

  int getCurrentFuelAmount() {
    return fuelInGallons;
  }

  void fillUp() {
    if (fuelInGallons == 15) return;

    fuelInGallons += 1;
  }

  void burn() {
    if (fuelInGallons == 0) return;

    fuelInGallons -= 1;
  }
};

class Odometer {
  int mileage = 0;
  int lastFuelUpdateAtMileage = 0;

  public:

  int getCurrentMileage() {
    return mileage;
  }

  void increment(const std::function<void()>& burn) {
    if (mileage == 999999) {
      mileage = 0;
    } else {
      mileage += 1;
    }

    if (mileagePlus24(lastFuelUpdateAtMileage) == mileage) {
      burn();
      lastFuelUpdateAtMileage = mileage;
    }
  }

  int mileagePlus24(int miles) {
    int result;

    if (miles + 24 > 999999) {
      result = miles + 24 - 999999;
    } else {
      result = miles + 24;
    }

    return result;
  }
};

int main() {
  FuelGauge fuel = FuelGauge();
  Odometer odo = Odometer();

  for (int i = 0; i <= 15; i++) {
    fuel.fillUp();
  }
  std::cout << fuel.getCurrentFuelAmount() << std::endl;

  while (fuel.getCurrentFuelAmount() != 0) {
    odo.increment([&fuel](){
      fuel.burn();
    });
    std::cout << "mileage: " << odo.getCurrentMileage() << std::endl
              << "fuel: " << fuel.getCurrentFuelAmount() << std::endl << std::endl;
  }
  
  return 0;
}
