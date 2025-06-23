#include "db.hpp"
#include <iostream>
#include <exception>
#include <string>
#include <sqlite3.h>

int main() {
    Database db("data/mtb.db");

    if (!db.criarTabelaPecas()) {
        std::cerr << "Falha ao criar a tabela de peças." << std::endl;
        return 1;
    }

    std::string nome, marca, modelo, categoria_input;
    int categoria_id;

    std::cout << "Digite o nome da peça: ";
    std::getline(std::cin, nome);

    std::cout << "Digite a marca da peça: ";
    std::getline(std::cin, marca);

    std::cout << "Digite o modelo da peça (pode deixar em branco): ";
    std::getline(std::cin, modelo);

    std::cout << "Digite o ID da categoria (ex: 1 para Quadro, 2 para Suspensão): ";
    std::getline(std::cin, categoria_input);

    try {
        categoria_id = std::stoi(categoria_input);
    } catch (...) {
        std::cerr << "ID de categoria inválido. Use apenas números." << std::endl;
        return 1;
    }

    if (db.inserirPeca(nome, marca, modelo, categoria_id)) {
        std::cout << "Peça inserida com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao inserir a peça." << std::endl;
    }

    return 0;
}
