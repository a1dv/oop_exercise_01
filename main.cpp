#include <iostream>
#include "timepoint.h"

int main()
{
    std::cout << "Меню\n1)Вычисление разницы между двумя моментами времени\n2)Сумма моментов времени\n3)Сложение момента времени и заданного количества секунд\n4)Вычитание из момента времени заданного количества секунд\n5)Вычисление, во сколько раз один момент времени больше(меньше) другого\n6)Сравнение моментов времени\n7)Перевод в секунды\n8)Перевод в минуты\n9)Перевод из секунд в формат час:минута:секунда\n10)Перевод из минут в формат час:минута:секунда\n";
    TimePoint* arrow;
    TimePoint res;
    std::string npt;
    char tmp;
    std::cin >> npt;
    if (npt == "1") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент, из которого необходимо произвести вычитание: ";
        TimePoint first;
        TimePoint second;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите момент времени, который необходимо вычесть: ";
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        first.difference(second);
        std::cout << "Результат:\n" << first.hours << " часов " << first.min << " минут " << first.sec << " секунд ";
    }
    if (npt == "2") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите первый момент времени: ";
        TimePoint first;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите второй момент времени: ";
        TimePoint second;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        first.summaring(second);
        std::cout << "Результат:\n" << first.hours  << " часов " << first.min << " минут " << first.sec << " секунд ";
    }
    if (npt == "3") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент времени: ";
        TimePoint moment;
        int addsec;
        std::cin >> moment.hours >> tmp >> moment.min >> tmp >> moment.sec;
        std::cout << "Введите количество секунд: ";
        std::cin >> addsec;
        res = arrow->secadding(addsec);
        res.summaring(moment);
        std::cout << "Результат:\n" << res.hours  << " часов " << res.min << " минут " << res.sec << " секунд ";
    }
    if (npt == "4") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент времени: ";
        TimePoint moment;
        std::cin >> moment.hours >> tmp >> moment.min >> tmp >> moment.sec;
        int addsec;
        std::cout << "Введите количество секунд: ";
        std::cin >> addsec;
        res = arrow->secadding(addsec);
        res.difference(moment);
        std::cout << "Результат:\n" << res.hours << " часов " << res.min << " минут " << res.sec << " секунд ";
    }
    if (npt == "5") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите первый момент времени: ";
        TimePoint first;
        double answ = 0;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите второй момент времени: ";
        TimePoint second;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        long long a = 0;
        long long b = 0;
        a = first.trans_to_sec();
        b = second.trans_to_sec();
        if ((a / b) > 0) {
            answ = double(a) / double(b);
            std::cout << "Первый момент больше второго в " << answ << " раз\n";
        }
        else {
          answ = double(b) / double(a);
          std::cout << "Первый момент меньше второго в " << answ << " раз\n";
        }
    }

    if (npt == "6") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите первый момент времени: ";
        TimePoint first;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите второй момент времени: ";
        TimePoint second;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        long long a = 0;
        long long b = 0;
        a = first.trans_to_sec();
        b = second.trans_to_sec();
        if (a > b) {
            std::cout << "Первый момент времени больше второго";
        }
        if (a < b) {
            std::cout << "Второй момент времени больше первого";
        }
        if (a == b) {
            std::cout << "Они равны";
        }

    }
    if (npt == "7") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент времени: ";
        TimePoint moment;
        std::cin >> moment.hours >> tmp >> moment.min >> tmp >> moment.sec;
        long long answ = moment.trans_to_sec();
        std::cout << "Результат:\n" << answ << " секунд ";
    }
    if (npt == "8") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент времени: ";
        TimePoint moment;
        std::cin >> moment.hours >> tmp >> moment.min >> tmp >> moment.sec;
        long long answ = moment.trans_to_min();
        std::cout << "Результат:\n" << answ << " минут ";
    }
    if (npt == "9") {
        int addsec;
        std::cout << "Введите количество секунд: ";
        std::cin >> addsec;
        res.secadding(addsec);
        std::cout << "Результат:\n" << res.hours % 24 << " часов " << res.min << " минут " << res.sec << " секунд ";
    }
    if (npt == "10") {
        int addmin;
        std::cout << "Введите количество минут: ";
        std::cin >> addmin;
        res.minadding(addmin);
        std::cout << "Результат:\n" << res.hours % 24 << " часов " << res.min << " минут " << res.sec << " секунд ";
    }
}
