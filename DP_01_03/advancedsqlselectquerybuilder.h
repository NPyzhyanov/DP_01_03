#ifndef ADVANCEDSQLSELECTQUERYBUILDER_H
#define ADVANCEDSQLSELECTQUERYBUILDER_H

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
{
public:
    SqlSelectQueryBuilder& AddWhere(std::string condition_l_value, std::string condition_r_value) override;
    SqlSelectQueryBuilder& AddWhereMore(std::string condition_l_value, std::string condition_r_value);
    SqlSelectQueryBuilder& AddWhereLess(std::string condition_l_value, std::string condition_r_value);
    
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string> &kv) noexcept override;
    SqlSelectQueryBuilder& AddWhereMore(const std::map<std::string, std::string> &kv) noexcept;
    SqlSelectQueryBuilder& AddWhereLess(const std::map<std::string, std::string> &kv) noexcept;
    
    
private:
    SqlSelectQueryBuilder& AddWhereCommon(std::string condition_l_value, std::string condition_r_value, const char operator_);
    SqlSelectQueryBuilder& AddWhereCommon(const std::map<std::string, std::string> &kv, const char operator_) noexcept;
    
};

#endif // ADVANCEDSQLSELECTQUERYBUILDER_H
