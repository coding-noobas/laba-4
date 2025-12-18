#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <cstdint>
#define isn isnatural

void is_natural(int32_t* x) {
    while (!(std::cin >> *x) || *x <= 0) {
        std::cout << "Please enter integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void is_int(int32_t* x) {
    while (!(std::cin >> *x) || *x != static_cast<int32_t>(*x)) {
        std::cout << "Please enter integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void normal(int32_t** a, int32_t n, int32_t m) {
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            is_int(&a[i][j]);
        }
    }
}

void random(int32_t** a, int32_t n, int32_t m) {
    std::cout << "Please enter the interval of numbers in array(min max): ";
    int32_t l, r;
    is_int(&l);
    is_int(&r);
    srand(time(nullptr));
    std::cout << "Your matrix: \n";
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            a[i][j] = l + rand() % (r - l + 1);
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void summ(int32_t** a, int32_t n, int32_t m, int32_t* sum, int32_t* b) {
    int32_t ans = 0;
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            sum[j] += a[i][j];
            if (a[i][j] == 0) {
                b[j] = 1;
            }
        }
    }
    for (int32_t i = 0; i < m; ++i) {
        if (b[i] == 1) {
            ans += sum[i];
        }
    }
    std::cout << "Sum of col with 0 is equal: " << ans << "\n";
}

void srt(int32_t** a, int32_t n, int32_t m) {
    for (int32_t i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            std::sort(a[i], a[i] + m);
        }
        else {
            std::sort(a[i], a[i] + m);
            std::reverse(a[i], a[i] + m);
        }
    }
    std::cout << "Your sorted matrix: \n";
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int32_t main() {
    int32_t n, m;
    SetConsoleOutputCP(1251);
    std::cout << "Enter quantity of rows and columns: ";
    is_int(&n);
    is_int(&m);

    int32_t** a = new int32_t * [n];
    for (int32_t i = 0; i < n; ++i) {
        a[i] = new int32_t[m];
    }

    int32_t* sum = new int32_t[m]{};
    int32_t* b = new int32_t[m]{};

    std::cout << "Normal or Random input?!(N or R): ";
    char x;
    while (!(std::cin >> x) || (x != 'N' && x != 'R')) {
        std::cout << "N or R: ";
    }
    if (x == 'N') {
        normal(a, n, m);
    }
    else if (x == 'R') {
        random(a, n, m);
    }

    summ(a, n, m, sum, b);
    srt(a, n, m);

    for (int32_t i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    delete[] sum;
    delete[] b;

    return 0;
}

