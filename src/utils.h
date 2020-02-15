#ifndef UTILS_H
#define UTILS_H

namespace cs
{

inline void addEmptyRow(DataFrame& df)
{
    vector<string> row;
    for (size_t i=0; i<df.getColSize(); ++i){
        row.push_back("");
    }

    df.addRow(row);
}

}

#endif