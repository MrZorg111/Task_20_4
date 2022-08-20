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
void addition(int a[]) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000; i++) {

        switch (rand() % 5) {
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
    }
}
int main() {
    int arr[1000];
    char command;

    std::ofstream bank("P:\\bank.txt");
    std::cout << "Enter the working command: Withdrawal or replenishment (-/+)";
    std::cin >> command;
    if (command == '+') {
        addition(arr);
    }
    else {
        int sum;
        std::cout << "Enter the desired withdrawal amount:";
        std::cin >> sum;
        if (sum % 100 != 0) {
            std::cout << "This operation is not possible, enter a multiple of 100.";
        }
        else {

        }
    }

}
