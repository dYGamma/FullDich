FROM openjdk:17

RUN mkdir -p /usr/src/lab8consume

COPY target/lab8consumer.jar /usr/src/lab8consume/

WORKDIR /usr/src/lab8consume

ENTRYPOINT ["java", "-jar", "lab8consumer.jar"]