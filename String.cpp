    //
    // Created by Stefan on 03/04/2024.
    //


    #include "String.h"

    namespace cppf {

        String::String() :
                length_{0},
                storage_(new char[1]{}) {}

        String::String(const char *input) :
                length_{strlen(input)},
                storage_{new char[length_ + 1]} {
            std::copy(input, input + length_, storage_.get());
            storage_[length_] = '\0';
        }

        String::String(const char c) :
                length_{1},
                storage_{new char[2]{c}} {
        }

        String::String(const std::string &other) :
                length_{other.length()},
                storage_(new char[length_ + 1]) {
            std::copy(other.begin(), other.end(), storage_.get());
            storage_[length_] = '\0';
        }

        String::String(const cppf::String &other) :
                length_{other.length_},
                storage_(new char[other.length_ + 1]) {

            std::copy(other.storage_.get(), other.storage_.get() + other.length_, storage_.get());
            storage_[length_] = '\0';
        }



        std::ostream &operator<<(std::ostream &out, const cppf::String &str) {
            out << str.c_str();
            return out;
        }

        cppf::String &String::operator=(const cppf::String &other) {
            if (this != &other) {
                storage_.release();
                storage_ = std::unique_ptr<char[]>(new char[other.length_ + 1]);
                length_ = other.length_;
                std::copy(other.storage_.get(), other.storage_.get() + other.length_, storage_.get());
                //?Should I
                storage_[length_] = '\0';

            }
            return *this;
        }

        cppf::String &String::operator+=(const cppf::String &other) {
            this->append(other);
            return *this;
        }

        cppf::String &String::operator+=(const char *other) {
            this->append(other);
            return *this;
        }

        cppf::String &String::operator+=(char other) {
            this->append(other);
            return *this;
        }


        bool String::operator==(const String &rhs) const {
            return std::strcmp(this->c_str(), rhs.c_str()) == 0;
        }

        bool String::operator!=(const String &rhs) const {
            return !operator==(rhs);
        }

        bool String::operator>(const cppf::String &rhs) const {
            return std::strcmp(this->c_str(), rhs.c_str()) > 0;
        }

        bool String::operator<(const cppf::String &rhs) const {
            return std::strcmp(this->c_str(), rhs.c_str()) < 0;
        }

        bool String::operator<=(const cppf::String &rhs) const {
            return !operator>(rhs);
        }

        bool String::operator>=(const cppf::String &rhs) const {
            return !operator<(rhs);
        }

        cppf::String operator+(const cppf::String &lhs, const cppf::String &rhs) {
            cppf::String output{lhs};
            output.append(rhs);
            return output;
        }

        cppf::String operator+(const cppf::String &lhs, const char *rhs) {
            cppf::String output{lhs};
            output.append(rhs);
            return output;
        }

        cppf::String operator+(const char *lhs, const cppf::String &rhs) {
            cppf::String output{lhs};
            output.append(rhs);
            return output;
        }

        cppf::String operator+(const cppf::String &lhs, char rhs) {
            cppf::String output{lhs};
            output.append(rhs);
            return output;
        }

        cppf::String operator+(char lhs, const cppf::String &rhs) {
            cppf::String output{lhs};
            output.append(rhs);
            return output;
        }

        char String::operator[](std::size_t index) const {
            return *(storage_.get() + index);
        }

        char &String::operator[](std::size_t index) {
            return *(storage_.get() + index);
        }

        bool cppf::String::operator!() const {
            return !this->empty();
        }

        String::operator bool() const {
            return this->empty();
        }

        bool String::empty() const {
            if (length_ == 0)
                return true;
            return false;
        }


        size_t String::size() const {
            return length_;
        }


        char *String::c_str() const {
            return storage_.get();
        }

        char *String::data() const {
            return storage_.get();
        }

        char String::at(std::size_t index) const {
            if (index > length_ - 1) {
                throw std::out_of_range("Out of range");
            }
            return *(storage_.get() + index);
        }


        char *String::begin() const {
            return storage_.get();
        }

        char *String::end() const {
            return begin() + size();
        }

        void String::append(const char *str) {
            size_t str_size = strlen(str);
            auto copy = new char[length_ + str_size + 1];
            std::copy(storage_.get(), storage_.get() + length_, copy);
            std::copy(str, str + str_size, copy + length_);
            copy[length_ + str_size] = '\0';
            length_ = length_ + str_size;
            storage_.reset(copy);
        }


        void String::append(const cppf::String &other) {
            auto str = other.c_str();
            this->append(str);
        }

        void String::append(const std::string &str) {
            this->append(str.c_str());
        }

        void String::append(char c) {
            char charArray[2] = {c};
            append(charArray);
        }

        void String::clear() {
            length_ = 0;
            if (storage_) {
                char *nullPointer = new char[1];
                nullPointer[0] = '\0';
                storage_.reset(nullPointer);
            }
        }


    } // cppf