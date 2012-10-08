#!/bin/bash
valgrind --leak-check=full --track-origins=yes ./test.bin
