#include "mlx90614.h"

uint8_t data[2] = {0};

float MLX90614_GetTemperature()
{
  uint16_t temp = 0;
  float temperatureValue = 0;
  HAL_I2C_Mem_Read(&hi2c2, 0x00, 0x07, 1, data, 2, 0x20);
  temp = ((data[1] << 8) | data[0]);
  if ((TEMPERATUREMIN <= temp) && (temp <= TEMPERATUREMAX))
  {
    temperatureValue = (((float)temp * 2) - 27315) / 100;
  }
  else
  {
    temperatureValue = -100.0;
  }
  return temperatureValue;
}
