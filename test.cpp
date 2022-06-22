#include <iostream>
#include <string>
#include <cmath>

bool is_number(const std::string& s) {
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

int main()
{
    // std::string date1 = "2020/03/17 17:01:24.884492";
    // std::string date2 = "2020/03/17 17:01:30.099017";
    // if (date1 < date2)
    // {
    //     std::cout << date2 << "comes after " << date1 << std::endl;
    // }
    // if (date1 > date2)
    // {
    //     std::cout << date1 << "comes after " << date2 << std::endl;
    // }
    if (is_number("800M")) {
        std::cout << "valid" << std::endl;
    } else {
        std::cout << "invalid" << std::endl;
    }
}