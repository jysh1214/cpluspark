#include "visualization.h"

using namespace cs;

inline void renderSplitLine(size_t col, int* colMaxSize)
{
    for (size_t i=0; i<col; ++i){
        cerr << "+";
        for (int len=0; len<colMaxSize[i]; ++len){
            cerr << "-";
        }
    }
    cerr << "+" << endl;
}

Visualization::Visualization(vector<string>& headersVector, vector<Row>& rowVector, size_t showNum)
{
    this->headersPtr = &headersVector;
    this->rowPtr = &rowVector;
    this->showNum = showNum;
}

void Visualization::showTable()
{
    // record column max length
    size_t col = headersPtr->size();
    int* colMaxSize = (int*) new int[col];
    int count = 0;

    for (vector<string>::iterator it=headersPtr->begin(); it!=headersPtr->end(); ++it){
        colMaxSize[count] = ((*it).size() > MAX_SIZE)? MAX_SIZE: (*it).size();
        ++count;
    }

    for (size_t i=0; i<showNum; ++i){
        for (size_t c=0; c<col; ++c){
            colMaxSize[c] = (rowPtr[c].size() > MAX_SIZE)? MAX_SIZE: rowPtr[c].size();
        } // for each item of row
    } // for each row

    // render
    renderSplitLine(col, colMaxSize);

    vector<string>::iterator it=headersPtr->begin();
    for (size_t i=0; i<col; ++i){
            cerr << "|";
            if ((*it).size() > MAX_SIZE){
                cerr << (*it).substr(0, 7) + "...";
            }
            else {
                cerr << (*it);
                // fill space
                for (int j=0; j<(colMaxSize[i]-(int)(*it).size()); ++j) 
                    cerr << " "; 
            }
            ++it;
    }
    cerr << "|" << endl;

    renderSplitLine(col, colMaxSize);

    delete colMaxSize;
}
