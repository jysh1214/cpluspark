#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("../../data/task2.csv").splitBy(',').withDefaultHeaders().createDF();

    // dataframe iterator
    for(auto row: df.dfIterator()){
        std::cerr << row[0] << ",";
        std::cerr << row[1] << ",";
        std::cerr << row[2] << std::endl;
    }

    size_t userID = df.getHeaderValue("userID");
    size_t A = df.getHeaderValue("A");
    size_t B = df.getHeaderValue("B");
    // dataframe iterator
    for(auto row: df.dfIterator()){
        std::cerr << row[userID] << ",";
        std::cerr << row[A] << ",";
        std::cerr << row[B] << std::endl;
    }

    df.show(10);

    return 0;
}