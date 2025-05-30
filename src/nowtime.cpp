    #include <ctime>
    #include <iostream>
    #include <iomanip>  

    #include "nowtime.hpp"
    using namespace std;

    void NowTimeSwug()
    {
        time_t now = time(nullptr);
    tm* local_time = localtime(&now);

    cout << put_time(local_time, "%H:%M:%S") ;

    }