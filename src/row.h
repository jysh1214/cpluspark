#ifndef ROW_H
#define ROW_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace cs
{

struct Row: public vector<string>
{
    Row(vector<string>& row);
    Row(vector<string>&& row);
    string& operator[](size_t i);
    size_t size();
    void push_back(string str);
    void print(size_t i);
    void erase(size_t i);

    private:
    vector<string> db_row;
};

} // namespace cs

#endif