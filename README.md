# Semáforo com Raspberry Pi Pico 🚦

Este projeto implementa um sistema de controle de semáforo utilizando o **Raspberry Pi Pico W**. O código controla três LEDs (vermelho, amarelo e verde), simulando o funcionamento de um semáforo real.

## 📋 **Funcionalidades**

- Alternância entre LEDs vermelho, amarelo e verde.
- Temporização controlada por interrupções de hardware.
- Mensagens no terminal indicando o tempo decorrido.

## 🚀 **Como Funciona**

O sistema utiliza um **temporizador de repetição** para alternar o estado dos LEDs a cada 3 segundos:

- **LED Vermelho** acende por 3 segundos.
- **LED Amarelo** acende por 3 segundos.
- **LED Verde** acende por 3 segundos.

Enquanto isso, o terminal exibe "Passou 1 segundo" a cada segundo, além de uma mensagem indicando a troca dos LEDs.

## 🧰 **Requisitos**

- **Raspberry Pi Pico**
- LEDs (vermelho, amarelo e verde)
- Resistores de 330Ω (para limitar a corrente dos LEDs)
- SDK do Raspberry Pi Pico W configurado

## ⚡ **Pinos Utilizados**

- **GPIO 11:** LED Vermelho
- **GPIO 12:** LED Amarelo
- **GPIO 13:** LED Verde

## 📝 **Instalação e Execução**

1. Clone o repositório:
   ```bash
   git clone https://github.com/Santos-Luan/Semaforo.git
   cd Semaforo
   ```
2. Compile o código usando o SDK do Raspberry Pi Pico.
3. Faça o upload do binário para o Raspberry Pi Pico.
4. Conecte os LEDs conforme o esquema de pinos e execute o código.

## 💻 **Código Principal**

O controle dos LEDs é feito através da função `repeating_timer_callback()`, chamada automaticamente a cada 3 segundos. A inicialização dos pinos é feita pela função `Inicializacoes()`, que configura os GPIOs como saídas.
