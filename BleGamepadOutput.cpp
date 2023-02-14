#include "BleGamepadOutput.h"

#if defined(CONFIG_ARDUHAL_ESP_LOG)
  #include "esp32-hal-log.h"
  #define LOG_TAG "BLEGamepad"
#else
  #include "esp_log.h"
  static const char* LOG_TAG = "BLEGamepad";
#endif

BleGamepadOutput::BleGamepadOutput(void) {
  ESP_LOGI(LOG_TAG, "Output callbacks initialised");
}

void BleGamepadOutput::onWrite(NimBLECharacteristic* pCharacteristic, NimBLEConnInfo& connInfo)
{
  RumbleData* rData = (RumbleData*)(pCharacteristic->getValue().c_str());
  ESP_LOGI(LOG_TAG, "New Data received");
  ESP_LOGI(LOG_TAG, "Data: %d", rData->data);

  func(rData);
}