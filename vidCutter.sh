#!/bin/bash

OUTFILE="out.mp3"
##Example ffmpeg command
if [ -f $OUTFILE]; then
   rm -rf out.mp3
   echo "out.mp3 found and has been deleted"
fi
youtube-dl -f251 $1 -o - | ffmpeg -i pipe: -strict -2 out.mp3
