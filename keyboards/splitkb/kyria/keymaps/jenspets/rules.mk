OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
WPM_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no # Need to optimize firmware size...

EXTRAFLAGS += -flto # Link time optimization, might decrease FW size
