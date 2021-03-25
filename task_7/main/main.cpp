#include <iostream>
#include <numeric>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>

int main()
{
    srand(time(0));
    std::deque<int> deq;
    std::vector<int> vect;
    for (int i = 1; i < 11; i++)
    {
        deq.push_back(i);
    }
    // Добавление в начало пару чисел
    deq.push_front(rand() % 10);
    deq.push_front(rand() % 10);
    deq.push_front(rand() % 10);

    // Копирование содержимого контейнера в другой контейнер
    vect.resize(deq.size());
    std::copy(deq.begin(), deq.end(), vect.begin());
    for (auto i : vect) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // Сортировка вектора по убыванию
    std::sort(vect.begin(), vect.end(),
        std::greater<>());
    for (auto i : vect) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // Перемешиваем deque случайным образом
    std::random_shuffle(deq.begin(), deq.end());

    // Вычисляем скалярное произведение vector-а и deque.
    std::cout << std::inner_product(vect.begin(), vect.end(),
        deq.begin(), 0);
    std::cout << std::endl;
    // Определяем количество чисел, больших 4, в любом из контейнеров.
    std::cout << std::count_if(deq.begin(), deq.end(),
        [](auto x) {return x  > 4; });

    std::cout << std::endl;
    std::cout << std::endl;
    // Находим сумму элементов vector-а.
    std::cout << std::accumulate(vect.begin(), vect.end(), 0);

    std::cout << std::endl;
    std::cout << std::endl;
    // Находим произведение элементов deque.
    std::cout << std::accumulate(deq.begin(), deq.end(), 1,
        [](auto x, auto y) {return x * y; });

    std::cout << std::endl;
    std::cout << std::endl;
    // Удаляем из vector все чётные числа, большие 3.
    auto start = std::remove_if(vect.begin(), vect.end(), [](auto x) {return (x > 3 && x % 2 == 0); });
    vect.erase(start, vect.end());
    std::cout << "====================" << std::endl;
    // Удаляем из deque все четвёрки.
    auto start1 = std::remove(deq.begin(), deq.end(), 4);
    deq.erase(start1, deq.end());
    // Выведите vector в консоль с помощью цикла for через итераторы.
    std::vector<int>::iterator it;
    it = vect.begin();
    for (auto it : vect)
    {
        std::cout << it << std::endl;
    }

    // Вывод deque в консоль с помощью алгоритма for_each.
    std::for_each(deq.begin(), deq.end(), [](int a) {std::cout << a << std::endl; });
    // Определите минимальный и максимальный элементы в этих контейнерах.
    auto min_max_deq = std::minmax_element(deq.begin(), deq.end());
    std::cout << *(min_max_deq.first) << ' ' << *(min_max_deq.second) << std::endl;

    auto min_max_vect = std::minmax_element(vect.begin(), vect.end());
    std::cout << *(min_max_vect.first) << ' ' << *(min_max_vect.second) << std::endl;
    std::cout << "Hello World!\n";
}


