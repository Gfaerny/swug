    #include <iostream>

    using namespace std;

     string OsC()
    {
        #ifdef __linux__
            return "linux";

        #elif _WIN32
            return "windows";

        #else
            return "N";

        #endif
    }