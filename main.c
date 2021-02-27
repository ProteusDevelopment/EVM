#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */
void main(void)
{
  // Инициализация.
  WDTCTL = WDTPW + WDTHOLD;
  Init_System();
  Init_System_Clock();

  LCD_init();
  LCD_clear();
  
  /* 1 Задание */
  
  /*
  // Строки для вывода.
  char row1[] = "Черных";
  char row2[] = "ВТ-32";

  // Вывод фамилии.
  LCD_message(row1);
  
  // Переход на 2 строку.
  LCD_set_pos(1, 0);

  // Вывод группы.
  LCD_message(row2);
  */
  
  
  
  /* 2 Задание */
  
  LCD_WriteCommand(0x40);

  // Смайлик с 2 открытими глазами.
  char data[] =
  {
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000000
  };

  // Смайлик с закрытым левым глазом.
  char data2[] =
  {
    0b00000000,
    0b00000010,
    0b00000010,
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000000
  };

  // Смайлик с закрытым правым глазом.
  char data3[] =
  {
    0b00000000,
    0b00001000,
    0b00001000,
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000000
  };

  // Запись в CGRAM.
  int i;
  for (i = 0; i < 8; i++)
    LCD_WriteData(data[i]);
  for (i = 0; i < 8; i++)
    LCD_WriteData(data2[i]);
  for (i = 0; i < 8; i++)
    LCD_WriteData(data3[i]);

  // Задержка между "кадрами".
  word ms = 100;
  // Вывод анимации на индикатор.
  while(0b1)
  {
      LCD_set_pos(0, 0);
      LCD_WriteData(0);
      wait_1ms(ms);

      LCD_set_pos(0, 0);
      LCD_WriteData(1);
      wait_1ms(ms);

      LCD_set_pos(0, 0);
      LCD_WriteData(0);
      wait_1ms(ms);

      LCD_set_pos(0, 0);
      LCD_WriteData(2);
      wait_1ms(ms);
  }
}
