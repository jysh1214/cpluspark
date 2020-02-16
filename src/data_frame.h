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

using namespace std;

namespace cs
{

class DataFrame
{
public:
    DataFrame();
    DataFrame(const DataFrame*);
    DataFrame(const DataFrame&);
    virtual ~DataFrame(){}

    void addHeaders(vector<string>& headers);
    void addRow(vector<string>& row);
    void addRow(Row& row);
    size_t getRowSize();
    size_t getColSize();
    vector<string> getHeaders();
    size_t getHeaderValue(const string header);
    vector<Row>& dfIterator();
    Row& getRow(size_t i);
    template<typename T> // std::string, int, float, double, long
    void sortBy(const string header, const char op);
    template<typename T> // std::string, int, float, double, long
    T getMax(const string header);
    template<typename T> // std::string, int, float, double, long
    T getMin(const string header);
    template<typename T> // int, float, double, long
    T getAvg(const string header);
    void addCol(const string newHeader);
    void removeCol(const string header);
    DataFrame selectCol(const initializer_list<string> list);
    void show();
    void show(size_t size);

    void resetHeadersMap();

private:
    map<string, size_t> headersMap;
    vector<string> headersVector;
    vector<Row> rowVector;
};

} // namespace cs

#endif