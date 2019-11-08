#include <iostream>
#include "timepoint.h"

int main()
{
    std::cout << "Меню\n1)Вычисление разницы между двумя моментами времени\n2)Сумма моментов времени\n3)Сложение момента времени и заданного количества секунд\n4)Вычитание из момента времени заданного количества секунд\n5)Вычисление, во сколько раз один момент времени больше(меньше) другого\n6)Сравнение моментов времени\n7)Перевод в секунды\n8)Перевод в минуты\n9)Перевод из секунд в формат час:минута:секунда\n10)Перевод из минут в формат час:минута:секунда\n";
    std::string npt;
    TimePoint res;
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
        first.printing();
    }
    if (npt == "2") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите первый момент времени: ";
        TimePoint first;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите второй момент времени: ";
        TimePoint second;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        first.summaring(second);
        first.printing();
    }
    if (npt == "3") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент времени: ";
        TimePoint moment;
        long long addsec;
        std::cin >> moment.hours >> tmp >> moment.min >> tmp >> moment.sec;
        std::cout << "Введите количество секунд: ";
        std::cin >> addsec;
        moment.secadding(addsec);
        moment.printing();
    }
    if (npt == "4") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите момент времени: ";
        TimePoint moment;
        std::cin >> moment.hours >> tmp >> moment.min >> tmp >> moment.sec;
        long long diffsec;
        std::cout << "Введите количество секунд: ";
        std::cin >> diffsec;
        moment.secdiff(diffsec);
        moment.printing();
    }
    if (npt == "5") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите первый момент времени: ";
        TimePoint first;
        double answ = 0;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите второй момент времени: ";
        TimePoint second;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        if (first.compare(second, &answ) && (answ != 1)) {
            std::cout << "Первый момент больше второго в " << answ << " раз\n";
        }
        else if (answ == 1) {
            std::cout << "Они равны\n";
        }
        else {
            std::cout << "Первый момент меньше второго в " << answ << " раз\n";
        }
    }

    if (npt == "6") {
        std::cout << "Ввод осуществляется в формате час:минута:секунда\nВведите первый момент времени: ";
        TimePoint first;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cout << "Введите второй момент времени: ";
        TimePoint second;
        double answ = 0;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        if (first.compare(second, &answ) && (answ != 1)) {
            std::cout << "Первый момент больше второго\n";
        }
        else if (answ == 1) {
            std::cout << "Они равны\n";
        }
        else {
            std::cout << "Первый момент меньше второго\n";
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
        long long addsec;
        std::cout << "Введите количество секунд: ";
        std::cin >> addsec;
        res.hours = 0, res.min = 0, res.sec = 0;
        res.secadding(addsec);
        res.printing();
    }
    if (npt == "10") {
        long long addmin;
        std::cout << "Введите количество минут: ";
        std::cin >> addmin;
        res.hours = 0, res.min = 0, res.sec = 0;
        res.minadding(addmin);
        res.printing();
    }
    if (npt == "11") {
        TimePoint first;
        TimePoint second;
        long long addsec;
        std::cin >> first.hours >> tmp >> first.min >> tmp >> first.sec;
        std::cin >> second.hours >> tmp >> second.min >> tmp >> second.sec;
        std::cin >> addsec;
        res = first;
        res.difference(second);
        res.printing();
        res = first;
        res.summaring(second);
        res.printing();
        res = first;
        res.secadding(addsec);
        res.printing();
        res = first;
        res.secdiff(addsec);
        res.printing();
        res = first;
        res.minadding(addsec);
        res.printing();
        res = first;
        std::cout << res.trans_to_min() << "\n";
        res = first;
        std::cout << res.trans_to_sec() << "\n";
        res = first;
        std::cout << res.trans_to_min() << "\n";
    }
}
