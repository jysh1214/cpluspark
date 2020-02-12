#ifndef ROW_H
#define ROW_H

#include <iostream>
#include <vector>
#include <string>

namespace cs
{

struct Row: public std::vector<std::string>
{
    Row(std::vector<std::string>& row);
    Row(std::vector<std::string>&& row);
    std::string& operator[](size_t i);
    std::string& operator[](std::string str);
    size_t size();
    void push_back(std::string str);
    void print(size_t i);
    void erase(size_t i);

    private:
    std::vector<std::string> db_row;
};

} // namespace cs

#endif