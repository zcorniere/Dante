FROM registry.dragonalpha.fr/infra/ci/minimal:latest AS compile
WORKDIR /app/dante
COPY . .
RUN make docker

FROM alpine:latest
COPY --from=compile /app/dante/generator/ /
ENTRYPOINT ["/generator"]
CMD []
