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
   rm -rf $OUTFILE
   echo "$OUTFILE found and has been deleted"
fi
##One liner
#youtube-dl -f251 $INFILE -o - | ffmpeg -i pipe: -strict -2 $OUTFILE
VIDEO=$(youtube-dl -f251 $INFILE -o "%(format_id)s.%(ext)s" | grep "Destination:" | awk '{ print substr($0, index($0,$3)) }')
echo "OUTPUT FOR \$VIDEO: $VIDEO"
ffmpeg -i $VIDEO -vn -ar 44100 -ac 2 -ab 192k -f mp3 $OUTFILE
