#include "../../include/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df_1 = p.readCVS("../../data/123.txt").splitBy(',').withDefaultHeaders().createDF();
    df_1.show();

    cs::DataFrame df_2 = p.readCVS("../../data/123.txt").splitBy(',').withDefaultHeaders().createDF();
    df_2.show();

    cs::DataFrame new_df = cs::contact(df_1, df_2);
    new_df.show();

    return 0;
}