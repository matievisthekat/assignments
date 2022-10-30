#include <string>
#include <iostream>

class Employee {
  std::string name;
  int number;
  std::string hire_date;

  public:
    Employee(std::string a, int b, std::string c) {
      name = a;
      number = b;
      hire_date = c;
    };

    std::string getName() {
      return name;
    }

    int getNumber() {
      return number;
    }

    std::string getHireDate() {
      return hire_date;
    }

    void setName(std::string new_name) {
      name = new_name;
    }

    void setNumber(int new_number) {
      number = new_number;
    }

    void setHireDate(std::string new_date) {
      hire_date = new_date;
    }
};

class ProductionWorker : public Employee {
  int shift; // 1 = day; 2 = night
  double hourly_pay;

  public:
    ProductionWorker(int a, double b, std::string name, int number, std::string hire_date): Employee(name, number, hire_date) {
      if (a > 2 || a < 1) {
        throw "Shift may only be 1 or 2";
        return;
      }
      shift = a;
      hourly_pay = b;
    };

    int getShift() {
      return shift;
    }

    double getHourlyPay() {
      return hourly_pay;
    }

    void setShift(int new_shift) {
      if (new_shift > 2 || new_shift < 1) {
        throw "Shift may only be 1 or 2";
        return;
      }

      shift = new_shift;
    }

    void setHourlyPay(double new_pay) {
      hourly_pay = new_pay;
    }
};

int main() {

  ProductionWorker prod = ProductionWorker(1, 14.56, "John Doe", 23332, "14/08/2021");

  std::cout << prod.getName() << " was hired on " << prod.getHireDate() << " and is paid $" << prod.getHourlyPay() << " per hour" << std::endl;

  prod.setHourlyPay(21.98);

  std::cout << prod.getName() << " is now paid $" << prod.getHourlyPay() << " per hour" << std::endl;

  return 0;
}
