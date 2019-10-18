#include <iostream>

class TimePoint
{
    public:
        long long hours;
        long long min;
        long long sec;

        TimePoint summaring(TimePoint second);

        TimePoint difference(TimePoint second);

        bool compare(TimePoint moment, double* answ);

        TimePoint secadding(long long addsec);

        TimePoint secdiff(long long diffsec);

        TimePoint minadding(long long addmin);

        long long trans_to_sec();

        long long trans_to_min();

        void printing();

};
