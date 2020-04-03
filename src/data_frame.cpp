#include "data_frame.h"

inline bool exist(string str, vector<string> &vec)
{
    for (auto item : vec)
    {
        if (str == item)
            return true;
    }

    return false;
}

using namespace cs;

DataFrame::DataFrame() {}

DataFrame::DataFrame(const DataFrame *old_df)
{
    for (auto item : old_df->headersMap)
        this->headersMap[item.first] = item.second;

    for (auto item : old_df->headersVector)
        this->headersVector.push_back(item);

    for (auto item : old_df->rowVector)
        this->rowVector.push_back(item);
}

DataFrame::DataFrame(const DataFrame &old_df)
{
    for (auto item : old_df.headersMap)
        this->headersMap[item.first] = item.second;

    for (auto item : old_df.headersVector)
        this->headersVector.push_back(item);

    for (auto item : old_df.rowVector)
        this->rowVector.push_back(item);
}

void DataFrame::addHeaders(vector<string> &headers)
{
    try
    {
        size_t i = 0;
        for (auto header : headers)
        {
            this->headersVector.push_back(header);
            this->headersMap[header] = i;
            ++i;
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

void DataFrame::addRow(vector<string> &row)
{
    try
    {
        this->rowVector.push_back(Row(row));
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

void DataFrame::addRow(Row &row)
{
    try
    {
        this->rowVector.push_back(row);
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

size_t DataFrame::getRowSize()
{
    return this->rowVector.size();
}

size_t DataFrame::getColSize()
{
    return this->headersVector.size();
}

vector<string> DataFrame::getHeaders()
{
    vector<string> templateVector = headersVector;
    return templateVector;
}

size_t DataFrame::getHeaderValue(const string header)
{
    return this->headersMap[header];
}

vector<Row> &DataFrame::dfIterator()
{
    return this->rowVector;
}

Row &DataFrame::getRow(size_t i)
{
    return this->rowVector[i];
}

template <>
void DataFrame::sortBy<string>(const string header, const char op)
{
    assert((op == '<' || op == '>') &&
           "DataFrame::sortBy Error: Use '<' or '>'.");

    size_t headerValue = this->headersMap[header];
    if (op == '<')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return lrow[headerValue] < rrow[headerValue]; });
    }
    else if (op == '>')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return lrow[headerValue] > rrow[headerValue]; });
    }
}

template <>
void DataFrame::sortBy<int>(const string header, const char op)
{
    assert((op == '<' || op == '>') &&
           "cs::DataFrame::sortBy Error: Use '<' or '>'.\n");

    size_t headerValue = this->headersMap[header];
    if (op == '<')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stoi(lrow[headerValue]) < stoi(rrow[headerValue]); });
    }
    else if (op == '>')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stoi(lrow[headerValue]) > stoi(rrow[headerValue]); });
    }
}

template <>
void DataFrame::sortBy<float>(const string header, const char op)
{
    assert((op == '<' || op == '>') &&
           "cs::DataFrame::sortBy Error: Use '<' or '>'.\n");

    size_t headerValue = this->headersMap[header];
    if (op == '<')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stof(lrow[headerValue]) < stof(rrow[headerValue]); });
    }
    else if (op == '>')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stof(lrow[headerValue]) > stof(rrow[headerValue]); });
    }
}

template <>
void DataFrame::sortBy<double>(const string header, const char op)
{
    assert((op == '<' || op == '>') &&
           "cs::DataFrame::sortBy Error: Use '<' or '>'.\n");

    size_t headerValue = this->headersMap[header];
    if (op == '<')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stod(lrow[headerValue]) < stod(rrow[headerValue]); });
    }
    else if (op == '>')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stod(lrow[headerValue]) > stod(rrow[headerValue]); });
    }
}

template <>
void DataFrame::sortBy<long>(const string header, const char op)
{
    assert((op == '<' || op == '>') &&
           "cs::DataFrame::sortBy Error: Use '<' or '>'.\n");

    size_t headerValue = this->headersMap[header];
    if (op == '<')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stol(lrow[headerValue]) < stol(rrow[headerValue]); });
    }
    else if (op == '>')
    {
        sort(this->rowVector.begin(), this->rowVector.end(),
             [=](Row &lrow, Row &rrow) { return stol(lrow[headerValue]) > stol(rrow[headerValue]); });
    }
}

template <>
string DataFrame::getMax<string>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMax Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    string max = this->rowVector[0][headerValue];
    for (auto row : this->rowVector)
    {
        max = row[headerValue] >= max ? row[headerValue] : max;
    }

    return max;
}

template <>
int DataFrame::getMax<int>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMax Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    int max = stoi(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        max = stoi(row[headerValue]) >= max ? stoi(row[headerValue]) : max;
    }

    return max;
}

template <>
float DataFrame::getMax<float>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMax Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    float max = stof(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        max = stof(row[headerValue]) >= max ? stof(row[headerValue]) : max;
    }

    return max;
}

template <>
double DataFrame::getMax<double>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMax Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    double max = stod(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        max = stod(row[headerValue]) >= max ? stod(row[headerValue]) : max;
    }

    return max;
}

template <>
long DataFrame::getMax<long>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMax Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    long max = stol(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        max = stol(row[headerValue]) >= max ? stol(row[headerValue]) : max;
    }

    return max;
}

template <>
string DataFrame::getMin<string>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMin Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    string min = this->rowVector[0][headerValue];
    for (auto row : this->rowVector)
    {
        min = row[headerValue] <= min ? row[headerValue] : min;
    }

    return min;
}

