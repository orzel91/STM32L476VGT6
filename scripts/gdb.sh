#!/bin/sh
session="gdb"

tmux has-session -t $session 2>/dev/null

if [ "$?" -eq 0 ] ; then
  echo "Session already exists"
else

# create a new tmux session and run gdb_server
tmux new-session -d -s $session 'JLinkGDBServerCLExe -device STM32L476VG -if SWD -speed 4500'

# Split pane 1 horizontal and run gdb_client
tmux split-window -h 'arm-none-eabi-gdb build/STM32L476VGT6.elf'

# Execute commands
tmux send-keys '' C-m #Dummy enter needed for gdb
tmux send-keys 'target remote localhost:2331' C-m 
tmux send-keys 'monitor reset' C-m 

# Finished setup, attach to the tmux session!
tmux attach-session -t $session
fi
