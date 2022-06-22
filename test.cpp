#include <iostream>
#include <string>
int main()
{
    std::string date1 = "2020/03/17 17:01:24.884492";
    std::string date2 = "2020/03/17 17:01:30.099017";
    if (date1 < date2)
    {
        std::cout << date2 << "comes after " << date1 << std::endl;
    }
    if (date1 > date2)
    {
        std::cout << date1 << "comes after " << date2 << std::endl;
    }
}