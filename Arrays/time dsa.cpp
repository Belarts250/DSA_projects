#include <iostream>
#include <ctime>

int main() {

    time_t now = time(0);


    char* local_dt = ctime(&now);

    std::cout << "The local date and time is: " << local_dt << std::endl;


    tm *gmtm = gmtime(&now);
    char* utc_dt = asctime(gmtm);
    std::cout << "The UTC date and time is: " << utc_dt << std::endl;

    return 0;
}