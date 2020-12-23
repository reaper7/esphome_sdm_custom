#include "esphome.h"

class SDMComponent : public PollingComponent {
public:
  SDM sdm = SDM(Serial, 9600, NOT_A_PIN, SERIAL_8N1, false);

  Sensor *voltage_sensor = new Sensor();
  Sensor *current_sensor = new Sensor();
  Sensor *power_sensor = new Sensor();
  Sensor *energy_sensor = new Sensor();
  Sensor *frequency_sensor = new Sensor();
  Sensor *power_factor_sensor = new Sensor();

  SDMComponent() : PollingComponent(15000) {}

  void setup() override {
    ESP_LOGD("SDM", "Setup completed");
  }

  void update() override {
    ESP_LOGD("SDM", "Start reading");
    float voltage = sdm.readVal(SDM_PHASE_1_VOLTAGE);
    float current = sdm.readVal(SDM_PHASE_1_CURRENT);
    float power = sdm.readVal(SDM_PHASE_1_POWER);
    float energy = sdm.readVal(SDM_TOTAL_ACTIVE_ENERGY); 
    float frequency = sdm.readVal(SDM_FREQUENCY);
    float power_factor = sdm.readVal(SDM_PHASE_1_POWER_FACTOR);

    ESP_LOGD("SDM", "V=%.1f V, I=%.3f A, P=%.1f W, E=%.1f kWh, F=%.1f Hz, PF=%.2f", voltage, current, power,
           energy, frequency, power_factor);
    
    voltage_sensor->publish_state(voltage);
    current_sensor->publish_state(current);
    power_sensor->publish_state(power);
    energy_sensor->publish_state(energy);
    frequency_sensor->publish_state(frequency);
    power_factor_sensor->publish_state(power_factor);

    ESP_LOGD("SDM", "End reading");
  }
};