#ifndef CONCAT_H
#define CONCAT_H

#include "data_frame.h"

#include <set>
#include <iostream>

using namespace std;

namespace cs
{

DataFrame contact(DataFrame& df_1, DataFrame& df_2)
{
    DataFrame* df_1_ptr = &df_1;
    DataFrame* df_2_ptr = &df_2;

    vector<string> df_1_headers = df_1_ptr->getHeaders();
    vector<string> df_2_headers = df_2_ptr->getHeaders();
    
    set<string> set_1;
    set<string> set_2;

    for (auto header_1: df_1_headers) set_1.insert(header_1);
    for (auto header_2: df_2_headers) set_2.insert(header_2);

    assert((set_1 == set_2) && "cs::contact Error: Different header was detected.\n");

    DataFrame new_df(df_1_ptr);
    for (auto row: df_2_ptr->dfIterator()){
        new_df.addRow(row);
    }

    return new_df;
}

} // namespace cs

#endif