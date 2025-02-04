#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Declarações
#define LED_PIN_R 11
#define LED_PIN_Y 12
#define LED_PIN_G 13
bool led = false;

static volatile int16_t cont = 0;
static volatile int16_t contSecund = 0;

// Funções
void Inicializacoes();
// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t)
{
    printf("Passou 3 segundos\n"); // Imprimi mostrando que se passaram 3 segundos

    if (cont == 0)
    {
        gpio_put(LED_PIN_R, false);
        gpio_put(LED_PIN_Y, true);
        cont++;
    }
    else if (cont == 1)
    {
        gpio_put(LED_PIN_Y, false);
        gpio_put(LED_PIN_G, true);
        cont++;
    }
    else
    {
        gpio_put(LED_PIN_G, false);
        gpio_put(LED_PIN_R, true);
        cont = 0;
    }
    return true;
}

int main()
{
    // Declaração de uma estrutura de temporizador de repetição..
    struct repeating_timer timer; // Variável do tipo da struct para o parametro da função add_repeatring_timer_ms()
    Inicializacoes();
    // Configura o temporizador para chamar a função de callback a cada 1 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    // Inicia o led red ligado
    gpio_put(LED_PIN_R, true);
    // Loop infinito que mantém o programa em execução.
    while (true)
    {
        printf("Passou 1 segundo\n");
        sleep_ms(1000);
    }
    return 0;
}

void Inicializacoes()
{
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializar os pinos 11, 12 e 13 e definir como saída
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);
    gpio_init(LED_PIN_Y);
    gpio_set_dir(LED_PIN_Y, GPIO_OUT);
}