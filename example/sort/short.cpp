#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("../../data/task2.csv").splitBy(',').withDefaultHeaders().createDF();

    df.show(10);
    df.sortBy<std::string>("A", '<');
    df.show(10);

    df.sortBy<std::string>("A", '>');
    df.show(10);
    
    df.sortBy<int>("A", '<');
    df.show(10);

    df.sortBy<float>("A", '<');
    df.show(10);
    
    df.sortBy<double>("A", '<');
    df.show(10);

    df.sortBy<long>("A", '<');
    df.show(10);

    df.sortBy<int>("B", '<');
    df.show(10);

    return 0;
}