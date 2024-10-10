#Nome do executável
EXEC = MonitoramentoAtleta

# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -std=c++11

# Arquivos de código-fonte
SRCS = main.cpp atleta.cpp treinador.cpp

# Arquivos de cabeçalho
HEADERS = atleta.h treinador.h

# Geração dos arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regras para compilar o programa
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra genérica para compilar arquivos .cpp
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para rodar o programa após a compilação
run: $(EXEC)
	./$(EXEC)
