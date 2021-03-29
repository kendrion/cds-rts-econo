#!/bin/sh
BITRATE=`expr $2 \\* 1000`

ip link set $1 down
ip link set $1 type can bitrate $BITRATE
ip link set $1 up
