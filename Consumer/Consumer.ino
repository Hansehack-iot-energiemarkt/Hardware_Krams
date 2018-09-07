#include <Arduino.h>
#include <Wire.h>

#define A_IN_PIN		A0

#define GPIO_MSB_PIN 	12
#define GPIO_6_BIT		11
#define GPIO_5_BIT		10
#define GPIO_4_BIT		9
#define GPIO_3_BIT		6
#define GPIO_2_BIT		5
#define GPIO_1_BIT		21
#define GPIO_LSB_PIN 	20

unsigned long time;
int cur;

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
//	pinMode(GPIO_MSB_PIN, OUTPUT);
//	pinMode(GPIO_6_BIT, OUTPUT);
//	pinMode(GPIO_5_BIT, OUTPUT);
//	pinMode(GPIO_4_BIT, OUTPUT);
//	pinMode(GPIO_3_BIT, OUTPUT);
//	pinMode(GPIO_2_BIT, OUTPUT);
//	pinMode(GPIO_1_BIT, OUTPUT);
//	pinMode(GPIO_LSB_PIN, OUTPUT);
	// Add your initialization code here
}

// The loop function is called in an endless loop
void loop() {
	time = 15 - (millis() % 15);
//	delay(time * 1000);
	delay(50);
	cur = currCurr();
//	writeIntGPIO(cur);
	getAnalog();
//Add your repeated code here
}

int currCurr() {
	return 0x0F0AA0F0;
}

uint_fast16_t getAnalog() {
	Serial.println(analogRead(A_IN_PIN));
	return analogRead(A_IN_PIN);
}

void writeIntGPIO(int val) {

	digitalWrite(GPIO_MSB_PIN, HIGH);
	digitalWrite(GPIO_6_BIT, LOW);
	digitalWrite(GPIO_5_BIT, HIGH);
	digitalWrite(GPIO_4_BIT, LOW);
	digitalWrite(GPIO_3_BIT, HIGH);
	digitalWrite(GPIO_2_BIT, LOW);
	digitalWrite(GPIO_1_BIT, HIGH);
	digitalWrite(GPIO_LSB_PIN, LOW);
	delay(10);

	for (int i = 3; i >= 0; i--) {
		digitalWrite(GPIO_MSB_PIN, (1 << (i * 8 + 7) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_6_BIT, (1 << (i * 8 + 6) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_5_BIT, (1 << (i * 8 + 5) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_4_BIT, (1 << (i * 8 + 4) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_3_BIT, (1 << (i * 8 + 3) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_2_BIT, (1 << (i * 8 + 2) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_1_BIT, (1 << (i * 8 + 1) & val) > 0 ? HIGH : LOW);
		digitalWrite(GPIO_LSB_PIN, (1 << (i * 8) & val) > 0 ? HIGH : LOW);

		Serial.print("\nTo Code: ");
		Serial.println(uint8_t(val >> i * 8));
		Serial.print((1 << (i * 8 + 7) & val) > 0 ? 1 : 0);
		Serial.print((1 << (i * 8 + 6) & val) > 0 ? 1 : 0);
		Serial.print((1 << (i * 8 + 5) & val) > 0 ? 1 : 0);
		Serial.print((1 << (i * 8 + 4) & val) > 0 ? 1 : 0);
		Serial.print((1 << (i * 8 + 3) & val) > 0 ? 1 : 0);
		Serial.print((1 << (i * 8 + 2) & val) > 0 ? 1 : 0);
		Serial.print((1 << (i * 8 + 1) & val) > 0 ? 1 : 0);
		Serial.println((1 << (i * 8) & val) > 0 ? 1 : 0);

		delay(10);
	}

	digitalWrite(GPIO_MSB_PIN, LOW);
	digitalWrite(GPIO_6_BIT, HIGH);
	digitalWrite(GPIO_5_BIT, LOW);
	digitalWrite(GPIO_4_BIT, HIGH);
	digitalWrite(GPIO_3_BIT, LOW);
	digitalWrite(GPIO_2_BIT, HIGH);
	digitalWrite(GPIO_1_BIT, LOW);
	digitalWrite(GPIO_LSB_PIN, HIGH);
	delay(10);
}
