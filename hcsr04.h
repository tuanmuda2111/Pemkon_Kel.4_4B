#ifndef HCSR04_H                      // MISRA C:2012 Rule 20.5 - Nama makro header guard harus unik dan konsisten
#define HCSR04_H                      // Menghapus double underscore __ yang dikhususkan untuk compiler (MISRA Rule 20.2)

#include "main.h"                     // MISRA C:2012 Rule 1.1 - Include file eksternal yang dibutuhkan

void HC_SR04_Init(void);             // MISRA C:2012 Rule 8.4 - Deklarasi prototipe fungsi
uint32_t HC_SR04_ReadDistance(void); // MISRA C:2012 Rule 8.4

#endif /* HCSR04_H */                // MISRA C:2012 Rule 20.5 - Penutup header guard harus sesuai pembuka
