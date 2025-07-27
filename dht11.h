#ifndef DHT11_H
#include "types.h"
#define DHT11_H

#define DHT11_PIN 10  // P0.10

void dht11_init(void);
void dht11_request(void);
u8 dht11_response(void);
u8 dht11_read_byte(void);
void dht11_read_data(u8 *temp, u8 *humidity);

#endif
