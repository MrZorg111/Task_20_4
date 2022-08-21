#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
/*
 * 1)Создадим основной блок с запросом пользователя на команду "+" или "-".
 * 2)Создадим блок с пополнением банкомата.-------------
 * 3) Создадим блок с выдачей пользователю купюр.
 *
 * */
void addition(int a[], int b) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000; i++) {
        switch (rand() % 5 && a[i] == 0) {
            case 0:
                a[i] = 100;
                break;
            case 1:
                a[i] = 200;
                break;
            case 2:
                a[i] = 500;
                break;
            case 3:
                a[i] = 1000;
                break;
            case 4:
                a[i] = 5000;
                break;
        }
        b += i;
    }
    for (int s = 0; s < 1000; s++) {
        for (int r = 0; r < 999; r++) {
            if (a[r] < a[r + 1]) {
                int o = a[r];
                a[r] = a[r + 1];
                a[r + 1] = o;
            }
        }
    }
}
int main() {
    std::string yes_no;
    int arr[1000], count;
    char command;

    std::ofstream bank("P:\\bank.txt");
    do {
        std::cout << "Enter the working command: Withdrawal or replenishment (-/+)";
        std::cin >> command;
        if (command == '+') {
            addition(arr, count);
            std::cout << "The machine is filled with cash.\n";
        }
        else {
            int sum;
            std::cout << "Enter the desired withdrawal amount:";
            std::cin >> sum;
            if (sum % 100 != 0) {
                std::cout << "This operation is not possible, enter a multiple of 100.\n";
            }
            if (count == 0) {
                std::cout << "Cash withdrawal is not possible, there are no funds in the machine. Contact the bank.\n";
            } else {
                for (int i = 0; sum > 0; i++) {
                    if (sum != 0 && i == 999) {
                        std::cout << "There are not enough funds in the device.\n";
                        break;
                    }
                    if (sum > arr[i]) {
                        sum -= arr[i];
                        arr[i] = 0;
                    }

                }
                std::cout << "Good";
            }
        }
        std::cout << "Do you want to continue working: (yes/no)";
        std::cin >> yes_no;
    }while (yes_no == "yes");
}
/*
  for (int t = 0; t < 1000; t++) {
    std::cout << arr[t] << " ";
    if (t % 20 == 0 && t > 0) {
      std::cout << "\n";
      for (int i = 0; sum > 0; i++) {
                if (sum > arr[i]) {
                   sum -= arr[i];
                }
            }
            std::cout << "Good";
    }
    }
*/