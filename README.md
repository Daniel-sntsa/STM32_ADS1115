# 📡 Driver ADS1115 para STM32F103C8T6  

## 📖 Descrição do Projeto  
Este projeto implementa um **driver simples para o conversor analógico-digital ADS1115**, utilizando comunicação I²C com o microcontrolador **STM32F103C8T6**.  
O exemplo incluso realiza a leitura de sinais analógicos e exibe o valor convertido em tensão via UART.

---

## ⚡ Recursos Implementados
- ✅ Configuração do registrador de configuração do ADS1115  
- ✅ Função de leitura RAW de 16 bits  
- ✅ Função para conversão direta em tensão (V)  
- ✅ Utilização da biblioteca HAL para comunicação I²C  
- ✅ Exemplo funcional em STM32CubeIDE  

---

## 🔧 Requisitos de Hardware
- 🟢 **STM32F103C8T6** (Blue Pill)  
- 🟢 **ADS1115** (conversor ADC 16 bits I²C)  
- 🟢 Resistores pull-up de 4.7kΩ para SDA e SCL  
- 🟢 Fonte de alimentação 3.3V ou 5V  

### Conexões sugeridas
| ADS1115 | STM32F103C8T6 |
|---------|---------------|
| VCC     | 3.3V ou 5V    |
| GND     | GND           |
| SDA     | PB7 (I²C1 SDA)|
| SCL     | PB6 (I²C1 SCL)|
| ADDR    | GND (endereço 0x48)|  

---

## 📂 Estrutura do Projeto
```
stm32_ads1115_driver/
├── Core
│   ├── Inc
│   │   └── ads1115.h       # Header do driver
│   └── Src
│       ├── ads1115.c       # Implementação do driver
│       └── main.c          # Exemplo de uso
└── README.md
```

---

## 🛠️ Funções do Driver

### `int8_t ADS1115_Init(uint16_t config, I2C_HandleTypeDef *hi2c)`
Inicializa o ADS1115 com a configuração fornecida.

### `int16_t ADS1115_Read(I2C_HandleTypeDef *hi2c)`
Lê o valor RAW (16 bits) do conversor.

### `float ADS1115_Voltage(I2C_HandleTypeDef *hi2c)`
Lê o ADC e retorna o valor convertido em tensão (V).

---

## ▶️ Exemplo de Uso (main.c)
```c
#include "ads1115.h"

extern I2C_HandleTypeDef hi2c1;

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_I2C1_Init();
    MX_USART1_UART_Init();

    ADS1115_Init(ADS1115_DEFAULT_CONFIG, &hi2c1);

    while (1) {
        float voltage = ADS1115_Voltage(&hi2c1);
        printf("Tensão: %.3f V\r\n", voltage);
        HAL_Delay(500);
    }
}
```

---

## ⚠️ Observações
- O cálculo da tensão considera **PGA = ±4.096V**. Se usar outro ganho, ajuste o cálculo.  
- Configure corretamente o endereço I²C (`ADS1115_ADDRESS0`) conforme o pino **ADDR**.  

---

## 📜 Licença
Este projeto é de uso livre para fins educacionais e de desenvolvimento.  
