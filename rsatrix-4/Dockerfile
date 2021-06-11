FROM sagemath/sagemath:9.0-py3

USER root
RUN useradd -m -d /home/ctf -u 12345 ctf
WORKDIR /home/ctf

RUN mkdir -m 700 .sage
RUN chown ctf:ctf .sage

COPY server.sage .
COPY flag.txt .

ENV HOME /home/ctf

USER ctf
EXPOSE 9999
CMD ["sage", "/home/ctf/server.sage"]
