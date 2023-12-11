#!/bin/bash

{
    echo "PASS a"
    echo "NICK spammer"
    echo "USER spammer 0 * :realname"
    echo "JOIN #test"
    while true line; do
        echo "PRIVMSG #test hello"
    done
} | nc -C localhost 6667
