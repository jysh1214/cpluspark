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
#include <initializer_list>

using namespace std;

namespace cs
{

struct cvs_helper
{
    cvs_helper();
    cvs_helper(string);
    cvs_helper(cvs_helper& cvs_helper);

    virtual ~cvs_helper(){}

    cvs_helper& splitBy(const char split);
    cvs_helper& withDefaultHeaders();
    cvs_helper& withHeaders(initializer_list<string> list);
    DataFrame createDF();

    bool withHeads;
    string cvs_content;
    char split;

private:
    vector<string> customizedHeaders;
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