#include "visualization.h"

using namespace cs;

inline void drawSplitLine(size_t col, int* colMaxSize)
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

    size_t showTimes = 0;
    for (vector<Row>::iterator it=rowPtr->begin(); it!=rowPtr->end(); ++it){
        for (size_t i=0; i<col; ++i){
            if ((int)(*it)[i].size() > colMaxSize[i])
                colMaxSize[i] = ((*it)[i].size() > MAX_SIZE)? MAX_SIZE: (*it)[i].size();
        } // fro each row item
        ++showTimes;
        if (showTimes == showNum) break;
    }

    drawSplitLine(col, colMaxSize);
    // headers
    vector<string>::iterator it = headersPtr->begin();
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

    drawSplitLine(col, colMaxSize);

    // content
    showTimes = 0;
    for (vector<Row>::iterator it=rowPtr->begin(); it!=rowPtr->end(); ++it){
        for (size_t i=0; i<col; ++i){
                cerr << "|";
                if ((*it)[i].size() > MAX_SIZE){
                    cerr << (*it)[i].substr(0, 7) + "...";
                }
                else {
                    cerr << (*it)[i];
                    // fill space
                    for (int j=0; j<(colMaxSize[i]-(int)(*it)[i].size()); ++j) 
                        cerr << " "; 
                }
        }
        cerr << "|" << endl;
        ++showTimes;
        if (showTimes == showNum) break;
    }

    drawSplitLine(col, colMaxSize);

    delete colMaxSize;
}
