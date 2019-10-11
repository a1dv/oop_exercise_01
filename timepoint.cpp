#include <iostream>
#include <cmath>
#include "timepoint.h"

        TimePoint TimePoint::summaring(TimePoint second)
        {
            this->sec += second.sec;
            this->min += second.min + (this->sec / 60);
            this->hours += second.hours + (this->min / 60);
            this->min = this->min % 60;
            this->sec = this->sec % 60;
            this->hours = this->hours % 24;
        }

        TimePoint TimePoint::difference(TimePoint second)
        {
            this->sec -= second.sec;
            if (this->sec < 0) {
                this->min -= 1;
                this->sec += 60;
            }
            this->min -= second.min;
            if (this->min < 0) {
                this->hours -= 1;
                this->min += 60;
            }
            this->hours -= second.hours;
            this->hours = abs(this->hours);
        }
        TimePoint TimePoint::secadding(long long addsec)
        {
            this->sec += addsec % 60;
            this->min += (addsec / 60) % 60;
            this->hours += addsec / 3600;
        }
        TimePoint TimePoint::minadding(long long addmin)
        {
            if ((addmin / 60) > 1) {
                this->min = addmin % 60;
                this->hours = addmin / 60;
            }
            else {
                this->sec = addmin;
            }
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
            std::cout << "Результат:\n" << this->hours  << " часов " << this->min << " минут " << this->sec << " секунд ";
        }
