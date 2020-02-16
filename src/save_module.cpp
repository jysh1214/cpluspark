#include "save_module.h"

using namespace cs;

save_csv_helper::save_csv_helper(DataFrame* df): df(df){}

save_csv_helper& save_csv_helper::splitBy(const char split)
{
    this->split = split;
    this->splitSetting = true;
    return *this;
}

void save_csv_helper::saveLocal(const char* savefile)
{
    assert(this->splitSetting &&
    "cs::save_csv_helper::saveLocal Error: Split char is not setted.\n");

    ofstream file(savefile);

    // write headers
    vector<string> headers = (this->df)->getHeaders();
    for (size_t i=0; i<headers.size(); ++i){
        file << headers[i];
        if (i != headers.size()-1) file << (this->split);
    }
    file << endl;

    // write table
    size_t col = (this->df)->getColSize();
    for (auto row: (this->df)->dfIterator()){
        for (size_t i=0; i<col; ++i){
            file << row[i];
            if (i != headers.size()-1) file << this->split;
        }
        file << endl;
    }
    
    file.close();
}

SaveModule::SaveModule(){}

SaveModule& SaveModule::saveDF(DataFrame& df)
{
    this->df = &df;
    return *this;
}

save_csv_helper SaveModule::asCVS()
{
    return save_csv_helper(this->df);
}