#!/bin/sh
gcc -c ft*
ar -rc libft.a *.o
ranlib libft.a
