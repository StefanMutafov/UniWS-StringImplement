//
// Created by Stefan on 03/04/2024.
//

#ifndef STRING_IMPLEMENT_STRING_H
#define STRING_IMPLEMENT_STRING_H

#include <iostream>
#include <memory>
#include <cstring>

namespace cppf {

    class String {
    public:
        String();

        explicit String(const char *input);

        explicit String(const char c);

        String(const cppf::String &other);

        String(const std::string &other);

        cppf::String &operator=(const cppf::String &other);

        cppf::String &operator+=(const cppf::String &other);

        cppf::String &operator+=(const char *other);

        cppf::String &operator+=(char other);

        bool operator==(const cppf::String &rhs) const;

        bool operator!=(const cppf::String &rhs) const;

        bool operator>(const cppf::String &rhs) const;

        bool operator<(const cppf::String &rhs) const;

        bool operator<=(const cppf::String &rhs) const;

        bool operator>=(const cppf::String &rhs) const;

        bool operator!() const;

        explicit operator bool() const;

        char operator[](std::size_t pos) const;

        char &operator[](std::size_t pos);

        /*  Accessors */
        size_t size() const;

        //What does this non-discard do?
        bool empty() const;

        char *c_str() const;

        char *data() const;

        char at(std::size_t index) const;

        char *begin() const;

        char *end() const;


        /*  Modifiers */
        void append(const String &other);

        void append(const char *str);

        void append(const std::string &str);

        void append(char c);

        void clear();

    private:
        std::size_t length_;
        std::unique_ptr<char[]> storage_;

    };

    cppf::String operator+(const cppf::String &lhs, const cppf::String &rhs);
    cppf::String operator+(const cppf::String& lhs, const char* rhs);
    cppf::String operator+(const char* lhs, const cppf::String& rhs);
    cppf::String operator+(const cppf::String& lhs, char rhs);
    cppf::String operator+(char lhs, const cppf::String& rhs);

    std::ostream& operator<<(std::ostream& out, const cppf::String &str);
} // cppf

#endif //STRING_IMPLEMENT_STRING_H
