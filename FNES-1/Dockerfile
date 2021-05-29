FROM ubuntu@sha256:86ac87f73641c920fb42cc9612d4fb57b5626b56ea2a19b894d0673fd5b4f2e9

RUN apt-get update -y && \
    apt-get install -y python3 python3-pip && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m -d /home/ctf -u 12345 ctf
WORKDIR /home/ctf

COPY ynetd .
RUN chmod +x ynetd

COPY requirements.txt .
RUN pip install -r requirements.txt

COPY fnes1.py .
COPY flag.txt .
COPY key.txt .

RUN chown -R root:root /home/ctf
RUN chmod +x fnes1.py

USER ctf
EXPOSE 9999
CMD ./ynetd -p 9999 ./fnes1.py
