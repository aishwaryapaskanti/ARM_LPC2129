//dht11.c
#include <lpc214x.h>
#include "dht11.h"
#include "delay.h"

void dht11_init() {
    IO0DIR |= (1 << DHT11_PIN);  // Set as output
    IO0SET |= (1 << DHT11_PIN);  // Set high
}

void dht11_request() {
    IO0DIR |= (1 << DHT11_PIN);   // Output
    IO0CLR |= (1 << DHT11_PIN);   // Pull low
    delay_us(20000);              // 20ms
    IO0SET |= (1 << DHT11_PIN);   // Pull high
    delay_us(30);                 // Wait
    IO0DIR &= ~(1 << DHT11_PIN);  // Input
}

u8 dht11_response() {
    delay_us(40);
    if (!(IO0PIN & (1 << DHT11_PIN))) {
        delay_us(80);
        if (IO0PIN & (1 << DHT11_PIN)) {
            delay_us(80);
            return 1;
        }
    }
    return 0;
}

u8 dht11_read_byte() {
    u8 i, byte = 0;
    for (i = 0; i < 8; i++) {
        while (!(IO0PIN & (1 << DHT11_PIN))); // Wait for HIGH
        delay_us(40);
        if (IO0PIN & (1 << DHT11_PIN))
            byte |= (1 << (7 - i));
        while (IO0PIN & (1 << DHT11_PIN)); // Wait for LOW
    }
    return byte;
}

void dht11_read_data(u8 *temp, u8 *humidity) {
    u8 h1, h2, t1, t2, checksum;
    dht11_request();
    if (dht11_response()) {
        h1 = dht11_read_byte();
        h2 = dht11_read_byte();
        t1 = dht11_read_byte();
        t2 = dht11_read_byte();
        checksum = dht11_read_byte();

        if ((h1 + h2 + t1 + t2) == checksum) {
            *humidity = h1;
            *temp = t1;
        }
    }
}
