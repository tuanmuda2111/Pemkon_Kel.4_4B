#include <stdio.h>                      // MISRA C:2012 Rule 1.1 - Include header standar
#include <stdint.h>                     // MISRA C:2012 Rule 1.1 - Untuk penggunaan uint32_t dan tipe numerik

#define THRESHOLD_DISTANCE 5U          // MISRA C:2012 Rule 8.9 - Gunakan konstanta simbolik, hindari magic number

// Simulasi fungsi HAL_Delay
void HAL_Delay(uint32_t delay)         // MISRA C:2012 Rule 8.4 - Prototipe fungsi harus ada
{
    printf("[Delay %lu ms]\n", (unsigned long)delay);  // MISRA C:2012 Rule 12.1 - Hindari implicit conversion
}

// Simulasi fungsi Buzzer
void Buzzer_On(void)
{
    printf("[BUZZER ON]\n");
}

void Buzzer_Off(void)
{
    printf("[BUZZER OFF]\n");
}

// Tampilkan info frekuensi berdasarkan nilai delay
void print_buzzer_frequency(uint32_t delay_time)
{
    if (delay_time <= 50U)
    {
        printf(">> Frekuensi: CEPAT \n");
    }
    else if (delay_time <= 100U)
    {
        printf(">> Frekuensi: SEDANG \n");
    }
    else if (delay_time <= 200U)
    {
        printf(">> Frekuensi: PELAN \n");
    }
    else
    {
        printf(">> Frekuensi: DIAM \n");
    }
}

// Fungsi utama seperti di STM32
void run_logic(uint32_t distance)
{
    uint32_t delay_time = 0U;
    uint32_t i = 0U;

    printf("Distance read: %lu cm\n", (unsigned long)distance);

    // Menentukan delay_time berdasarkan jarak
    if (distance <= THRESHOLD_DISTANCE)
    {
        delay_time = 50U;
    }
    else if (distance <= 10U)
    {
        delay_time = 100U;
    }
    else if (distance <= 15U)
    {
        delay_time = 200U;
    }
    else
    {
        delay_time = 0U;
    }

    print_buzzer_frequency(delay_time);

    if (delay_time > 0U)
    {
        for (i = 0U; i < 3U; ++i)  // MISRA C:2012 Rule 13.3 - Penggunaan indeks loop yang aman
        {
            Buzzer_On();
            HAL_Delay(delay_time);
            Buzzer_Off();
            HAL_Delay(delay_time);
        }
    }
    else
    {
        Buzzer_Off();
        printf("[BUZZER DIAM]\n");
    }
}

int main(void)
{
    uint32_t input_distance = 0U;
    char again = 'y';

    printf("=== HC-SR04 Unit Testing Simulator ===\n");

    while ((again == 'y') || (again == 'Y'))  // MISRA C:2012 Rule 14.3 - ekspresi boolean eksplisit
    {
        printf("\nMasukkan jarak (cm): ");
        if (scanf("%u", &input_distance) != 1)
        {
            printf("Input tidak valid. Silakan coba lagi.\n");
            while (getchar() != '\n') {}  // MISRA C:2012 Rule 14.4 - penggunaan loop valid untuk flush
            continue;
        }

        run_logic(input_distance);

        printf("\nCoba jarak lain? (y/n): ");
        (void)scanf(" %c", &again);  // MISRA C:2012 Rule 10.5 - nilai return scanf dibuang dengan cast void
    }

    printf("=== Unit test selesai ===\n");
    return 0;
}
