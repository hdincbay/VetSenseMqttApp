#include <mqtt/async_client.h>
#include "MQTTAsync.h"
#include <iostream>

int main() {
    mqtt::async_client client("tcp://broker.hivemq.com:1883", "test_client");
    try {
        client.connect()->wait();
        std::cout << "Connected to MQTT broker" << std::endl;
        client.disconnect()->wait();
        std::cout << "Disconnected" << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << exc.what() << std::endl;
        return 1;
    }
    return 0;
}