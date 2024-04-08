#include <iostream>
#include "String.h"

int main() {
    cppf::String str0{};    // default constructor
    cppf::String str1{"Alice"}; // from a string literal
    cppf::String str2 = std::string{"Bob"}; // from std::string
    cppf::String str3{str1};    // copy constructor
    str0 = str1;    // copy assignment operator
    cppf::String str4 = str1+str2;
    cppf::String str5 = str1+" "+str2;
    cppf::String str6{"Hello"};
    str6 += "Alice";

    std::cout << "Empty string constructor:" << str0 <<std::endl;
    std::cout << "Size:"<<str0.size() << std::endl;
    std::cout << "Is empty?:"<<str0.empty() << std::endl;
    if(!str0)
        std::cout << "Is empty if():"<<str0.empty() << std::endl;

    std::cout << "Literal string constructor:" << str1 <<std::endl;
    std::cout << "Size:"<<str1.size() << std::endl;
    std::cout << "Is empty?:"<<str1.empty() << std::endl;
    std::cout << "Char at 2:"<<str1.at(2) << std::endl;
    std::cout << "Char at 2 with[]:"<<str1[2]<< std::endl;
    str1[2] = 'b';
    std::cout << "Changed char at [2]:"<<str1[2]<<":"<<str1<< std::endl;

    std::cout << "std::string string constructor:" << str2 <<std::endl;

    std::cout << "Copy string constructor:" << str3 <<std::endl;

    std::cout << "Copy operator from  to Bob:" << str0 <<std::endl;

    std::cout << "+ operator AliceBob:" << str4 <<std::endl;

    std::cout << "+ chain operator Alice Bob:" << str5 <<std::endl;

    std::cout << "+= operator HelloAlice:" << str6 <<std::endl;

    if(str1 > str2)
        std::cout<< str1 << ">" << str2 <<std::endl;

    if(str2 < str1)
        std::cout<< str2 << "<" << str1 <<std::endl;

    if(str3 == str2)
        std::cout<< str3 << "==" << str2 <<std::endl;
    return 0;
}
