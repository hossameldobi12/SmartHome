#File name: makefile
#Purpose:   Contains the compiler commands to have the final executable image (.hex)
#Author:   Hossam ELdobi
#Date:      9-9-2022
#Version:   v1.0

# Include directories
INC_DIR := -I../LIB
INC_DIR += -I../MCAL/DIO
INC_DIR += -I../MCAL/ADC
INC_DIR += -I../MCAL/EXT0
INC_DIR += -I../MCAL/GIE
INC_DIR += -I../MCAL/TIMER0
INC_DIR += -I../MCAL/UART
INC_DIR += -I../MCAL/EEPROM
INC_DIR += -I../HAL/KEYPAD
INC_DIR += -I../HAL/LCD
INC_DIR += -I../HAL/MENU
INC_DIR += -I../HAL/RELAY
INC_DIR += -I../HAL/LM35
INC_DIR += -I../HAL/DCMOTOR
INC_DIR += -I../HAL/BUZZER





# C source files
C_FILES := ../main.c
C_FILES += ../MCAL/DIO/DIO_prog.c
C_FILES += ../MCAL/ADC/ADC_prog.c
C_FILES += ../MCAL/EXT0/EXT0_prog.c
C_FILES += ../MCAL/GIE/GIE_prog.c
C_FILES += ../MCAL/TIMER0/TIMER0_prog.c
C_FILES += ../MCAL/UART/UART_prog.c
C_FILES += ../MCAL/SPI/SPI_prog.c
C_FILES += ../MCAL/EEPROM/EEPROM_prog.c
C_FILES += ../HAL/KEYPAD/KEYPAD_prog.c
C_FILES += ../HAL/LCD/LCD_prog.c
C_FILES += ../HAL/MENU/MENU.c
C_FILES += ../HAL/RELAY/RELAY_prog.c
C_FILES += ../HAL/LM35/LM35_Interface.c
C_FILES += ../HAL/DCMOTOR/MOTOR_Interface.c
C_FILES += ../HAL/BUZZER/BUZZER_prog.c





# Object files
OBJ_FILES := main.o
OBJ_FILES += DIO_prog.o
OBJ_FILES += ADC_prog.o
OBJ_FILES += EXT0_prog.o
OBJ_FILES += GIE_prog.o
OBJ_FILES += TIMER0_prog.o
OBJ_FILES += UART_prog.o
OBJ_FILES += SPI_prog.o
OBJ_FILES += EEPROM_prog.o
OBJ_FILES += KEYPAD_prog.o
OBJ_FILES += LCD_prog.o
OBJ_FILES += MENU.o
OBJ_FILES += RELAY_prog.o
OBJ_FILES += LM35_Interface.o
OBJ_FILES += MOTOR_Interface.o
OBJ_FILES += BUZZER_prog.o




# AVR Controller configuration
CONTROLLER := atmega32
CONTROLLER_CLK := 16000000

# Compiler configuration variables
CC := avr-gcc
COMPILER_OPTIONS := -mmcu=$(CONTROLLER) -DF_CPU=$(CONTROLLER_CLK) -Wall -Os $(INC_DIR)

all: $(C_FILES) clean main.hex

main.elf:
	@echo "Compiling C files......."
	@$(CC) $(COMPILER_OPTIONS) -c $(C_FILES)
	@echo "Linking C files......."
	@$(CC) -Wl,-Map=main.map -mmcu=$(CONTROLLER) $(OBJ_FILES) -o main.elf

main.hex: main.elf
	@echo "Generating Hex file......."
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature main.elf -O ihex main.hex

clean:
	@rm -rf *.hex *.elf *.map *.o
