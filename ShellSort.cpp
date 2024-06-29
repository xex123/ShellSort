#include <iostream>
#include <vector>
#include <locale>

void ShellSort(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");

    std::cout << "Введите элементы массива (нажмите Enter когда закончите):\n";

    int element;
    while (true) {
        if (std::cin >> element) {
            data.push_back(element);
        }
        else {
            std::cin.clear();
            std::cin.ignore();
        }
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
            break;
        }
    }

    int size = data.size();
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int temp = data[i];
            int j;
            for (j = i; j >= interval && data[j - interval] > temp; j -= interval) {
                data[j] = data[j - interval];
            }
            data[j] = temp;
        }
    }

    std::cout << "\nОтсортированный массив:\n";

    for (int& num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    data.clear();

    int choice = 0;
    while (choice != 1) {
        std::cout << "\n1.Выход в меню\n";
        std::cout << "\nВведите свой выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Некорректный выбор. Пожалуйста, введите цифру 1 для выхода в меню.\n\n";
            break;
        }
    }
}

void Menu(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");
    int choice = 0;
    while (choice != 4) {
        std::cout << "Меню:\n";
        std::cout << "\n1.Ввод элементов массива вручную\n";
        std::cout << "2.Произвольный массив\n";
        std::cout << "3.Элементы массива из файла\n";
        std::cout << "4.Выход\n";
        std::cout << "\nВведите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            ShellSort(data);
        case 2:
            system("cls");
            //ShellSortRand(data);
            //case 3:
                //system("cls");
        case 4:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Некорректный выбор. Пожалуйста, введите цифру от 1 до 4 для выбора.\n\n";
            break;
        }
    }
}

int main() {
    std::vector<int> data;

    Menu(data);

    return 0;
}