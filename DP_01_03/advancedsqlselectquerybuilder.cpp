#include <string>
#include <vector>
#include <map>

#include "sqlselectquerybuilder.h"
#include "advancedsqlselectquerybuilder.h"

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhere(std::string condition_l_value, std::string condition_r_value)
{
    this->AddWhereCommon(condition_l_value, condition_r_value, '=');
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereMore(std::string condition_l_value, std::string condition_r_value)
{
    this->AddWhereCommon(condition_l_value, condition_r_value, '>');
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLess(std::string condition_l_value, std::string condition_r_value)
{
    this->AddWhereCommon(condition_l_value, condition_r_value, '<');
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereCommon(std::string condition_l_value, std::string condition_r_value, const char operator_)
{
    if (condition_l_value.empty() || condition_r_value.empty())
    {
        return *this;
    }
    
    std::string str(1, operator_);
    std::string full_condition = condition_l_value + str + condition_r_value;
    where_condition += (where_condition.empty() ? full_condition : " AND " + full_condition);
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string> &kv) noexcept
{
    this->AddWhereCommon(kv, '=');
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereMore(const std::map<std::string, std::string> &kv) noexcept
{
    this->AddWhereCommon(kv, '>');
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLess(const std::map<std::string, std::string> &kv) noexcept
{
    this->AddWhereCommon(kv, '<');
    
    return *this;
}

SqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereCommon(const std::map<std::string, std::string> &kv, const char operator_) noexcept
{
    if (kv.begin() == kv.end())
    {
        return *this;
    }
    
    for (auto [l_val, r_val] : kv)
    {
        this->AddWhereCommon(l_val, r_val, operator_);
    }
    
    return *this;
}
