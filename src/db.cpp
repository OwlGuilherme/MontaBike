#include "db.hpp"
#include <iostream>

Database::Database(const std::string& path) {
    if (sqlite3_open(path.c_str(), &db)) {
        std::cerr << "Erro ao abrir o banco: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
}

Database::~Database() {
    if (db) sqlite3_close(db);
}

bool Database::criarTabelaPecas() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS peca (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL,
            marca TEXT NOT NULL,
            modelo TEXT,
            categoria_id INTEGER
        );
    )";

    char* errmsg;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela: " << errmsg << std::endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool Database::inserirPeca(const std::string& nome, const std::string& marca, const std::string& modelo, int categoria_id) {
    const char* sql = "INSERT INTO peca (nome, marca, modelo, categoria_id) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erro ao preparar statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, nome.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, marca.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, modelo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, categoria_id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao inserir peça: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
