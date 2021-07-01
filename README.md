# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Documento de Especificação

Leia o documento de especificação contido em [Especificação do Trabalho 1](https://docs.google.com/document/d/1nwQxiP9YQzU3O-H4YQMqWRtylqO1AOke8y1rQF7cPEc/edit?usp=sharing). Preencha o autor.md com as informações relativas ao grupo/autor.


# KenoBet

**Keno é um jogo de apostas muito popular parecido com loteria ou bingo. Os jogadores apostam escolhendo entre 1 e 20 números únicos no intervalo entre 1 e 80, inclusive. Quando os jogadores escolhem seus números, o jogo gera vinte números aleatórios entre 1 e 80. Baseado na quantidade de números que o jogador acertou, e no valor que ele apostou, ele recebe um valor de volta.**

## 🖥️ Compilando o projeto
Para isso siga os comandos abaixo no seu terminal

```bash
# Cria um clone do projeto
git clone https://github.com/JulioMelo-Classes/trabalho-1-rafasfz.git

# Entra na pasta de build do projeto
cd trabalho-1-rafasfz/build

# Compila o projeto
cmake ..
make
```

## 🤖 Executando o projeto
Para isso siga o comando abaixo no seu terminal

```bash
# Executa o projeto
./keno {"nome do arquivo com as entradas"}
```

## Executando teste
```bash
# Executa o projeto no arquvio input.txt da pasta data na raiz do projeto
./keno ../data/input.txt
```


