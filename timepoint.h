#include <iostream>

class TimePoint
{
    public:
        long long hours;
        long long min;
        long long sec;

        void summaring(TimePoint second);

        void difference(TimePoint second);

        bool compare(TimePoint moment, double* answ);

        void secadding(long long addsec);

        void secdiff(long long diffsec);

        void minadding(long long addmin);

        long long trans_to_sec();

        long long trans_to_min();

        void printing();

};
