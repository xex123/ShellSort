#include <iostream>
#include <vector>
#include <fstream>
#include <locale>
#include <Windows.h>

HANDLE hConsole;

void Sort(std::vector<int>& data) {
    int size = data.size();
    clock_t start = clock();
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
    clock_t stop = clock();
    double duration = double(stop - start) / CLOCKS_PER_SEC;
    SetConsoleTextAttribute(hConsole, 7);
    std::cout << "\nВремя сортировки массива состовляет: " << duration * 1000 << " миллисекунд\n";
}

void ExitToMenu() {
    int choice = 0;
    while (choice != 1) {
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "\n1.Выход в меню\n";
        SetConsoleTextAttribute(hConsole, 6);
        std::cout << "\nВведите свой выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            break;
        default:
            system("cls");
            SetConsoleTextAttribute(hConsole, 4);
            std::cout << "Некорректный выбор. Пожалуйста, введите цифру 1 для выхода в меню.\n\n";
            break;
        }
    }
}

void ShellSort(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");

    std::cout << "Введите элементы массива (нажмите Enter когда закончите):\n";
    SetConsoleTextAttribute(hConsole, 7);
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

    std::ofstream in("input.txt");
    for (int& num : data) {
        in << num << " ";
    }
    in.close();

    SetConsoleTextAttribute(hConsole, 2);
    std::cout << "\nИсходный массив записан в файл 'input.txt'\n";

    Sort(data);

    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "\nОтсортированный массив:\n";
    SetConsoleTextAttribute(hConsole, 7);
    std::ofstream out("output.txt");
    for (int& num : data) {
        std::cout << num << " ";
        out << num << " ";
    }
    std::cout << "\n";
    out.close();
    data.clear();

    SetConsoleTextAttribute(hConsole, 2);
    std::cout << "\nОтсортированный массив записан в файл 'output.txt'\n";

    ExitToMenu();
}

void ShellSortRand(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");
    int count, minVal, maxVal;

    std::cout << "Введите количество элементов случайного массива:\n";
    SetConsoleTextAttribute(hConsole, 7);
    std::cin >> count;
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Введите минимальное значение:\n";
    SetConsoleTextAttribute(hConsole, 7);
    std::cin >> minVal;
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Введите максимальное значение:\n";
    SetConsoleTextAttribute(hConsole, 7);
    std::cin >> maxVal;

    for (int i = 0; i < count; i++) {
        int randomNum = rand() % (maxVal - minVal + 1) + minVal;
        data.push_back(randomNum);
    }

    if (count > 100) {
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "\nИсходный массив записан в файл 'input.txt'";
        std::ofstream in("input.txt");
        for (int& num : data) {
            in << num << " ";
        }
        in.close();
    }
    else {
        SetConsoleTextAttribute(hConsole, 6);
        std::cout << "\nИсходный массив:\n";
        std::ofstream in("input.txt");
        SetConsoleTextAttribute(hConsole, 7);
        for (int& num : data) {
            std::cout << num << " ";
            in << num << " ";
        }
        std::cout << "\n";
        in.close();
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "\nИсходный массив записан в файл 'input.txt'\n";
    }

    Sort(data);

    if (count > 100) {
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "\nОтсортированный массив записан в файл 'output.txt'\n";
        std::ofstream out("output.txt");
        for (int& num : data) {
            out << num << " ";
        }
        out.close();
    }
    else {
        SetConsoleTextAttribute(hConsole, 6);
        std::cout << "\nОтсортированный массив:\n";
        std::ofstream out("output.txt");
        SetConsoleTextAttribute(hConsole, 7);
        for (int& num : data) {
            std::cout << num << " ";
            out << num << " ";
        }
        std::cout << "\n";
        out.close();
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "\nОтсортированный массив записан в файл 'output.txt'\n";
    }

    data.clear();

    ExitToMenu();
}

void ShellSortFromFile(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");

    SetConsoleTextAttribute(hConsole, 7);
    std::ifstream in("input.txt");
    int num;
    while (in >> num) {
        data.push_back(num);
    }
    in.close();
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Исходный массив из файла 'input.txt':\n";
    SetConsoleTextAttribute(hConsole, 7);
    for (int& num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    Sort(data);

    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "\nОтсортированный массив:\n";
    SetConsoleTextAttribute(hConsole, 7);
    std::ofstream out("output.txt");
    for (int& num : data) {
        std::cout << num << " ";
        out << num << " ";
    }
    std::cout << "\n";
    out.close();
    data.clear();

    SetConsoleTextAttribute(hConsole, 2);
    std::cout << "\nОтсортированный массив записан в файл 'output.txt'\n";

    ExitToMenu();
}

void Menu(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");
    int choice = 0;
    while (choice != 4) {
        SetConsoleTextAttribute(hConsole, 6);
        std::cout << "Меню:\n";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "\n1.Ввод элементов массива вручную\n";
        std::cout << "2.Произвольный массив\n";
        std::cout << "3.Элементы массива из файла\n";
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "4.Выход\n";
        SetConsoleTextAttribute(hConsole, 6);
        std::cout << "\nВведите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            ShellSort(data);
            break;
        case 2:
            system("cls");
            ShellSortRand(data);
            break;
        case 3:
            system("cls");
            ShellSortFromFile(data);
        case 4:
            system("cls");
            break;
        default:
            system("cls");
            SetConsoleTextAttribute(hConsole, 4);
            std::cout << "Некорректный выбор. Пожалуйста, введите цифру от 1 до 4 для выбора.\n\n";
            break;
        }
    }
}

int main() {
    std::vector<int> data;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Menu(data);

    return 0;
}