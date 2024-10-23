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
    printf("������������ /  �����������: %d / %d", max, min);
    printf("\n\n");
    return 0;
}


int func2() {
    srand(time(NULL));

    int rows, cols;

    // ������ ���������� ����� � �������� � ������������
    printf("������� ���������� �����: ");
    scanf("%d", &rows);

    printf("������� ���������� ��������: ");
    scanf("%d", &cols);

    // ��������� ������ ��� ������������� ���������� �������
    int** mas = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mas[i] = (int*)malloc(cols * sizeof(int));
    }

    // ���������� ������� ���������� ������� � ��������� [-40, 20]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mas[i][j] = rand() % 61 - 40;
            printf(" %d ", mas[i][j]);
        }
        printf("\n");
    }

    // ������������ ���������� ������
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
    printf("������� �������� �������: ");
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
        printf("����� � ������ %d: %d\n", i, sum);
    }
    return 0;
}

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

// ������� ������ �������� ������ �� �������
int find_student_by_famil(struct student students[], int size, const char* fam) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].famil, fam) == 0) {
            return i; // ���������� ������ ���������� ��������
        }
    }
    return -1; // ���� ������� �� ������
}

int func5() {
    struct student stud[3];

    // ���������� ������� ����������
    strcpy(stud[0].famil, "������");
    strcpy(stud[0].name, "����");
    strcpy(stud[0].facult, "���");
    stud[0].Nomzach = 123;

    strcpy(stud[1].famil, "�����");
    strcpy(stud[1].name, "��������");
    strcpy(stud[1].facult, "���");
    stud[1].Nomzach = 456;

    strcpy(stud[2].famil, "��������");
    strcpy(stud[2].name, "�����");
    strcpy(stud[2].facult, "���");
    stud[2].Nomzach = 789;

    char fam[20];

    // ������ ������ ������� � ������������
    printf("������� ������� ��������: ");
    scanf("%19s", fam);

    // ����� �������� �� �������
    int found_index = find_student_by_famil(stud, 3, fam);

    if (found_index != -1) {
        printf("������� ������!\n");
        printf("�������: %s\n", stud[found_index].famil);
        printf("���: %s\n", stud[found_index].name);
        printf("���������: %s\n", stud[found_index].facult);
        printf("����� �������� ������: %d\n", stud[found_index].Nomzach);
    }
    else {
        printf("������� � ����� �������� �� ������.\n");
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
        printf("�������� �������:\n");
        printf("1 - ������� 1 (���� / ���)\n");
        printf("2 - ������� 2 (������ ��������� �����)\n");
        printf("3 - ������� 3 (������ ������ �������)\n");
        printf("4 - ������� 4 (����� � ������)\n");
        printf("5 - ������� 5 (����� ��������)\n");

        scanf("%d", &choice);  // ������ ������ �����

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
            printf("�������� �����\n");
        }

        printf("������ ����������? (1 - ��, 0 - ���)\n");
        scanf("%d", &choice);

    } while (choice == 1);
}
// ���������� ����������� ����� �� �������� �� ������������ �������� �� �������
// �������. ��� ��� ��������� ������, ������� ������������ ��������� ������ � ��������  ��������� �� -40  �� 20