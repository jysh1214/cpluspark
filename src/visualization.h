#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "row.h"

#include <vector>
#include <string>

using namespace std;

namespace cs
{

class Visualization
{
public:
    Visualization(vector<string>& headersVector, vector<Row>& rowVector, size_t showNum);
    virtual ~Visualization(){}

    void showTable();

private:
    size_t MAX_SIZE = 10;
    vector<string>* headersPtr;
    vector<Row>* rowPtr;
    size_t showNum;
};

} // namespace cs

#endif