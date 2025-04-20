#include "buzzer.h"               // MISRA C:2012 Rule 1.1, Rule 8.4 - Include header yang mendeklarasikan fungsi
#include "stm32f1xx_hal.h"        // MISRA C:2012 Rule 1.1 - Header eksternal yang diperlukan

void Buzzer_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // MISRA C:2012 Rule 9.1 - Variabel harus diinisialisasi sebelum digunakan

    __HAL_RCC_GPIOB_CLK_ENABLE();            // MISRA C:2012 Rule 2.2 - Hasil ekspresi (makro) digunakan

    GPIO_InitStruct.Pin = GPIO_PIN_8;        // MISRA C:2012 Rule 10.1 - Literal numerik sesuai tipe data
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);  // MISRA C:2012 Rule 8.4 - Panggil fungsi sesuai deklarasi
}

void Buzzer_On(void)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);  // MISRA C:2012 Rule 10.1 - Konstanta harus sesuai tipe
}

void Buzzer_Off(void)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);  // MISRA C:2012 Rule 10.1
}
