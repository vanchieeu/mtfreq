#include <iostream>
using namespace std;

#define HASH_SIZE 1201

typedef struct arr {
    long n;

    struct arr *next;
} arr;
arr *head[HASH_SIZE];

void initHash(arr *head[]) {
    for (int i = 0; i < HASH_SIZE; i++)
        head[i] = NULL;
}

arr *creatArr(long n) {
    arr *a = new arr;

    a->n = n;
    a->next = NULL;

    return a;
}

int hash_func(long n) {
    return n % HASH_SIZE;
}

void insertHash(long n) {
    arr *a = new arr;
    a = creatArr(n);

    int index = hash_func(n);
    if (head[index] == NULL) {
        head[index] = a;
    } else {
        a->next = head[index];
        head[index] = a;
    }
}

void checkArr(long *a, bool *check, int n, long x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            check[i] = false;
}

int countHash(long n) {
    int index = hash_func(n);

    arr *ptr = new arr;
    ptr = head[index];

    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    initHash(head);

    long a[n];
    bool check[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        check[i] = true;
        insertHash(a[i]);
    }

    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++)
        if (head[i] != NULL)
            count++;
    cout << count << endl;

    for (int i = 0; i < n; i++) {
        if (check[i]) {
            checkArr(a, check, n, a[i]);

            cout << a[i] << " " << countHash(a[i]) << endl;
        }
    }
    return 0;
}