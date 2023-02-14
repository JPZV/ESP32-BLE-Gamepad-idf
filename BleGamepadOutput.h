#ifndef ESP32_BLE_GAMEPAD_OUTPUT_CALLBACKS_H
#define ESP32_BLE_GAMEPAD_OUTPUT_CALLBACKS_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include <NimBLEServer.h>
#include "NimBLECharacteristic.h"

// key report back
typedef struct
{
    uint8_t data;
} RumbleData;
using callBackFunc = void (*)(RumbleData*);

class BleGamepadOutput : public NimBLECharacteristicCallbacks
{
public:
    callBackFunc func = [](RumbleData*){ };
    BleGamepadOutput(void);
    void onWrite(NimBLECharacteristic* pCharacteristic, NimBLEConnInfo& connInfo);
};

#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_GAMEPAD_OUTPUT_CALLBACKS_H