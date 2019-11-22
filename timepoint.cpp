#include <iostream>
#include <cmath>
#include "timepoint.h"

        void TimePoint::summaring(TimePoint second)
        {
            this->sec += second.sec;
            this->min += second.min + (this->sec / 60);
            this->hours += second.hours + (this->min / 60);
            this->min = this->min % 60;
            this->sec = this->sec % 60;
            this->hours = this->hours % 24;
        }

        void TimePoint::difference(TimePoint second)
        {
            this->hours -= second.hours;
            if (this->hours < 0) {
                this->hours += 24;
            }
            this->min -= second.min;
            if (this->min < 0) {
                this->hours -=1;
                this->min += 60;
            }
            this->sec -= second.sec;
            if (this->sec < 0) {
                this->min -= 1;
                this->sec += 60;
            }
        }
        void TimePoint::secadding(long long addsec)
        {
            this->sec += addsec % 60;
            this->min += (addsec / 60) % 60;
            this->hours += addsec / 3600;
            if (this->sec >= 60) {
                this->sec = this->sec % 60;
                this->min += 1;
            }
            if (this->min >= 60) {
                this->min = this->min % 60;
                this->hours += 1;
            }
            this->hours = this->hours % 24;
        }
        void TimePoint::secdiff(long long diffsec)
        {
            this->sec -= diffsec;
            if (this->sec < 0) {
                this->min -= 1;
                this->min -= diffsec / 60;
                this->sec = this->sec % 60 + 60;
            }
            if (this->min < 0) {
                this->hours -= diffsec / 3600;
                this->min = this->min % 60 + 60;
            }
            this->sec = this->sec % 60;
            this->min = this->min % 60;
            this->hours = abs(this->hours % 24);
        }
        void TimePoint::minadding(long long addmin)
        {
            this->min += addmin % 60;
            this->hours += addmin / 60;
            if (this->min >= 60) {
                this->min = this->min % 60;
                this->hours += 1;
            }
            this->hours = this->hours % 24;
        }
        bool TimePoint::compare(TimePoint moment, double &answ) {
            long long a = this->trans_to_sec();
            long long b = moment.trans_to_sec();
            answ = double(a) / double(b);
            return a > b;
        }
        long long TimePoint::trans_to_sec() {
            this->min = (this->hours * 60) + this->min;
            this->sec = (this->min * 60) + this->sec;
            return this->sec;
        }
        long long TimePoint::trans_to_min() {
            this->min = (this->hours * 60) + this->min;
            if (this->sec >= 30) {
                this->min += 1;
            }
            return this -> min;
        }
        void TimePoint::printing () {
            std::cout << "Результат:\n" << this->hours  << " часов " << this->min << " минут " << this->sec << " секунд\n";
        }
