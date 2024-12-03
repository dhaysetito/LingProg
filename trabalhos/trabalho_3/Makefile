# Nome do executável
EXEC = programa

# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -std=c++11

# Arquivos de código-fonte
SRCS = main.cpp disciplina.cpp historico.cpp

# Arquivos de cabeçalho
HEADERS = disciplina.h historico.h

# Geração dos arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Argumentos passados ao make run
#ARGS = $(filter-out $@,$(MAKECMDGOALS))
#ARGS = "grafo.txt"

# Regras para compilar o programa
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra genérica para compilar arquivos .cpp
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para rodar o programa após a compilação, usando argumentos
run: $(EXEC)
	./$(EXEC) 

# # Permitir que o make entenda "run" como um comando de alvo, mesmo com argumentos
# %:
# 	@: