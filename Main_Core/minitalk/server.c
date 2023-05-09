#include "minitalk.h"

void ft_str_converter(char *str)
{
  int idx = 7;
  int base;
  char bit;
  int control;
  int result;

  while (str[idx])
  {
    base = 1;
    control = idx;
    result = 0;
    while (base <= 128)
    {
      bit = str[control];
      if (bit == '1')
        result += base;
      base *= 2;
      control--;
    }
    ft_printf("%c", result);
    idx += 8;
  }
  // ft_printf("\n");
}

void ft_message_handler(int sig)
{
  static int idx;
  static char c[8];

  idx = 0;
  if (sig == SIGUSR1)
    c[idx] = '1';
  else if (sig == SIGUSR2)
    c[idx] = '0';
  idx++;
  if (idx == 8)
  {
    idx = 0;
    ft_str_converter(c);
  }
}

int main(void)
{
  ft_printf("Pid: %d\n", getpid());
  signal(SIGUSR1, ft_message_handler);
  signal(SIGUSR2, ft_message_handler);
  while (1)
    sleep(1);
  return 0;
}