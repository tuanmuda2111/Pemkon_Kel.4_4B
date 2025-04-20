#include "hcsr04.h"     // MISRA C:2012 Rule 1.1, Rule 8.4 - include header yang mendeklarasikan fungsi
#include "stm32f1xx_hal.h"  // MISRA C:2012 Rule 1.1 - file header eksternal yang dibutuhkan

void HC_SR04_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // MISRA C:2012 Rule 9.1 - variabel harus diinisialisasi

    __HAL_RCC_GPIOB_CLK_ENABLE();  // MISRA C:2012 Rule 2.2 - hasil makro digunakan

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);  // MISRA C:2012 Rule 8.4 - fungsi eksternal dipanggil sesuai prototipe

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

uint32_t HC_SR04_ReadDistance(void)
{
    uint32_t pulse_duration = 0U;
    uint32_t distance = 0U;
    uint32_t start = 0U;
    uint32_t end = 0U;
    uint32_t timeout = 100U;  // MISRA C:2012 Rule 17.7 - gunakan timeout pada loop untuk menghindari infinite loop

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);  // Trigger high
    HAL_Delay(1U);  // MISRA C:2012 Rule 10.1 - konversi literal ke unsigned

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);  // Trigger low

    // Tunggu sampai Echo HIGH dengan timeout
    while ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) && (timeout > 0U))
    {
        timeout--;
    }
    start = HAL_GetTick();

    timeout = 100U;
    while ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_SET) && (timeout > 0U))
    {
        timeout--;
    }
    end = HAL_GetTick();

    pulse_duration = end - start;  // Durasi pulsa

    // Hitung jarak (konstanta 0.0343 adalah kecepatan suara dalam cm/us dibagi 2)
    // MISRA C:2012 Rule 10.1 - casting eksplisit
    distance = (uint32_t)(((float)pulse_duration) * 0.0343f / 2.0f);

    return distance;
}

