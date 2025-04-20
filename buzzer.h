#ifndef BUZZER_H                         // MISRA C:2012 Rule 20.5 - Header guard harus unik dan tidak menggunakan __ (Rule 20.2)
#define BUZZER_H                         // Penggunaan nama makro tanpa double underscore

#include "main.h"                        // MISRA C:2012 Rule 1.1 - File header eksternal harus valid dan digunakan

void Buzzer_Init(void);                 // MISRA C:2012 Rule 8.4 - Prototipe fungsi harus dideklarasikan
void Buzzer_On(void);                   // MISRA C:2012 Rule 8.4
void Buzzer_Off(void);                  // MISRA C:2012 Rule 8.4

#endif /* BUZZER_H */                   // MISRA C:2012 Rule 20.5 - Penutup sesuai nama pembuka
