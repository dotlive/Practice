#include <iostream>
#include <memory>

int main()
{
        std::shared_ptr<double> ptr( new double(2.3) );
        std::cout << *ptr << std::endl;
        return 0;   
}
