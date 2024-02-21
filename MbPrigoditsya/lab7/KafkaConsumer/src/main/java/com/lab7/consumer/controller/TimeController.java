package com.lab7.consumer.controller;


import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.lab7.consumer.model.ITimeRepository;
import com.lab7.consumer.model.Time;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.List;

@Controller
public class TimeController {

    private final ITimeRepository repository;

    static final Logger log =
            LoggerFactory.getLogger(TimeController.class);

    @Autowired
    public TimeController(ITimeRepository repository) {
        this.repository = repository;
    }


    @GetMapping("/")
    public String index(Model model) {

        List<Time> objs = this.repository.findAll();
        model.addAttribute("obj_list", objs);
        return "index";
    }

    @KafkaListener(topics = "TRSIS7", groupId = "group1")
    void listener(String data) {
        log.info("Received message in group1: " + data);

        ObjectMapper objectMapper = new ObjectMapper();

        try {
            JsonNode jsonNode = objectMapper.readTree(data);

            // Проверка наличия поля "action"
            if (jsonNode.has("action")) {
                String action = jsonNode.get("action").asText();

                // Обработка действия "delete"
                if ("delete".equals(action)) {
                    repository.deleteById(jsonNode.get("id").asInt());
                    return; // Выход из метода после обработки удаления
                }
            }

            Time obj = objectMapper.readValue(data, Time.class);
            repository.save(obj);

        } catch (IOException e) {
            e.printStackTrace();

        }

    }

}
