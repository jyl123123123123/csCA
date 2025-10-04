SRCPATH=../../src/bst
CC=gcc
CFLAGS=-g -std=c99 -Wall -Wvla -Werror -fsanitize=address,undefined

project: bst

vpath %.c $(SRCPATH)
vpath %.h $(SRCPATH)

-include $(SRCPATH)/Makefile
