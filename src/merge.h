#ifndef MERGE_H
#define MERGE_H

#include "data_frame.h"
#include "utils.h"

using namespace std;

namespace cs
{

DataFrame merge(DataFrame& df_1, DataFrame& df_2)
{
    DataFrame* df_1_ptr = &df_1;
    DataFrame* df_2_ptr = &df_2;

    vector<string> df_1_headers = df_1_ptr->getHeaders();
    vector<string> df_2_headers = df_2_ptr->getHeaders();

    assert(([=]() ->bool{
        for (auto header_1: df_1_headers){
            for (auto header_2: df_2_headers){
                if (header_1 == header_2) return false;
            }
        }
        return true;
    })() && "cs::merge error: Same header was detected.\n");


    size_t maxRow = max(df_1_ptr->getRowSize(), df_2_ptr->getRowSize());

    DataFrame new_df(df_1_ptr);

    for (auto header: df_2_headers){
        new_df.addCol(header);
    }

    for (size_t i=0 ; i<(maxRow - new_df.getRowSize()); ++i){
        addEmptyRow(new_df);
    }
    
    size_t newValue;
    size_t oldValue;
    
    for (size_t i=0; i<maxRow; ++i){
        for (auto header: df_2_headers){
            newValue = new_df.getHeaderValue(header);
            oldValue = df_2_ptr->getHeaderValue(header);
            new_df.dfIterator()[i][newValue] = df_2_ptr->dfIterator()[i][oldValue];
        }
    }

    return new_df;
}
    
} // namespace cs

#endif