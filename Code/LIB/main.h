#ifndef MAIN_H
#define MAIN_H



#define PASS_SIZE                     (u8)   4
#define TRIES_ALLOWED                 (u8)   3
#define PASSWORD_SYMBOL               (u8)  '*'
#define ASCII_ZERO                    (u8)  '0'

#define PASS_NOT_SET                  (u8)  0xFF
#define PASS_SET                      (u8)  0x01

#define ADMIN_PASS_STATUS_ADDRESS     (u16) 0X100
#define GUEST_PASS_STATUS_ADDRESS     (u16) 0X101
#define EEPROM_ADMIN_ADDRESS          (u16) 0X102
#define EEPROM_GUEST_ADDRESS          (u16) 0X106
#define LOGIN_BLOCKED_ADDRESS         (u16) 0X10A

#define CHECK_ADMIN_MODE               (s8) '0'
#define CHECK_GUEST_MODE               (s8) '1'

#define NO_MODE                        (u8)  0
#define ADMIN                          (u8)  1
#define GUEST                          (u8)  2

#define TRUE                           (u8)  1
#define FALSE                          (u8)  0



#define NOT_STORED                        0xFF


#endif