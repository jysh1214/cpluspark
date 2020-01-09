#ifndef DATA_FRAME_H
#define DATA_FRAME_H

#include <algorithm>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <type_traits>
#include <initializer_list>

namespace cs
{

class DataFrame
{
public:
    DataFrame();
    virtual ~DataFrame(){}

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
    
    void addHeaders(std::vector<std::string>& headers);
    void addRow(std::vector<std::string>& row);
    size_t getRowSize();
    size_t getColSize();
    std::vector<std::string> getHeaders();
    std::vector<Row>& dfIterator();
    template<typename T> // std::string, int, float, double, long
    void sortBy(std::string header, char op);
    template<typename T> // std::string, int, float, double, long
    T getMax(std::string header);
    template<typename T> // std::string, int, float, double, long
    T getMin(std::string header);
    template<typename T> // int, float, double, long
    T getAvg(std::string header);
    void addCol(std::string newHeader);
    DataFrame select(std::initializer_list<std::string> list);
    void removeCol(std::string header);

    void show(size_t size);

    static std::map<std::string, size_t> headersMap;

private:
    std::vector<std::string> headersVector;
    std::vector<Row> rowVector;
};

} // namespace cs

#endif