#!/usr/bin/env bash

echo "Beginning the debugging session"
	echo "Enter the value of L"
	read L
	echo "Enter the value of p"
	read p
	echo "Enter the value of SEED"
	read SEED
	echo "Launching debugging session witht he given arguments"
	gdb --tui --args ./foo_debug ${L} ${p} ${SEED}
