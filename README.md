# Arkanoid 2D (C++ + Raylib)

**Disciplina:** Algoritmos e Programação II  
**Instituição:** Universidade do Vale do Itajaí - UNIVALI  
**Professor:** Welington Gadelha
**Alunos:** Lucca Antonio, Gustavo Hermes

---

## 📝 Sobre o Projeto

Este projeto consiste no desenvolvimento de um jogo **Arkanoid 2D** completo, desenvolvido em linguagem C++ utilizando a biblioteca gráfica **Raylib**. O jogo foi criado como parte da avaliação da disciplina, visando aplicar conceitos avançados de programação.

O jogador controla uma barra (*paddle*) que rebate uma bola para destruir blocos, coletar itens especiais e acumular pontos, com diferentes níveis de dificuldade.

## 🎯 Objetivos

Conforme os requisitos da disciplina, o objetivo principal deste projeto é aplicar de forma integrada os conceitos estudados, incluindo:
* Alocação dinâmica de memória.
* Uso de ponteiros e referências.
* Estruturas (`structs`).
* Manipulação de arquivos.
* Modularização do código.
* Lógica de colisão e física básica de jogos 2D.

## 🛠️ Bibliotecas Utilizadas

* **[Raylib](https://www.raylib.com/):** Biblioteca principal para renderização gráfica, gerenciamento de janelas, áudio e entrada de dados (mouse/teclado).
* **C++ Standard Library:**
    * `<iostream>` / `<cstdio>`: Entrada e saída padrão.
    * `<cstdlib>` / `<ctime>`: Geração de números aleatórios (`rand`, `srand`).
    * `<string>`: Manipulação de textos.
    * `<fstream>`: Manipulação de arquivos (leitura e escrita de ranking).

## 🎮 Controles e Regras

### Controles Básicos
* **Mouse:** Movimenta a barra (paddle) lateralmente.
* **Botão Esquerdo do Mouse:**
    * Interagir com os menus (Jogar, Dificuldade, Sair).
    * Lançar a bola no início da rodada ou após perder uma vida.
* **Teclas de Atalho (Dev/Debug):**
    * `E`: Sair do jogo.
    * `R`: Reiniciar blocos (se a bola não estiver em uso).
    * `Espaço` ou `Enter`: Confirmar nome na tela de Game Over.

### Regras do Jogo
1.  **Objetivo:** Destruir todos os blocos da tela sem deixar a bola cair abaixo da barra.
2.  **Vidas:** O jogador inicia com 3 vidas. Perde-se uma vida se a bola tocar a parte inferior da tela.
3.  **Blocos:** Existem blocos com diferentes resistências (cores diferentes) que exigem 1 ou mais toques para serem destruídos.
4.  **Dificuldade:**
    * **Fácil:** Velocidade padrão.
    * **Médio:** +25% de velocidade.
    * **Difícil:** +50% de velocidade.

### 🎁 Itens Especiais (Power-ups)
Ao destruir blocos específicos, itens podem cair. O jogador deve coletá-los com a barra para ativar o efeito temporário:

| Cor | Efeito |
| :--- | :--- |
| 🟦 **Azul** | **Velocidade:** Aumenta a velocidade da bola. |
| 🟥 **Vermelho** | **Força:** Aumenta o dano da bola (destrói blocos mais resistentes mais rápido). |
| 🟩 **Verde** | **Multi-Ball:** Adiciona uma segunda bola ao jogo. |
| 🟨 **Amarelo** | **Tamanho:** Aumenta a largura da barra do jogador. |

## 🚀 Como Compilar e Executar

Para rodar este projeto, é necessário ter um compilador C++ e a biblioteca Raylib configurada no seu ambiente.

**Exemplo de compilação via terminal (GCC/G++):**

```bash
g++ main.cpp -o arkanoid -lraylib -lGL -lm -lpthread -ldl -lrt
./arkanoid
