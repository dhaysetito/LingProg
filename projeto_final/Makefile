# Nome do executável
EXEC = build/programa

# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -std=c++11 -Iinclude

# Diretórios
SRC_DIR = src/cpp
INCLUDE_DIR = include
BUILD_DIR = build

# Arquivos de código-fonte
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/diario.cpp $(SRC_DIR)/pagina.cpp

# Arquivos de cabeçalho
HEADERS = $(INCLUDE_DIR)/pagina.h $(INCLUDE_DIR)/diario.h

# Geração dos arquivos objeto (coloca os .o na pasta build)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Regras para compilar o programa
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra genérica para compilar arquivos .cpp (salva .o na pasta build)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	mkdir -p $(BUILD_DIR)  
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
	rm -rf $(BUILD_DIR)

# Regra para rodar o programa após a compilação
run: $(EXEC)
	./$(EXEC)
