FROM ubuntu@sha256:86ac87f73641c920fb42cc9612d4fb57b5626b56ea2a19b894d0673fd5b4f2e9

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update -y && \
    apt-get install -y sagemath --no-install-recommends && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m -d /home/ctf -u 12345 ctf
WORKDIR /home/ctf

COPY ynetd .
RUN chmod +x ynetd

COPY rt3.sage .
COPY flag.txt .

RUN chown -R root:root /home/ctf
RUN chown ctf:ctf /home/ctf
RUN chmod +x rt3.sage

USER ctf
EXPOSE 9999
CMD ./ynetd -p 9999 ./rt3.sage
