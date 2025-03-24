OLED_GAMING = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += font_block.c
endif
