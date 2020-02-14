#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("../../data/task2.csv").splitBy(',').withDefaultHeaders().createDF();

    std::cerr << df.getMax<int>("A") << std::endl;
    std::cerr << df.getMin<int>("B") << std::endl;
    std::cerr << df.getAvg<float>("A") << std::endl;

    return 0;
}