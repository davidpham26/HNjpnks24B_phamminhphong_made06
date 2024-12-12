#include <stdio.h>

int inputArray(int arr[], int max) {
    int n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    if (n > max) {
        printf("So phan tu vuot qua gioi han %d!\n", max);
        return 0;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

int printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1;
}

int countPerfectNumbers(int arr[], int n) {
    int i, j, count = 0, sum;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 1; j <= arr[i] / 2; j++) {
            if (arr[i] % j == 0) sum += j;
        }
        if (sum == arr[i]) count++;
    }
    return count;
}

int findSecondSmallest(int arr[], int n) {
    int i, min1 = __INT_MAX__, min2 = __INT_MAX__;
    for (i = 0; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    return min2;
}

int addElement(int arr[], int n, int x, int pos, int max) {
    int i;
    if (pos < 0 || pos > n || n >= max) return n;
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    int i;
    if (pos < 0 || pos >= n) return n;
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 1;
}

int isAscendingArray(int arr[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) return 1;
    }
    return 0;
}

int main() {
    const int MAX = 100;
    int arr[MAX], n = 0, choice, x, pos;

    do {
        printf("\n____MENU____:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong so hoan hao trong mang\n");
        printf("4. Tim gia tri nho thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri bat ky\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = inputArray(arr, MAX);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("So luong so hoan hao: %d\n", countPerfectNumbers(arr, n));
                break;
            case 4:
                printf("Gia tri nho thu 2: %d\n", findSecondSmallest(arr, n));
                break;
            case 5:
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                n = addElement(arr, n, x, pos, MAX);
                break;
            case 6:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                n = deleteElement(arr, n, pos);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    return 0;
}

