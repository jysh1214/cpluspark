#include "data_frame.h"

inline bool exist(std::string str, std::vector<std::string>& vec){
    for (auto item: vec){
        if (str == item) return true;
    }

    return false;
}

using namespace cs;

DataFrame::Row::Row(std::vector<std::string>& row): db_row(row){}

DataFrame::Row::Row(std::vector<std::string>&& row): db_row(row){}

std::string& DataFrame::Row::operator[](size_t i)
{
    // preconditions
    assert(i < DataFrame::headersMap.size());

    return this->db_row[i];
}

std::string& DataFrame::Row::operator[](std::string str)
{
    // preconditions
    assert(str.size() > 0);
    assert(str.c_str() != nullptr);
    assert(([=]()-> bool{ // valid header
        for (auto item: DataFrame::headersMap){
            // std::cerr << "match: " << str << "," <<item.first << std::endl;
            if (str == item.first) return true;
        } return false;
    })());

    // postconditions

    // invariants

    return this->db_row[DataFrame::headersMap[str]];
}

size_t DataFrame::Row::size()
{
    return db_row.size();
}

void DataFrame::Row::push_back(std::string str)
{
    db_row.push_back(str);
}

void DataFrame::Row::print(size_t i)
{
    if (db_row[i].c_str() == nullptr){
        std::cerr << "null";
    }
    else{
        std::cerr << db_row[i];
    }
}

void DataFrame::Row::erase(size_t i)
{
    db_row.erase(db_row.begin() + i);
}

DataFrame::DataFrame(){}

DataFrame::DataFrame(const DataFrame* old_df)
{
    for (auto item: old_df->headersMap)
        this->headersMap[item.first] = item.second;
    
    for (auto item: old_df->headersVector)
        this->headersVector.push_back(item);

    for (auto item: old_df->rowVector)
        this->rowVector.push_back(item);
}

DataFrame::DataFrame(const DataFrame& old_df)
{
    for (auto item: old_df.headersMap)
        this->headersMap[item.first] = item.second;
    
    for (auto item: old_df.headersVector)
        this->headersVector.push_back(item);

    for (auto item: old_df.rowVector)
        this->rowVector.push_back(item);
}

void DataFrame::addHeaders(std::vector<std::string>& headers)
{
    try{
        int i = -1;
        for (auto header: headers){
            this->headersVector.push_back(header);
            this->headersMap[header] = i += 1;
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void DataFrame::addRow(std::vector<std::string>& row)
{
    try{
        this->rowVector.push_back(Row(row));
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
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

std::vector<std::string> DataFrame::getHeaders()
{
    std::vector<std::string> templateVector = headersVector;
    return templateVector;
}

std::vector<DataFrame::Row>& DataFrame::dfIterator()
{
    return this->rowVector;
}

template<>
void DataFrame::sortBy<std::string>(std::string header, char op)
{
    // precondition
    assert(op == '<' || op == '>');

    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){return lrow[header] < rrow[header];});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){return lrow[header] > rrow[header];});        
    }
}

template<>
void DataFrame::sortBy<int>(std::string header, char op)
{
    // precondition
    assert(op == '<' || op == '>');

    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stoi(lrow[header]) < std::stoi(rrow[header]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stoi(lrow[header]) > std::stoi(rrow[header]);});        
    }
}

template<>
void DataFrame::sortBy<float>(std::string header, char op)
{
    // precondition
    assert(op == '<' || op == '>');

    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stof(lrow[header]) < std::stof(rrow[header]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stof(lrow[header]) > std::stof(rrow[header]);});        
    }
}

template<>
void DataFrame::sortBy<double>(std::string header, char op)
{
    // precondition
    assert(op == '<' || op == '>');

    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stod(lrow[header]) < std::stod(rrow[header]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stod(lrow[header]) > std::stod(rrow[header]);});        
    }
}

template<>
void DataFrame::sortBy<long>(std::string header, char op)
{
    // precondition
    assert(op == '<' || op == '>');

    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stol(lrow[header]) < std::stol(rrow[header]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stol(lrow[header]) > std::stol(rrow[header]);});        
    }
}

template<>
std::string DataFrame::getMax<std::string>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    std::string max = this->rowVector[0][header];
    for (auto row: this->rowVector){
        max = row[header] >= max ?
        row[header] : max;
    }
    return max;
}

