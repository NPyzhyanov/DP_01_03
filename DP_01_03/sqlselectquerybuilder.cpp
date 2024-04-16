#include <string>
#include <vector>
#include <map>

#include "sqlselectquerybuilder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder()
{
    select_statement_as_default = true;
    from_statement_got = false;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string column_name)
{
    if (column_name.empty())
    {
        return *this;
    }
    
    select_statement += (select_statement.empty() ? column_name : ", " + column_name);
    select_statement_as_default = false;
    
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string> &columns) noexcept
{
    if (columns.begin() == columns.end())
    {
        return *this;
    }
    
    for (auto word : columns)
    {
        this->AddColumn(word);
    }
    
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string table_name)
{
    from_statement = table_name;
    from_statement_got = true;
    
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string condition_l_value, std::string condition_r_value)
{
    if (condition_l_value.empty() || condition_r_value.empty())
    {
        return *this;
    }
    
    std::string full_condition = condition_l_value + "=" + condition_r_value;
    where_condition += (where_condition.empty() ? full_condition : " AND " + full_condition);
    
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string> &kv) noexcept
{
    if (kv.begin() == kv.end())
    {
        return *this;
    }
    
    for (auto [l_val, r_val] : kv)
    {
        this->AddWhere(l_val, r_val);
    }
    
    return *this;
}

const std::string SqlSelectQueryBuilder::BuildQuery()
{
    if (!from_statement_got)
    {
        return "";
    }
    
    if (select_statement_as_default)
    {
        select_statement = default_select_statement;
    }
    
    std::string necessary_part = "SELECT " + select_statement + " FROM " + from_statement;
    std::string optional_part = "";
    if (!where_condition.empty())
    {
        optional_part = " WHERE " + where_condition;
    }
    
    return necessary_part + optional_part + ";";
}
