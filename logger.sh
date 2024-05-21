#!/bin/bash

# variable init
current=$SECONDS
timeout=3
time_diff=0
flag=false

while :
  do
    if inotifywait -t 1 -qq -r -e CREATE -e MODIFY /home/rosh/catkin_ws/src/auto-log-test/logs/; then
      flag=true
      event_time=$SECONDS
    fi

    current=$SECONDS
    time_diff=$((current - event_time))
    
    if [[ "$time_diff" -gt "$timeout" && "$flag" = true ]]; then
      echo "poop"
      git -C /home/rosh/catkin_ws/src/auto-log-test add . && git -C /home/rosh/catkin_ws/src/auto-log-test commit -m 'auto commit' && git -C /home/rosh/catkin_ws/src/auto-log-test push origin master
      flag=false
    fi

    sleep 0.05
  done