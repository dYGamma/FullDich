FROM openjdk:17

RUN mkdir -p /usr/src/lab8
COPY target/lab78.jar /usr/src/lab8/
WORKDIR /usr/src/lab8

ENTRYPOINT ["java", "-jar", "lab78.jar"]
