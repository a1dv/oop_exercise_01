#include <iostream>

class TimePoint
{
    public:
        int hours;
        int min;
        int sec;

        TimePoint summaring(TimePoint second);

        TimePoint difference(TimePoint second);

        TimePoint secadding(int addsec);

        TimePoint minadding(int addmin);

        long long trans_to_sec();

        long long trans_to_min();

};
