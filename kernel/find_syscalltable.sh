#!/bin/bash

SYSCALL_ADDRESS=$(grep sys_call_table /boot/System.map-$(uname -r) | grep -v "ia32" | awk '{ print $1 }' ) 

echo "#define SYS_CALL_ADDRESS 0x${SYSCALL_ADDRESS}" > syscall_table.h
