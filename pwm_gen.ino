// PWM at 20kHz with 69.7% on D9 and 33.33% on D10

void setup() {
  // Set D9 and D10 as output
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Stop Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // Set Fast PWM mode with ICR1 as TOP
  // WGM13:WGM10 = 14 => Fast PWM with ICR1 as TOP
  TCCR1A |= (1 << COM1A1) | (1 << COM1B1); // Non-inverting mode
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);

  // No prescaling (prescaler = 1)
  TCCR1B |= (1 << CS10);

  // TOP value for 20kHz PWM frequency
  ICR1 = 799; // f_PWM = 16MHz / (1 * (1 + 799)) = 20kHz

  // Set duty cycles
  OCR1A = (ICR1 * 23) / 33; // BOOST duty on D9
  OCR1B = (ICR1 * 5) / 15;         // BUCK duty on D10
}

void loop() {
}
