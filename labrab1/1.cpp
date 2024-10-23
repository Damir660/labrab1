#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <Windows.h>

int func1() {
    int mas[10] = { 10, 20, 11, 2, 3, 4, 5, 89, 1, 5 };
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i <= 9; i++) {
        if (mas[i] > max)
            max = mas[i];
        if (mas[i] < min)
            min = mas[i];
    }
    printf("Максимальное /  Минимальное: %d / %d", max, min);
    printf("\n\n");
    return 0;
}


int func2() {
    srand(time(NULL));

    int rows, cols;

    // Запрос количества строк и столбцов у пользователя
    printf("Введите количество строк: ");
    scanf("%d", &rows);

    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    // Выделение памяти для динамического двумерного массива
    int** mas = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mas[i] = (int*)malloc(cols * sizeof(int));
    }

    // Заполнение массива случайными числами в диапазоне [-40, 20]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mas[i][j] = rand() % 61 - 40;
            printf(" %d ", mas[i][j]);
        }
        printf("\n");
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < rows; i++) {
        free(mas[i]);
    }
    free(mas);

    printf("\n\n");
    return 0;
}


int func3() {
    srand(time(NULL));
    int a;
    printf("Введите мерность массива: ");
    scanf("%d", &a);
    int* arr = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        arr[i] = rand() % 2;
        printf(" %d ", arr[i]);
    }
    free(arr);
    printf("\n\n");
    return 0;
}

int func4() {
    srand(time(NULL));
    int mas[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mas[i][j] = rand() % 100;
            printf(" %d ", mas[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        int sum = mas[i][0] + mas[i][1] + mas[i][2];
        printf("Сумма в строке %d: %d\n", i, sum);
    }
    return 0;
}

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

// Функция поиска студента только по фамилии
int find_student_by_famil(struct student students[], int size, const char* fam) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].famil, fam) == 0) {
            return i; // Возвращаем индекс найденного студента
        }
    }
    return -1; // Если студент не найден
}

int func5() {
    struct student stud[3];

    // Заполнение массива студентами
    strcpy(stud[0].famil, "Иванов");
    strcpy(stud[0].name, "Иван");
    strcpy(stud[0].facult, "ФВТ");
    stud[0].Nomzach = 123;

    strcpy(stud[1].famil, "Путин");
    strcpy(stud[1].name, "Владимир");
    strcpy(stud[1].facult, "ФВТ");
    stud[1].Nomzach = 456;

    strcpy(stud[2].famil, "Тинчурин");
    strcpy(stud[2].name, "Дамир");
    strcpy(stud[2].facult, "ФВТ");
    stud[2].Nomzach = 789;

    char fam[20];

    // Запрос только фамилии у пользователя
    printf("Введите фамилию студента: ");
    scanf("%19s", fam);

    // Поиск студента по фамилии
    int found_index = find_student_by_famil(stud, 3, fam);

    if (found_index != -1) {
        printf("Студент найден!\n");
        printf("Фамилия: %s\n", stud[found_index].famil);
        printf("Имя: %s\n", stud[found_index].name);
        printf("Факультет: %s\n", stud[found_index].facult);
        printf("Номер зачётной книжки: %d\n", stud[found_index].Nomzach);
    }
    else {
        printf("Студент с такой фамилией не найден.\n");
    }

    return 0;
}


int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        printf("Выберите функцию:\n");
        printf("1 - Функция 1 (Макс / мин)\n");
        printf("2 - Функция 2 (Массив случайных чисел)\n");
        printf("3 - Функция 3 (Массив любого размера)\n");
        printf("4 - Функция 4 (Сумма в строке)\n");
        printf("5 - Функция 5 (Поиск студента)\n");

        scanf("%d", &choice);  // Чтение целого числа

        switch (choice) {
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        case 4:
            func4();
            break;
        case 5:
            func5();
            break;
        default:
            printf("Неверный выбор\n");
        }

        printf("Хотите продолжить? (1 - да, 0 - нет)\n");
        scanf("%d", &choice);

    } while (choice == 1);
}
// существить возможность поиск по струтуре по необходимому элементу по фамилии
// массивы. там где двумерный массив, сделать динамический двумернйы массив и элементы  диапазоне от -40  до 20