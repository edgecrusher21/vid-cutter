#!/bin/bash

INFILE=$1
OUTFILE="out.mp3"
##Check to see if url is valid
if [ -z $INFILE ]; then
    echo "Please enter in a valid file"
    exit 0
elif [ -z $( echo $INFILE | grep "watch?v=") ]; then
    echo "Please enter in a valid youtube URL"
    exit 0
fi
##Example ffmpeg command
if [ -f $OUTFILE ]; then
   rm -rf out.mp3
   echo "out.mp3 found and has been deleted"
fi
youtube-dl -f251 $INFILE -o - | ffmpeg -i pipe: -strict -2 $OUTFILE