template<>
int DataFrame::getMax<int>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    int max = std::stoi(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        max = std::stoi(row[header]) >= max ?
        std::stoi(row[header]) : max;
    }
    return max;
}

template<>
float DataFrame::getMax<float>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    float max = std::stof(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        max = std::stof(row[header]) >= max ?
        std::stof(row[header]) : max;
    }
    return max;
}

template<>
double DataFrame::getMax<double>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    double max = std::stod(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        max = std::stod(row[header]) >= max ?
        std::stod(row[header]) : max;
    }
    return max;
}

template<>
long DataFrame::getMax<long>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    long max = std::stol(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        max = std::stol(row[header]) >= max ?
        std::stol(row[header]) : max;
    }
    return max;
}

template<>
std::string DataFrame::getMin<std::string>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    std::string min = this->rowVector[0][header];
    for (auto row: this->rowVector){
        min = row[header] <= min ?
        row[header] : min;
    }
    return min;
}

template<>
int DataFrame::getMin<int>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    int min = std::stoi(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        min = std::stoi(row[header]) <= min ?
        std::stoi(row[header]) : min;
    }
    return min;
}

template<>
float DataFrame::getMin<float>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    float min = std::stof(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        min = std::stof(row[header]) <= min ?
        std::stof(row[header]) : min;
    }
    return min;
}

template<>
double DataFrame::getMin<double>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    double min = std::stod(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        min = std::stod(row[header]) <= min ?
        std::stod(row[header]) : min;
    }
    return min;
}

template<>
long DataFrame::getMin<long>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));

    long min = std::stol(this->rowVector[0][header]);
    for (auto row: this->rowVector){
        min = std::stol(row[header]) <= min ?
        std::stol(row[header]) : min;
    }
    return min;
}

template<>
int DataFrame::getAvg<int>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));
    assert(this->rowVector.size() > 0);

    int sum = 0;
    for (Row row: this->rowVector){
        sum += std::stoi(row[header]);
    }

    return int(sum/this->rowVector.size());
}

template<>
float DataFrame::getAvg<float>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));
    assert(this->rowVector.size() > 0);

    float sum = 0;
    for (Row row: this->rowVector){
        sum += std::stof(row[header]);
    }

    return float(sum/this->rowVector.size());
}

template<>
double DataFrame::getAvg<double>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));
    assert(this->rowVector.size() > 0);

    double sum = 0;
    for (Row row: this->rowVector){
        sum += std::stod(row[header]);
    }

    return double(sum/this->rowVector.size());
}

template<>
long DataFrame::getAvg<long>(std::string header)
{
    // precondition
    assert(exist(header, this->headersVector));
    assert(this->rowVector.size() > 0);

    long sum = 0;
    for (Row row: this->rowVector){
        sum += std::stol(row[header]);
    }

    return long(sum/this->rowVector.size());
}

void DataFrame::addCol(std::string newHeader)
{
    // precondition
    assert(([=]()-> bool{
        for (auto item: DataFrame::headersMap){
            if (item.first == newHeader) return false;
        } return true;
    })());

    this->headersMap[newHeader] = this->headersVector.size();
    this->headersVector.push_back(newHeader);

    for (Row& row: this->rowVector){
        row.push_back(std::string(""));
    }
}

void DataFrame::removeCol(std::string header)
{
    // precondition
    assert(([=]()-> bool{
        for (auto item: DataFrame::headersMap){
            if (item.first == header) return true;
        } return false;
    })());

    int index = this->headersMap[header];
    this->headersVector.erase(this->headersVector.begin() + index);

    for (auto& row: this->rowVector){
        row.erase(index);
    }

    this->headersMap.erase(header);
}

void DataFrame::show(size_t size)
{
    // precondition
    assert(size <= this->rowVector.size());

    using namespace std;
    size_t colSize = this->headersVector.size();

    for (size_t i=0; i<colSize; i++){
        cerr << this->headersVector[i];
        if (i != colSize-1) cerr << ",";
    }
    cerr << endl;

    for (size_t i=0; i<size; i++){
        for (size_t j=0; j<colSize; j++){
            this->rowVector[i].print(j);
            if (j != colSize-1) cerr << ",";
            else continue;
        }
        cerr << endl;
    }
}

std::map<std::string, size_t> DataFrame::headersMap;