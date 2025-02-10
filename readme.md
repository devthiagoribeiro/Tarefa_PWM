# Controle de Servomotor por PWM com Raspberry Pi Pico W

Este projeto consiste em controlar um servomotor utilizando o módulo PWM (Pulse Width Modulation) do microcontrolador Raspberry Pi Pico W. A simulação foi realizada no ambiente Wokwi, utilizando o Pico SDK e a linguagem C para programação.

## Descrição do Projeto

O objetivo desta atividade é simular o controle de um servomotor padrão (micro servo) utilizando o módulo PWM do Raspberry Pi Pico W. O projeto inclui a configuração do PWM para diferentes ciclos ativos, permitindo o controle do ângulo do servomotor em 0°, 90° e 180°. Além disso, foi implementada uma rotina para movimentação suave do braço do servomotor entre 0° e 180°.

### 🎥 Demonstração
[Clique para assistir](https://youtu.be)

### Requisitos da Atividade

1. **Configuração do PWM**:
   - Frequência de PWM: 50Hz (período de 20ms).
   - Ciclo ativo de 2.400µs (Duty Cycle de 0,12%) para posicionar o servomotor em 180°.
   - Ciclo ativo de 1.470µs (Duty Cycle de 0,0735%) para posicionar o servomotor em 90°.
   - Ciclo ativo de 500µs (Duty Cycle de 0,025%) para posicionar o servomotor em 0°.

2. **Movimentação Periódica**:
   - Implementação de uma rotina para movimentação suave do braço do servomotor entre 0° e 180°, com incremento de ±5µs e atraso de 10ms.

3. **Experimento com LED RGB**:
   - Utilização da ferramenta BitDogLab para observar o comportamento do LED RGB (GPIO 12) durante a execução do código.

## Tecnologias Utilizadas

- **Microcontrolador**: Raspberry Pi Pico W.
- **Linguagem de Programação**: C.
- **Ambiente de Desenvolvimento**: VS Code.
- **Simulador**: Wokwi.
- **Ferramenta Educacional**: BitDogLab.
- **Versionamento**: GitHub.

## Como Executar o Projeto

1. **Configuração do Ambiente**:
   - Instale o VS Code e configure o ambiente de desenvolvimento para o Raspberry Pi Pico W.
   - Integre o simulador Wokwi ao VS Code.

2. **Clonar o Repositório**:
   ```bash
   git clone https://github.com/devthiagoribeiro/Tarefa_PWM
   cd Tarefa_PWM