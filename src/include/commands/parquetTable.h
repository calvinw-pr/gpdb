#pragma once
#include <vector>
#include <memory>
#include <arrow/type.h>
#include <arrow/stl.h>
class ParquetTable
{
  public:
    static ParquetTable* create(char* relname, std::vector<std::shared_ptr<arrow::Field>> &fields);

    virtual ~ParquetTable() = 0;

    virtual int insert( std::vector<std::shared_ptr<arrow::Array>> &data ) = 0;

    virtual int insertColumn(void* value) = 0;

    virtual std::string getName() const = 0;

    virtual void persist() = 0;
};

