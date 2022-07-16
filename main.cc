#include <cassert>
#include <stdio.h>
#include <iostream>
#include "leveldb/db.h"

int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
    std::cout << "hello from leveldb4!!" << std::endl;
    return 0;
}
