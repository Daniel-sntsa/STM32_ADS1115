#ifndef ADS1115_H_
#define ADS1115_H_
#include "main.h"


#define ADS1115_ADDRESS0 0x90



//Input multiplexer configuration

#define ADC0_1    	0b000 << 12
#define ADC0_3    	0b001 << 12
#define ADC1_3    	0b010 << 12
#define ADC2_3    	0b011 << 12
#define ADC0_GND    0b100 << 12
#define ADC1_GND    0b101 << 12
#define ADC2_GND    0b110 << 12
#define ADC3_GND    0b111 << 12



//Programmable gain amplifier configuration

#define PGA0    0b000 << 9
#define PGA1    0b001 << 9
#define PGA2    0b010 << 9
#define PGA3    0b011 << 9
#define PGA4    0b100 << 9
#define PGA5    0b101 << 9
#define PGA6    0b110 << 9
#define PGA7    0b111 << 9



//Operational status

#define MODE_CONT   		0b0 << 8
#define MODE_POWER_DOWN  	0b1 << 8



//Data rate

#define RAT8 	  0b000 << 5
#define RAT16     0b001 << 5
#define RAT32     0b010 << 5
#define RAT64     0b011 << 5
#define RAT128    0b100 << 5
#define RAT250    0b101 << 5
#define RAT475    0b110 << 5
#define RAT860    0b111 << 5



//Comparator Mode

#define TRADITIONAL		0b00 << 4
#define WINDOW			0b01 << 4



//Comparator Mode Polarity

#define ACTIVE_LOW		0b00 << 3
#define ACTIVE_HIGH		0b01 << 3



//Latching Comparator

#define NON_LATCH		0b00 << 1
#define LATCH			0b01 << 1



//Comparator Queue and Disable

#define A_1_CONV		0b00 << 0
#define A_2_CONV		0b01 << 0
#define A_4_CONV		0b10 << 0
#define DSABLE			0b11 << 0



//Input multiplexer configuration

void initADS(void);

void Config(uint8_t OS,uint8_t MUX, uint8_t PGA,uint8_t MODE, uint8_t DR, uint8_t COMP_MODE, uint8_t COMP_POL,uint8_t COMP_LAT,uint8_t COMP_QUE );
int16_t ADS1115_Read(I2C_HandleTypeDef* hi2c1);
int8_t ADS1115_Init(uint16_t config, I2C_HandleTypeDef* hi2c1);
float ADS1115_Voltage(I2C_HandleTypeDef* hi2c1);

#endif
