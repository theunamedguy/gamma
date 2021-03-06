#include "gamma.h"
#include <stdint.h>
char* read_buf;
int idx=0, maxchars;
uint32_t readdone=0;
extern uint32_t loop_while_ptr_zero(uint32_t* ptr);
void on_keypress(char c)
{
  if(c!='\n' && c!='\b' && c!=127)
    {
      if(idx<maxchars)
	{
	  read_buf[idx]=c;
	  ++idx;
	}
    }
  else
    {
      switch(c)
	{
	case '\n':
	  readdone=1; // this does not work!
	  break;
	case '\b': case 127:
	  if(idx>0)
	    {
	      read_buf[idx]=0;
	      --idx;
	    }
	  break;
	}
    }
}
int read(int n, char* buf)
{
  printf("Read function entered.\n");
  read_buf=buf;
  idx=0;
  maxchars=n;
  register_keyboard_handler(&on_keypress);
  readdone=0;
  printf("Waiting for enter...\n");
  asm("sti");
  loop_while_ptr_zero(&readdone);
  return idx;
}
