#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições de macros
#define SERVOMOTOR_PIN 22 
#define WRAP 65535 
#define M_ANGULO 7864 
#define L_ANGULO 1638 
#define STEP 17

/* calculo do divisor:

freq_clock padrão= 125MHz, warp = 65535, Fpwm desejada = 50Hz
Fpwm = freq_clock padrão/(div*(warp+1)) == 38.147*/

// Função para inicialização do PWM com frequência de 50Hz – período de 20ms.
void pwm_inicial_setup(){

    gpio_set_function(SERVOMOTOR_PIN, GPIO_FUNC_PWM); //Seta o pino 22 para funcionar como PWM

    uint slice = pwm_gpio_to_slice_num(SERVOMOTOR_PIN); // Salva o slice referente ao pino 22 na variável "slice"

    pwm_config config = pwm_get_default_config(); // Salvando configuração padrão do PWM na variável config

    pwm_config_set_clkdiv(&config, 38.0); // Define o divisor inteiro de clock para 38.0

    pwm_config_set_wrap(&config, WRAP); // Configurando WRAP para 65535

    pwm_init(slice, &config, true); // Inicializando o PWM
}

//primeira rotina a ser acionada no projeto
void mainRoutine(){
    pwm_set_gpio_level(SERVOMOTOR_PIN, 7864); // Duty Cycle de 0,12% (180°)
    printf("180 graus\n");
    sleep_ms(5000);
    pwm_set_gpio_level(SERVOMOTOR_PIN, 4817); // Duty Cycle de 0,0735% (90°)
    printf("90 graus\n");
    sleep_ms(5000);
    pwm_set_gpio_level(SERVOMOTOR_PIN, 1638); // Duty Cycle de 0,025% (0°)
    printf("0 graus\n");
    sleep_ms(5000);
}

int main(){
    uint16_t angulo = 1638; // Variável responsável por armazenar a posição atual do motor
    uint8_t Switch = 1; // Variável de controle para inverter rotação do servomotor

    stdio_init_all();
    pwm_inicial_setup(); //inicializando PWM
    mainRoutine(); //chamando a rotina que executa as primeiras tarefas do programa

    while (true) {
        pwm_set_gpio_level(SERVOMOTOR_PIN, angulo); // Função para alterar o ciclo ativo do período
        if(Switch){
            printf("Ajustado: %d\n", angulo);
            angulo += STEP;
        }
        else{
            printf("Ajustado: %d\n", angulo);
            angulo -= STEP;
        }
        if(angulo >= M_ANGULO ||angulo <= L_ANGULO) Switch = !Switch; //atualiza a variável responsável por inverter a rotação do motor
        sleep_ms(10);
    }

    return 0;
}