template <>
int DataFrame::getMin<int>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMin Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    int min = stoi(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        min = stoi(row[headerValue]) <= min ? stoi(row[headerValue]) : min;
    }

    return min;
}

template <>
float DataFrame::getMin<float>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMin Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    float min = stof(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        min = stof(row[headerValue]) <= min ? stof(row[headerValue]) : min;
    }

    return min;
}

template <>
double DataFrame::getMin<double>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMin Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    float min = stod(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        min = stod(row[headerValue]) <= min ? stod(row[headerValue]) : min;
    }

    return min;
}

template <>
long DataFrame::getMin<long>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getMin Error: Header does not exist.\n");

    size_t headerValue = this->headersMap[header];
    float min = stol(this->rowVector[0][headerValue]);
    for (auto row : this->rowVector)
    {
        min = stol(row[headerValue]) <= min ? stol(row[headerValue]) : min;
    }

    return min;
}

template <>
int DataFrame::getAvg<int>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getAvg Error: Header does not exist.\n");
    if (this->rowVector.size() == 0)
        return 0;

    size_t headerValue = this->headersMap[header];
    int sum = 0;
    for (Row row : this->rowVector)
    {
        sum += stoi(row[headerValue]);
    }

    return int(sum / this->rowVector.size());
}

template <>
float DataFrame::getAvg<float>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getAvg Error: Header does not exist.\n");
    if (this->rowVector.size() == 0)
        return 0;

    size_t headerValue = this->headersMap[header];
    float sum = 0;
    for (Row row : this->rowVector)
    {
        sum += stof(row[headerValue]);
    }

    return float(sum / this->rowVector.size());
}

template <>
double DataFrame::getAvg<double>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getAvg Error: Header does not exist.\n");
    if (this->rowVector.size() == 0)
        return 0;

    size_t headerValue = this->headersMap[header];
    double sum = 0;
    for (Row row : this->rowVector)
    {
        sum += stod(row[headerValue]);
    }

    return double(sum / this->rowVector.size());
}

template <>
long DataFrame::getAvg<long>(const string header)
{
    assert(exist(header, this->headersVector) &&
           "cs::DataFrame::getAvg Error: Header does not exist.\n");
    if (this->rowVector.size() == 0)
        return 0;

    size_t headerValue = this->headersMap[header];
    long sum = 0;
    for (Row row : this->rowVector)
    {
        sum += stol(row[headerValue]);
    }

    return long(sum / this->rowVector.size());
}

void DataFrame::addCol(const string newHeader)
{
    assert(([=]() -> bool {
               for (auto item : DataFrame::headersMap)
               {
                   if (item.first == newHeader)
                       return false;
               }
               return true;
           })() &&
           "cs::DataFrame::addCol Error: The header exist.\n");
    size_t headersMapSize = this->headersMap.size();
    size_t headersVectorSize = this->headersVector.size();
    size_t rowVectorSize = this->rowVector.size();

    this->headersMap[newHeader] = this->headersVector.size();
    this->headersVector.push_back(newHeader);

    for (Row &row : this->rowVector)
    {
        row.push_back(string(""));
    }

    assert(this->headersMap.size() == headersMapSize + 1);
    assert(this->headersVector.size() == headersVectorSize + 1);
    assert(this->rowVector.size() == rowVectorSize);
}

void DataFrame::removeCol(const string header)
{
    assert(([=]() -> bool {
               for (auto item : DataFrame::headersMap)
               {
                   if (item.first == header)
                       return true;
               }
               return false;
           })() &&
           "cs::DataFrame::removeCol Error: The header does not exist.\n");
    size_t headersMapSize = this->headersMap.size();
    size_t headersVectorSize = this->headersVector.size();
    size_t rowVectorSize = this->rowVector.size();

    int index = this->headersMap[header];
    this->headersVector.erase(this->headersVector.begin() + index);

    for (auto &row : this->rowVector)
    {
        row.erase(index);
    }

    // reset headersMap
    this->headersMap.clear();
    size_t i = 0;
    for (auto header : this->headersVector)
    {
        this->headersMap[header] = i;
        ++i;
    }

    assert(this->headersMap.size() == headersMapSize - 1);
    assert(this->headersVector.size() == headersVectorSize - 1);
    assert(this->rowVector.size() == rowVectorSize);
}

DataFrame DataFrame::selectCol(const initializer_list<string> list)
{
    assert(([=]() -> bool {
               for (auto item : list)
               {
                   if (!exist(item, this->headersVector))
                       return false;
               }
               return true;
           })() &&
           "cs::DataFrame::selectCol Error: The header does not exist.\n");
    vector<string> list_vec = list;

    DataFrame new_df(this);
    for (auto header : this->headersVector)
    {
        if (!exist(header, list_vec))
        {
            new_df.removeCol(header);
        }
    }

    assert(new_df.getColSize() == list.size());
    assert(new_df.headersMap.size() == list.size());
    assert(new_df.getRowSize() == this->getRowSize());

    return new_df;
}

void DataFrame::show()
{
    size_t size = (10 > this->rowVector.size()) ? this->rowVector.size() : 10;

    Visualization vis(this->headersVector, this->rowVector, size);
    vis.showTable();
}

void DataFrame::show(size_t size)
{
    assert((size <= this->rowVector.size()) &&
           "cs::DataFrame::show Error: Input size must <= dataframe size.\n");

    Visualization vis(this->headersVector, this->rowVector, size);
    vis.showTable();
}

void DataFrame::resetHeadersMap()
{
    this->headersMap.clear();
    size_t i = 0;
    for (auto header : this->headersVector)
    {
        this->headersMap[header] = i;
        ++i;
    }
}
