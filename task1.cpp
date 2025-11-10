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

bool isnatural(int32_t x) {
    return x > 0 && x == static_cast<int32_t>(x);
}

isint(int32_t x){
    return x == static_cast<int32_t>(x);
}

void fail() {
    std::cout << "Ќу как так вы совершили неправильный ввод подумайте над своим поведением" << "\n";
}

void normal(int32_t** a, int32_t n, int32_t m) {
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            if (!isint(a[i][j])) {
                fail();
                exit(0);
            }
        }
    }
}

void random(int32_t** a, int32_t n, int32_t m) {
    std::cout << "Please enter the interval of numbers in array(min max): ";
    int32_t l, r;
    std::cin >> l >> r;
    if (!isint(l) || !isint(r)) {
        fail();
        exit(0);
    }
    std::cout << "Your matrix: \n";
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            a[i][j] = l + rand() % (r - l + 1);
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void solve(int32_t** a, int32_t n, int32_t m, int32_t* sum, int32_t* b) {
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

int32_t main() {
    int32_t n, m;
    SetConsoleOutputCP(1251);
    std::cout << "Enter quantity of rows and columns: ";
    std::cin >> n >> m;

    if (!isn(n) || !isn(m)) {
        fail();
        return 0;
    }

    int32_t** a = new int32_t*[n];
    for (int32_t i = 0; i < n; ++i) {
        a[i] = new int32_t[m];
    }

    int32_t* sum = new int32_t[m];
    int32_t* b = new int32_t[m];

    for (int32_t i = 0; i < m; ++i) {
        sum[i] = 0;
        b[i] = 0;
    }

    std::cout << "Normal or Random input?!(N or R): ";
    char x;
    std::cin >> x;

    if (x == 'N') {
        normal(a, n, m);
    }
    else if (x == 'R') {
        random(a, n, m);
    }
    else {
        fail();
        return 0;
    }

    solve(a, n, m, sum, b);

    for (int32_t i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    delete[] sum;
    delete[] b;

    return 0;
}
