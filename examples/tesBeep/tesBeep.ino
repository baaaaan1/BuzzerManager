#include <BuzzerManager.h>

#define bzPin 9  // Pin untuk buzzer
BuzzerManager buzzer(bzPin);

void setup() {
  // Tidak perlu setup tambahan untuk buzzer
}

void loop() {
  // Panggil fungsi beep (bisa dipanggil kapan saja)
  buzzer.beep(3, 500, 250, 300); // 3 beep, 500 Hz, durasi 250ms, jeda 300ms

  // Jalankan update untuk memastikan fungsi berjalan
  buzzer.update();

  // Tugas lain tetap berjalan
  // ...
}
