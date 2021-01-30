#pragma once
#include <unordered_map>
#include "parquetTable.h"

class TableManager
{
  public:
   static TableManager& getManager()
   {
      static TableManager mgr;
      return mgr;
   }

   ParquetTable* getTable(std::string &name);

   void addTable(ParquetTable &table);

   void commit();

   TableManager& operator =(const TableManager& rhs) = delete;
   TableManager(const TableManager& rhs) = delete;

  private:
   TableManager() = default;
   ~TableManager() = default;

   std::unordered_map<std::string, ParquetTable *> m;

};

