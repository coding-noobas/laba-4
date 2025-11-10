#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <windows.h>
#define isn isnatural

void normal_input(int** a, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
}

void random_input(int** a, int n, int m){
    std::cout << "Please enter the interval of numbers in array(min max): ";
    int l, r;
    std::cin >> l >> r;
    if(l > r) std::swap(l, r);
    std::cout << "Your matrix: \n";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            a[i][j] = l + rand() % (r - l + 1);
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void solve(int** a, int m, int n){
    for (int i = 0; i < n; i++) {
        if(i % 2 == 0) std::sort(a[i], a[i] + m), std::reverse(a[i], a[i] + m);
        else std::sort(a[i], a[i] + m);
    }
    std::cout << "Your sorted matrix: \n";
    for (int i = 0; i < n; i++) {
        for(int j = 0;j < m;j++){
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool isnatural (int x){
    return x > 0 && x == static_cast<int>(x);
}

void fail(){
    std::cout << "Ќу как так вы совершили неправильный ввод подумайте над своим поведением" << "\n";
}

int main()
{
    int n, m, ans{};
    char x;
    SetConsoleOutputCP(1251);
    std::cout << " ак вы считаете будете ли вы вводить буквы когда прос€т целые числа или прос€т натуральные или быть может вы провер€ете эту лабу и ваша цель сломать мой код? ¬ведите 1 если что-то из вышеперечисленного относитс€ к вам или 0 если вы средний пользователь: \n";
    std::cin >> x;
    if(x == '1' || x == '0'){
        std::cout << "” вас ещЄ есть шанс на исправление\n";
    }
    else{
        std::cout << "“€жЄлый случай...\n";
    }
    std::cout << "Enter quantity of rows and columns: ";
    std::cin >> n >> m;
    if(!isn(n) || !isn(m)){
        fail();
        return 0;
    }
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
    }
    std::cout << "Normal or Random input?!(N or R): ";
    std::cin >> x;
    if(x == 'N') normal_input(a, n, m);
    if(x == 'R') random_input(a, n, m);
    if(x != 'N' && x != 'R'){
        fail();
        return 0;
    }
    solve(a, m, n);

    for (int i = 0; i < n; ++i) {
        delete a[i];
    }
    delete a;
    return 0;
}
