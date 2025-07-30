/*
 * ads1115.c
 */
#include "ads1115.h"
#include "stdio.h"
#include "main.h"





int8_t ADS1115_Init(uint16_t config, I2C_HandleTypeDef* hi2c1){
	uint8_t config1= config>>8;
	uint8_t config2= config;
	printf("%i\t",config1);
	printf("%i\t",config2);
	uint8_t configRegister[]={0x01,config1,config2};


	HAL_I2C_Master_Transmit(hi2c1, ADS1115_ADDRESS0, &configRegister , sizeof(configRegister), 100);

	return 0;
}


int16_t ADS1115_Read(I2C_HandleTypeDef* hi2c1){;
	uint8_t pointerRegister = 0x01;
	uint8_t adcValue[2];



	HAL_I2C_Master_Transmit(hi2c1, ADS1115_ADDRESS0, &pointerRegister, sizeof(pointerRegister), 100);
	pointerRegister = 0;
	HAL_I2C_Master_Transmit(hi2c1, ADS1115_ADDRESS0, &pointerRegister, sizeof(pointerRegister), 100);
	HAL_I2C_Master_Receive(hi2c1, ADS1115_ADDRESS0, &adcValue, sizeof(adcValue), 100);

	return (adcValue[0]<<8 | adcValue[1]);

}

float ADS1115_Voltage(I2C_HandleTypeDef* hi2c1){
	uint8_t pointerRegister = 0x01;
	uint8_t adcValue[2];


	HAL_I2C_Master_Transmit(hi2c1, ADS1115_ADDRESS0, &pointerRegister, sizeof(pointerRegister), 100);
	pointerRegister = 0;
	HAL_I2C_Master_Transmit(hi2c1, ADS1115_ADDRESS0, &pointerRegister, sizeof(pointerRegister), 100);
	HAL_I2C_Master_Receive(hi2c1, ADS1115_ADDRESS0, &adcValue, sizeof(adcValue), 100);

	int16_t RawValue=adcValue[0]<<8 | adcValue[1];
	float Converted=4.096*2*RawValue/65536;
	return Converted;
}
