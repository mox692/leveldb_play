#include <cassert>
#include <stdio.h>
#include <iostream>
#include "leveldb/db.h"

#define CHECK(s)                                \
    if (!s.ok())                                \
    {                                           \
        std::cout << s.ToString() << std::endl; \
        goto END;                               \
    }

int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    std::string val;

    // open
    leveldb::Status s = leveldb::DB::Open(options, "/tmp/testdb", &db);
    CHECK(s);
    std::cout << "DB open done." << std::endl;

    // put
    s = db->Put(leveldb::WriteOptions(), "motoyuki", "44");
    CHECK(s);

    // get
    s = db->Get(leveldb::ReadOptions(), "motoyuki", &val);
    CHECK(s);
    std::cout << "val is " + val << std::endl;

// delete
END:
    delete db;
    std::cout << "DB closing..." << std::endl;
    return 0;
}
