/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000
#define MAX_LEN 15  // 10^12 �ִ� 13�ڸ� + �ι���

unsigned long long arr[MAX_N];

// ���� ���ڿ��� ������ unsigned long long���� ��ȯ�ϴ� �Լ�
unsigned long long reverse_str_to_ull(char* str) {
    int len = strlen(str);
    unsigned long long res = 0;
    for (int i = len - 1; i >= 0; i--) {
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

// ������ partition �Լ�
int partition(unsigned long long* a, int left, int right) {
    unsigned long long pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            unsigned long long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    unsigned long long temp = a[i+1];
    a[i+1] = a[right];
    a[right] = temp;
    return i+1;
}

// ������ �Լ�
void quicksort(unsigned long long* a, int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quicksort(a, left, p - 1);
        quicksort(a, p + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char buffer[MAX_LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        arr[i] = reverse_str_to_ull(buffer);
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%llu\n", arr[i]);
    }

    return 0;
}*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000
#define MAX_LEN 15  // 10^12 �ִ� 13�ڸ� + �ι���

unsigned long long arr[MAX_N];

// ���� ���ڿ��� ������ unsigned long long���� ��ȯ�ϴ� �Լ�
unsigned long long reverse_str_to_ull(char* str) {
    int len = strlen(str);
    unsigned long long res = 0;
    for (int i = len - 1; i >= 0; i--) {
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

// ������ partition �Լ�
int partition(unsigned long long* a, int left, int right) {
    unsigned long long pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            unsigned long long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    unsigned long long temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;
    return i + 1;
}

// ������ �Լ�
void quicksort(unsigned long long* a, int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quicksort(a, left, p - 1);
        quicksort(a, p + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char buffer[MAX_LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        arr[i] = reverse_str_to_ull(buffer);
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%llu\n", arr[i]);
    }

    return 0;
}

