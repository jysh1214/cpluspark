#include "data_frame.h"

inline bool exist(std::string str, std::vector<std::string>& vec){
    for (auto item: vec){
        if (str == item) return true;
    }
    
    return false;
}

using namespace cs;

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

size_t DataFrame::getHeaderValue(const std::string header)
{
    return this->headersMap[header];
}

std::vector<Row>& DataFrame::dfIterator()
{
    return this->rowVector;
}

template<>
void DataFrame::sortBy<std::string>(const std::string header, const char op)
{
    assert((op == '<' || op == '>') &&
    "DataFrame::sortBy error: Use '<' or '>'.");

    size_t headerValue = this->headersMap[header];
    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){return lrow[headerValue] < rrow[headerValue];});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){return lrow[headerValue] > rrow[headerValue];});        
    }
}

template<>
void DataFrame::sortBy<int>(const std::string header, const char op)
{
    assert((op == '<' || op == '>') &&
    "DataFrame::sortBy error: Use '<' or '>'.");

    size_t headerValue = this->headersMap[header];
    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stoi(lrow[headerValue]) < std::stoi(rrow[headerValue]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stoi(lrow[headerValue]) > std::stoi(rrow[headerValue]);});        
    }
}

template<>
void DataFrame::sortBy<float>(const std::string header, const char op)
{
    assert((op == '<' || op == '>') &&
    "DataFrame::sortBy error: Use '<' or '>'.");

    size_t headerValue = this->headersMap[header];
    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stof(lrow[headerValue]) < std::stof(rrow[headerValue]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stof(lrow[headerValue]) > std::stof(rrow[headerValue]);});        
    }
}

template<>
void DataFrame::sortBy<double>(const std::string header, const char op)
{
    assert((op == '<' || op == '>') &&
    "DataFrame::sortBy error: Use '<' or '>'.");

    size_t headerValue = this->headersMap[header];
    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stod(lrow[headerValue]) < std::stod(rrow[headerValue]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stod(lrow[headerValue]) > std::stod(rrow[headerValue]);});        
    }
}

template<>
void DataFrame::sortBy<long>(const std::string header, const char op)
{
    assert((op == '<' || op == '>') &&
    "DataFrame::sortBy error: Use '<' or '>'.");

    size_t headerValue = this->headersMap[header];
    if (op == '<'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stol(lrow[headerValue]) < std::stol(rrow[headerValue]);});
    }
    else if (op == '>'){
        std::sort(this->rowVector.begin(), this->rowVector.end(), \
        [=](Row& lrow, Row& rrow){
            return std::stol(lrow[headerValue]) > std::stol(rrow[headerValue]);});        
    }
}

template<>
std::string DataFrame::getMax<std::string>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMax error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    std::string max = this->rowVector[0][headerValue];
    for (auto row: this->rowVector){
        max = row[headerValue] >= max ?
        row[headerValue] : max;
    }

    return max;
}

template<>
int DataFrame::getMax<int>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMax error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    int max = std::stoi(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        max = std::stoi(row[headerValue]) >= max ?
        std::stoi(row[headerValue]) : max;
    }

    return max;
}

template<>
float DataFrame::getMax<float>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMax error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    float max = std::stof(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        max = std::stof(row[headerValue]) >= max ?
        std::stof(row[headerValue]) : max;
    }

    return max;
}

template<>
double DataFrame::getMax<double>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMax error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    double max = std::stod(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        max = std::stod(row[headerValue]) >= max ?
        std::stod(row[headerValue]) : max;
    }

    return max;
}

template<>
long DataFrame::getMax<long>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMax error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    long max = std::stol(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        max = std::stol(row[headerValue]) >= max ?
        std::stol(row[headerValue]) : max;
    }

    return max;
}

template<>
std::string DataFrame::getMin<std::string>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMin error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    std::string min = this->rowVector[0][headerValue];
    for (auto row: this->rowVector){
        min = row[headerValue] <= min ?
        row[headerValue] : min;
    }

    return min;
}

template<>
int DataFrame::getMin<int>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMin error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    int min = std::stoi(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        min = std::stoi(row[headerValue]) <= min ?
        std::stoi(row[headerValue]) : min;
    }

    return min;
}

template<>
float DataFrame::getMin<float>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMin error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    float min = std::stof(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        min = std::stof(row[headerValue]) <= min ?
        std::stof(row[headerValue]) : min;
    }

    return min;
}

template<>
double DataFrame::getMin<double>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMin error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    float min = std::stod(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        min = std::stod(row[headerValue]) <= min ?
        std::stod(row[headerValue]) : min;
    }
    
    return min;
}

