#!/bin/bash
for ((i=1; i<=5; i++))
do
    {
        echo "PASS a"
        echo "NICK spammer$i"
        echo "USER spammer$i 0 * :realname$i"
        echo "JOIN #test"
        while true; do
            echo "PRIVMSG #test hello from spammer$i"
        done
    } | nc -C localhost 6667 &
done
