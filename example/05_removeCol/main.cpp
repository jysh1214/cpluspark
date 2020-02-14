#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("../../data/task2.csv").splitBy(',').withDefaultHeaders().createDF();

    df.removeCol("A");
    df.show(10);

    return 0;
}