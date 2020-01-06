#ifndef PARSER_H
#define PARSER_H

#include "data_frame.h"

#include <assert.h>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <assert.h>
#include <string>
#include <vector>
#include <iostream>

namespace cs
{

struct cvs_helper
{
    cvs_helper();
    cvs_helper(std::string);
    cvs_helper(cvs_helper& cvs_helper);

    virtual ~cvs_helper(){}

    cvs_helper& splitBy(const char split);
    cvs_helper& withDefaultHeaders();
    DataFrame createDF();

    bool withHeads;
    std::string cvs_content;
    char split;

    private:
    bool headerSetting = false;
    bool splitSetting = false;
};

class Parser
{
    public:
    Parser();
    virtual ~Parser(){}

    cvs_helper readCVS(const char* filePath);
};

} // namespace cs

#endif