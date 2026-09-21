
// Вариант 61.
// Yaroslav Aksenov,ПИ-53.
#include <iostream>
#include <clocale>  
using namespace std;


double cToF(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

double fToC(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double cToK(double c) {
    return c + 273.15;
}

double kToC(double k) {
    return k - 273.15;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    double value;
    do {
        cout << "\n=== Вариант 61: конвертер температур ===\n";
        cout << "1. Цельсий -> Фаренгейт\n";
        cout << "2. Фаренгейт -> Цельсий\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите температуру в Цельсиях: ";
            cin >> value;
            cout << value << " °C = " << cToF(value) << " °F\n";
            break;
        case 2:
            cout << "Введите температуру в Фаренгейтах: ";
            cin >> value;
            cout << value << " °F = " << fToC(value) << " °C\n";
            break;
        case 3:
            cout << "Введите температуру в Цельсиях: ";
            cin >> value;
            cout << value << " °C = " << cToK(value) << " K\n";
            break;
        case 4:
            cout << "Введите температуру в Кельвинах: ";
            cin >> value;
            if (value < 0) {
                cout << "Ошибка: температура не может быть ниже 0 K\n";
            }
            else {
                cout << value << " K = " << kToC(value) << " °C\n";
            }
            break;
        case 0:
            cout << "Работа завершена.\n";
            break;
        default:
            cout << "Такого пункта нет.\n";
        }
    } while (choice != 0);

    return 0;
}





