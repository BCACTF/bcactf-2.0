FROM ubuntu@sha256:86ac87f73641c920fb42cc9612d4fb57b5626b56ea2a19b894d0673fd5b4f2e9 AS build

RUN apt-get update -y && \
    apt-get install -y gcc && \
    rm -rf /var/lib/apt/lists/*

COPY src.c .
RUN gcc -o ib-lit src.c


FROM ubuntu@sha256:86ac87f73641c920fb42cc9612d4fb57b5626b56ea2a19b894d0673fd5b4f2e9

RUN useradd -m -d /home/ctf -u 12345 ctf
WORKDIR /home/ctf

COPY ynetd .
RUN chmod +x ynetd

COPY --from=build ib-lit ib-lit
COPY flag.txt .

RUN chown -R root:root /home/ctf

USER ctf
EXPOSE 9999
CMD ./ynetd -p 9999 ./ib-lit
