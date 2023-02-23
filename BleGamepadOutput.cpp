#include "BleGamepadOutput.h"

#if defined(CONFIG_ARDUHAL_ESP_LOG)
    #include "esp32-hal-log.h"
    #define LOG_TAG "BLEGamepad"
#else
    #include "esp_log.h"
    static const char* LOG_TAG = "BLEGamepad";
#endif

BleGamepadOutput::BleGamepadOutput(void)
{
    ESP_LOGI(LOG_TAG, "Output callbacks initialised");
}

void BleGamepadOutput::onWrite(NimBLECharacteristic* pCharacteristic, NimBLEConnInfo& connInfo)
{
    uint8_t *cData = (uint8_t *)malloc(sizeof(uint8_t) * pCharacteristic->getValue().length());
    for (int i = 0; i < pCharacteristic->getValue().length(); i++)
    {
        cData[i] = pCharacteristic->getValue().data()[i];
    }

    RumbleData *rData = (RumbleData *)(cData);

    func(rData);
}