# Glassphones

A Bluetooth headset but built into glasses frames; this is V1, so is a bulky experiment

MCU is an esp32 (tinypico nano), programmed using espidf 4.3

codec is a Maxim9850eti+, which is sent audio over i2s and control signals over i2c.
on the same i2s bus (sharing BCLK and LRCLK) is an ics43432 MEMS microphone

audio drivers are tiny bone conduction speakers.

micro SD card using 4 bit SD bus used for secondary storage 
