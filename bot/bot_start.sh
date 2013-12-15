#!/bin/bash

#CURL VARS
UA="\"Mozilla/5.0\""
INIT_URL="https://www.google.com"
COOKIE_FILE="cookie_jar"
#AWK VARS
AWKFILE="extract_id.awk"

function start {
  curl $INIT_URL --user-agent $UA --cookie-jar $COOKIE_FILE
  #awk -f $AWKFILE < $HEADER_FILE
  cat $HEADER_FILE
}
