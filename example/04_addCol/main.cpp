#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("../../data/task2.csv").splitBy(',').withDefaultHeaders().createDF();

    df.addCol("C");
    df.show(10);

    size_t userID = df.getHeaderValue("userID");
    size_t A = df.getHeaderValue("A");
    size_t B = df.getHeaderValue("B");
    size_t C = df.getHeaderValue("C");

    for(auto& row: df.dfIterator()){
        row[C] = std::to_string(std::stoi(row[A]) +  std::stoi(row[B]));
    }

    df.show(10);

    return 0;
}