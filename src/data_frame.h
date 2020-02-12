#ifndef DATA_FRAME_H
#define DATA_FRAME_H

#include "row.h"
#include "visualization.h"

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
    DataFrame(const DataFrame*);
    DataFrame(const DataFrame&);
    virtual ~DataFrame(){}

    void addHeaders(std::vector<std::string>& headers);
    void addRow(std::vector<std::string>& row);
    size_t getRowSize();
    size_t getColSize();
    std::vector<std::string> getHeaders();
    size_t getHeaderValue(const std::string header);
    std::vector<Row>& dfIterator();
    template<typename T> // std::string, int, float, double, long
    void sortBy(const std::string header, const char op);
    template<typename T> // std::string, int, float, double, long
    T getMax(const std::string header);
    template<typename T> // std::string, int, float, double, long
    T getMin(const std::string header);
    template<typename T> // int, float, double, long
    T getAvg(const std::string header);
    void addCol(const std::string newHeader);
    void removeCol(const std::string header);
    DataFrame selectCol(const std::initializer_list<std::string> list);
    void show(size_t size);

private:
    std::map<std::string, size_t> headersMap;
    std::vector<std::string> headersVector;
    std::vector<Row> rowVector;
};

} // namespace cs

#endif