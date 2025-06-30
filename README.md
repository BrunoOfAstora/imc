# Projeto: Calculadora de IMC (C & Python)
Projeto por: Bruno Silva Ferreira

Este projeto apresenta duas implementações de uma Calculadora de Índice de Massa Corporal (IMC), cada uma desenvolvida com uma tecnologia diferente para demonstrar abordagens distintas para a criação de aplicações.

## Descrição

O objetivo principal é calcular o IMC de um usuário com base em seu peso e altura (em centímetros).

O projeto inclui:
1.  **Uma aplicação em C**, construída com a biblioteca `raylib` para uma interface visual simples e direta, ou de forma alternativa, uma aplicação em CLI.
  
2.  **Uma aplicação em Python**, que pode ser executada tanto com uma interface gráfica (GUI) quanto por linha de comando (CLI).

##  Funcionalidades

-   Cálculo preciso do IMC.
-   Entrada de peso em kilos (ex: `75`) e altura em centímetros (ex: `183`).
-   Exibição da classificação do IMC (Abaixo do peso, Peso normal, Sobrepeso, etc.).
-   Duas interfaces distintas para a mesma funcionalidade (Uma em GUI, outra em CLI).

---

##  Tecnologias Utilizadas (GUI)

-   **Linguagens:** C, Python 3
-   **Biblioteca Gráfica (C):** `raylib` e `raygui`
-   **Toolkit (Python)**: `tkinter`

---

## ⚙ Instalação e Execução

Primeiro, clone o repositório para a sua máquina local:
```bash
git clone https://github.com/BrunoOfAstora/imc
cd imc
```
### 1. Calculadora em Python (GUI e CLI)
**Como Rodar**
Basta clonar o repositorio, ir até a pasta que acabou de clonar e rodar com:
```bash
python calculadora_imc.py 
```
## OU
```bash
python calculadora_imc.py --cli
```
Para rodar em modo CLI.

### 2. Calculadora em C (GUI)

**Compilação:**
Vá até a pasta que acabou de clonar e compile com:
```bash
gcc imc_c.c -o imc_gui -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```
## Ou para a aplicação em CLI:
Basta fazer uma compilação padrão:
```bash
gcc imc_c_cli.c -o imc_cli_c
```

**Execução:**
Após a compilação, execute o programa:
```bash
./imc_gui
```


