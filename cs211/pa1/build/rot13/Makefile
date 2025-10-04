SRCPATH=../../src/rot13
CC=gcc
CFLAGS=-g -std=c99 -Wall -Wvla -Werror -fsanitize=address,undefined

project: rot13

vpath %.c $(SRCPATH)
vpath %.h $(SRCPATH)

-include $(SRCPATH)/Makefile
