FROM ubuntu:latest AS compile
WORKDIR /app/dante
COPY . .
RUN apt-get update && apt-get install -y make gcc && apt-get clean
RUN make re

FROM ubuntu:latest
COPY --from=compile /app/dante/generator/ /
ENTRYPOINT ["/generator"]
CMD []
