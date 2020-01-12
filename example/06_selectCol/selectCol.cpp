#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("../../data/task2.csv").splitBy(',').withDefaultHeaders().createDF();
    df.show(10);
    cs::DataFrame new_df = df.selectCol({"A", "B"});
    new_df.show(10);

    return 0;
}