#ifndef GPDB_PARQ_ADAPTOR
#define GPDB_PARQ_ADAPTOR

#include "postgres.h"

typedef struct List List;
typedef struct TupleTableSlot TupleTableSlot;
class ParquetTable;
class ParquetAdaptor
{
  public:
    static ParquetTable* createTable(char *relname, List *schema);
    static int insertRecord(TupleTableSlot *slot, char *relname);
    static int commit();
};
extern "C"
{
class ParquetTable;

extern int createParquetTable( char* relname, List *schema);
extern int insertParquetRecord(TupleTableSlot *slot, char *relname);
extern int parquetCommit();
}
#endif
