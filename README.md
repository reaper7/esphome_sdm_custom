# esphome_sdm_custom

This is a custom component for esphome.
Component is in the custom_component/sdm directory.
Example application in the powermetersdm.yaml file.

Component in its current version can read the following parameters:
voltage, current, power, energy, frequency and power factor for single phase.

It can be used (as-is) to read the following modbus meters:
SDM120, SDM220, SDM230, SDM630(only first phase).

Add-on based on https://github.com/reaper7/SDM_Energy_Meter library.
