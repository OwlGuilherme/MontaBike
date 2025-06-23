-- Criar todas as tabelas
CREATE TABLE categoria (
  id INTEGER PRIMARY KEY,
  nome TEXT UNIQUE NOT NULL
);

CREATE TABLE peca (
  id INTEGER PRIMARY KEY,
  nome TEXT NOT NULL,
  marca TEXT NOT NULL,
  modelo TEXT,
  categoria_id INTEGER NOT NULL,
  FOREIGN KEY (categoria_id) REFERENCES categoria(id)
);

CREATE TABLE especificacao (
  id INTEGER PRIMARY KEY,
  peca_id INTEGER NOT NULL,
  chave TEXT NOT NULL,
  valor TEXT,
  FOREIGN KEY (peca_id) REFERENCES peca(id)
);

CREATE TABLE oferta (
  id INTEGER PRIMARY KEY,
  peca_id INTEGER NOT NULL,
  site TEXT NOT NULL,
  preco REAL NOT NULL,
  data_catalogo DATE NOT NULL,
  link TEXT,
  FOREIGN KEY (peca_id) REFERENCES peca(id)
);

CREATE TABLE build (
  id INTEGER PRIMARY KEY,
  nome TEXT NOT NULL,
  data_criacao DATE NOT NULL
);

CREATE TABLE build_item (
  id INTEGER PRIMARY KEY,
  build_id INTEGER NOT NULL,
  peca_id INTEGER NOT NULL,
  oferta_id INTEGER,
  FOREIGN KEY (build_id) REFERENCES build(id),
  FOREIGN KEY (peca_id) REFERENCES peca(id),
  FOREIGN KEY (oferta_id) REFERENCES oferta(id)
);

