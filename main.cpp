#include <iostream>
#include <vector.h>

int main() {
    Vector<double>  vec(10,3.5);
    Vector<double>::iterator it =vec.begin();
    std::cout<<*it<<std::endl;
    std::cout<<vec[0]<<std::endl;

    std::cout<<vec(8)<<std::endl;
    std::cout<<vec.size()<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}