FROM ubuntu@sha256:86ac87f73641c920fb42cc9612d4fb57b5626b56ea2a19b894d0673fd5b4f2e9

RUN apt-get update -y && \
    apt-get install -y gcc && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m -d /home/ctf -u 12345 ctf
WORKDIR /home/ctf

COPY main.c .
RUN gcc -o story2 main.c
