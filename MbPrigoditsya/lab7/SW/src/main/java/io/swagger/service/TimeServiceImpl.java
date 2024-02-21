package io.swagger.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ObjectNode;
import io.swagger.db.TimeRepository;
import org.apache.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.stereotype.Service;
import io.swagger.model.Time;

@Service
public class TimeServiceImpl implements TimeService {
    private final static Logger log = Logger.getLogger(TimeServiceImpl.class);

    @Autowired
    private TimeRepository tRep;

    @Value(value = "${kafka.topicName}")
    private String kafkaTopicName;

    @Autowired
    private KafkaTemplate<String, String> kafkaTemplate;

    @Override
    public Iterable<Time> findByType(Integer type){
        return tRep.findByType(type);
    }

    @Override
    public Iterable<Time> listAll() {
        return tRep.findAll();
    }

    @Override
    public void delete(Integer id) {
        try {
            tRep.deleteById(id);
        } catch (org.springframework.dao.EmptyResultDataAccessException e) {
            return;
        }

        log.info("DELETE BY ID" + id);

        try {
            // Создание JSON-объекта для удаления
            ObjectMapper objectMapper = new ObjectMapper();
            ObjectNode deleteJson = objectMapper.createObjectNode();
            deleteJson.put("action", "delete");
            deleteJson.put("id", id);

            // Преобразование JSON-объекта в строку
            String jsonToDelete = objectMapper.writeValueAsString(deleteJson);

            // Отправка JSON в топик Kafka
            kafkaTemplate.send(kafkaTopicName, jsonToDelete);

            log.info("Deletion message sent to Kafka successfully, id: " + id);
        } catch (JsonProcessingException e) {
            log.error("Error converting deletion message to JSON: " + e.getMessage(), e);
        } catch (Exception e) {
            log.error("Error sending Exhibit deletion message to Kafka: " + e.getMessage(), e);
        }

    }

    @Override
    public Time add(Integer id, String name, Integer type) {

        Time time = new Time(id, name, type);
        tRep.save(time);

        try {
            ObjectMapper objectMapper = new ObjectMapper();
            String jsonTime = objectMapper.writeValueAsString(time);
            log.info("Send to kafka topic: " + kafkaTopicName);
            log.info("Converted to JSON: " + jsonTime);

            kafkaTemplate.send(kafkaTopicName, jsonTime);

        log.info("Sending to Kafka successfully");
        } catch (JsonProcessingException e) {
            log.error("Error converting to JSON: " + e.getMessage(), e);
        }
        catch (Exception e){
            log.error("!Error converting to JSON: " + e.getMessage(), e);
        }

        return time;
    }

    @Override
    public Time getById(Integer id) {

        return tRep.findById(id).orElse(null);
    }

}
