# Spectrum emulator on the microcontroller stm32f407. This is my old project, which I sometimes look at.
# 1. Processor commands are emulated.
# 2. The screen is updated 48.8 times per second, this update does not look like Spectrum, 1 pixel update per CPU clock, the whole screen is 320 pixels wide and 224 lines.
# 3. 4 timers emulate the work of ay-3-891x. 3 voices and a noise generator. There is no envelope generator.