template<>
long DataFrame::getMin<long>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getMin error: Header does not exist.");

    size_t headerValue = this->headersMap[header];
    float min = std::stol(this->rowVector[0][headerValue]);
    for (auto row: this->rowVector){
        min = std::stol(row[headerValue]) <= min ?
        std::stol(row[headerValue]) : min;
    }
    
    return min;
}

template<>
int DataFrame::getAvg<int>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getAvg error: Header does not exist.");
    if (this->rowVector.size() == 0) return 0;

    size_t headerValue = this->headersMap[header];
    int sum = 0;
    for (Row row: this->rowVector){
        sum += std::stoi(row[headerValue]);
    }

    return int(sum/this->rowVector.size());
}

template<>
float DataFrame::getAvg<float>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getAvg error: Header does not exist.");
    if (this->rowVector.size() == 0) return 0;

    size_t headerValue = this->headersMap[header];
    float sum = 0;
    for (Row row: this->rowVector){
        sum += std::stof(row[headerValue]);
    }

    return float(sum/this->rowVector.size());
}

template<>
double DataFrame::getAvg<double>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getAvg error: Header does not exist.");
    if (this->rowVector.size() == 0) return 0;

    size_t headerValue = this->headersMap[header];
    double sum = 0;
    for (Row row: this->rowVector){
        sum += std::stod(row[headerValue]);
    }

    return double(sum/this->rowVector.size());
}

template<>
long DataFrame::getAvg<long>(const std::string header)
{
    assert(exist(header, this->headersVector) &&
    "DataFrame::getAvg error: Header does not exist.");
    if (this->rowVector.size() == 0) return 0;

    size_t headerValue = this->headersMap[header];
    long sum = 0;
    for (Row row: this->rowVector){
        sum += std::stol(row[headerValue]);
    }

    return long(sum/this->rowVector.size());
}

void DataFrame::addCol(const std::string newHeader)
{
    assert(([=]()-> bool{
        for (auto item: DataFrame::headersMap){
            if (item.first == newHeader) return false;
        } return true;
    })() && "DataFrame::addCol error: The header exist.");
    size_t headersMapSize = this->headersMap.size();
    size_t headersVectorSize = this->headersVector.size();
    size_t rowVectorSize = this->rowVector.size();

    this->headersMap[newHeader] = this->headersVector.size();
    this->headersVector.push_back(newHeader);

    for (Row& row: this->rowVector){
        row.push_back(std::string(""));
    }
    
    // postconditions
    assert(this->headersMap.size() == headersMapSize + 1);
    assert(this->headersVector.size() == headersVectorSize + 1);
    // invariants
    assert(this->rowVector.size() == rowVectorSize);
}

void DataFrame::removeCol(const std::string header)
{
    assert(([=]()-> bool{
        for (auto item: DataFrame::headersMap){
            if (item.first == header) return true;
        } return false;
    })() && "DataFrame::removeCol error: The header does not exist.");
    size_t headersMapSize = this->headersMap.size();
    size_t headersVectorSize = this->headersVector.size();
    size_t rowVectorSize = this->rowVector.size();

    int index = this->headersMap[header];
    this->headersVector.erase(this->headersVector.begin() + index);

    for (auto& row: this->rowVector){
        row.erase(index);
    }

    // reset headersMap
    this->headersMap.clear();
    int i = -1;
    for (auto header: this->headersVector){
        this->headersMap[header] = i += 1;
    }

    // postconditions
    assert(this->headersMap.size() == headersMapSize - 1);
    assert(this->headersVector.size() == headersVectorSize - 1);
    // invariants
    assert(this->rowVector.size() == rowVectorSize);
}

DataFrame DataFrame::selectCol(const std::initializer_list<std::string> list)
{
    // precondition
    assert(([=]()-> bool{
        for (auto item: list){
            if (!exist(item, this->headersVector))
                return false;
        }
        return true;
    })() && "DataFrame::selectCol error: The header does not exist.");
    size_t headersMapSize = this->headersMap.size();
    size_t headersVectorSize = this->headersVector.size();
    size_t rowVectorSize = this->rowVector.size();
    std::vector<std::string> list_vec = list;

    DataFrame new_df(this);
    for (auto header: this->headersVector){
        if (!exist(header, list_vec)){
            new_df.removeCol(header);
        }
    }

    // postconditions
    assert(new_df.getColSize() == list.size());
    assert(new_df.headersMap.size() == list.size());
    // invariants
    assert(new_df.getRowSize() == this->getRowSize());
    assert(this->headersMap.size() == headersMapSize);
    assert(this->headersVector.size() == headersVectorSize);
    assert(this->rowVector.size() == rowVectorSize);  

    return new_df;
}

void DataFrame::show(size_t size)
{
    assert((size <= this->rowVector.size()) && 
    "DataFrame::show error: Input size must <= dataframe size.");

    Visualization vis(this->headersVector, this->rowVector, size);
    vis.showTable();
}
