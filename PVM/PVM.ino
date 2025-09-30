const int ledPin = 7;  

int period = 10000;  
int duty = 50;       

void set_period(int p) {
  if (p < 100) p = 100;
  if (p > 10000) p = 10000;
  period = p;
}

void set_duty(int d) {
  if (d < 0) d = 0;
  if (d > 100) d = 100;
  duty = d;
}

void pwm_led(int period_us, int duty_percent) {
  int onTime = (period_us * duty_percent) / 100;
  int offTime = period_us - onTime;
  
  digitalWrite(ledPin, LOW);
  delayMicroseconds(onTime);
  
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(offTime);
}

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  for (int i = 0; i <= 100; i++) {
    set_duty(i);
    pwm_led(period, duty);
  }

  for (int i = 100; i >= 0; i--) {
    set_duty(i);
    pwm_led(period, duty);
  }
}
