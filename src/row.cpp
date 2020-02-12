#include "row.h"

using namespace cs;

Row::Row(std::vector<std::string>& row): db_row(row){}

Row::Row(std::vector<std::string>&& row): db_row(row){}

std::string& Row::operator[](size_t i)
{
    return this->db_row[i];
}

size_t Row::size()
{
    return db_row.size();
}

void Row::push_back(std::string str)
{
    db_row.push_back(str);
}

void Row::print(size_t i)
{
    if (db_row[i].c_str() == nullptr || db_row[i].size() == 0){
        std::cerr << "null";
    }
    else{
        std::cerr << db_row[i];
    }
}

void Row::erase(size_t i)
{
    db_row.erase(db_row.begin() + i);
}