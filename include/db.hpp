#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& path);
    ~Database();

    bool criarTabelaPecas();
    bool inserirPeca(const std::string& nome, const std::string& marca, const std::string& modelo, int categoria_id);

private:
    sqlite3* db;
};

#endif
