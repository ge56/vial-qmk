# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = bootloadhid
BOOTLOADER_SIZE = 2048

# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX           = yes # Custom matrix file
UNICODE_ENABLE          = yes # Unicode
BOOTMAGIC_ENABLE        = yes # Enable Bootmagic Lite
MOUSEKEY_ENABLE         = yes # Mouse keys
EXTRAKEY_ENABLE         = yes # Audio control and System control
CONSOLE_ENABLE          = no  # Console for debug
COMMAND_ENABLE          = yes # Commands for debug and configuration
NKRO_ENABLE             = yes # Enable N-Key Rollover
BACKLIGHT_ENABLE        = yes # Enable keyboard backlight functionality
RGBLIGHT_ENABLE         = no
LTO_ENABLE              = yes 
BACKLIGHT_DRIVER        = custom

# project specific files
SRC ?=	matrix.c \
        led_fn.c \
        light_ws2812.c \
        backlight_user.c \
        rgblight.c
    
include $(TMK_DIR)/protocol/ble51.mk
