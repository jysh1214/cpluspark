#ifndef SAVE_MODULE_H
#define SAVE_MODULE_H

#include "data_frame.h"

#include <assert.h>
#include <fstream>

namespace cs
{

struct save_csv_helper
{
    save_csv_helper(DataFrame* df);
    virtual ~save_csv_helper(){}

    save_csv_helper& splitBy(const char split);
    void saveLocal(const char* savefile);

    DataFrame* df = nullptr;

private:
    char split;
    bool splitSetting = false;
};

class SaveModule
{
public:
    SaveModule();
    virtual ~SaveModule(){}

    SaveModule& saveDF(DataFrame& df);
    save_csv_helper asCVS();

private:
    DataFrame* df = nullptr;
};

} // namespace cs

#endif