#include "parser.h"

using namespace cs;

cvs_helper::cvs_helper(){}

cvs_helper::cvs_helper(std::string str): cvs_content(str){}

cvs_helper::cvs_helper(cvs_helper& cvs_helper)
{
    this->cvs_content = cvs_helper.cvs_content;
}

cvs_helper& cvs_helper::splitBy(const char split)
{
    this->split = split;
    this->splitSetting = true;
    return *this;
}

cvs_helper& cvs_helper::withDefaultHeaders()
{
    this->withHeads = true;
    this->headerSetting = true;
    return *this;
}

cvs_helper& cvs_helper::withHeaders(std::initializer_list<std::string> list)
{
    for (std::string header: list)
        this->customizedHeaders.push_back(header);

    this->withHeads = false;
    this->headerSetting = true;
    return *this;
}

DataFrame cvs_helper::createDF()
{
    // precondition
    assert(this->splitSetting && this->headerSetting);

    using namespace std;
    
    DataFrame df;
    // customized headers
    if (!this->withHeads){
        df.addHeaders(this->customizedHeaders);
    }
    int current_point = 0;
    vector<string> row;
    for (string::size_type i = 0; i <= this->cvs_content.size(); ++i){
        if (cvs_content[i] == this->split || cvs_content[i] == '\n' || i == cvs_content.size()){
            string item = cvs_content.substr(current_point, i-current_point);
            current_point = i + 1;
            if (item.size() > 0) row.push_back(item);
        }
        // get headers in first line
        if (this->withHeads && cvs_content[i] == '\n'){
            df.addHeaders(row);
            row.clear();
            this->withHeads = false;
        }
        if (cvs_content[i] == '\n' || i == cvs_content.size()){
            if (row.size() > 0){
                df.addRow(row);
                row.clear();
            }
        }
    } // read whole csv file

    return df;
}

Parser::Parser(){}

cvs_helper Parser::readCVS(const char* filePath)
{
    using namespace std;

    struct stat _st;
    // precondition
    assert(lstat(filePath, &_st) != -1);

    string fileName(filePath);
    if(fileName.substr(fileName.size()-4, 4) != ".csv"){
        cerr << "Warnning: ";
        cerr << filePath;
        cerr << " is not a .csv file." << endl;
    }

    ifstream cvsFile(filePath);
    string content((istreambuf_iterator<char>(cvsFile)),
                    istreambuf_iterator<char>());
    cvsFile.close();

    return cvs_helper(content);
}