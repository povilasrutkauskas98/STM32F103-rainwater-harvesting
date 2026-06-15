#include "hcsr04.h"

extern TIM_HandleTypeDef htim2;

uint32_t HCSR04_GetDistanceCM(void)
{
    uint32_t timeout = 0;
    uint32_t echo_time = 0;

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    HAL_Delay(2);

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
    __HAL_TIM_SET_COUNTER(&htim2, 0);
    while (__HAL_TIM_GET_COUNTER(&htim2) < 10) {}
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

    timeout = 0;
    while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
    {
        timeout++;
        if (timeout > 100000)
            return 0;
    }

    __HAL_TIM_SET_COUNTER(&htim2, 0);

    while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
    {
        if (__HAL_TIM_GET_COUNTER(&htim2) > 60000)
            return 0;
    }

    echo_time = __HAL_TIM_GET_COUNTER(&htim2);

    return echo_time / 58;
}


uint32_t GetAverageDistanceCM(void)
{
    uint32_t sum = 0;
    uint8_t valid_samples = 0;
    uint32_t measurement;

    while (valid_samples < 10)
    {
    	measurement = HCSR04_GetDistanceCM();

    	if (measurement > 0 && measurement < 100)

    	{
    		sum+= measurement;
    		valid_samples++;
    	}
    		HAL_Delay(30);
    }

    return sum / valid_samples;

}


