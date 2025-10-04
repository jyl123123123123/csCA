SRCPATH=../../src/anagram
CC=gcc
CFLAGS=-g -std=c99 -Wall -Wvla -Werror -fsanitize=address,undefined

project: anagram

vpath %.c $(SRCPATH)
vpath %.h $(SRCPATH)

-include $(SRCPATH)/Makefile
