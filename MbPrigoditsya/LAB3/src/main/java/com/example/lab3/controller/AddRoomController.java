package com.example.lab3.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class AddRoomController {

    @RequestMapping("/add")
    public String welcome() throws Exception {
        return "add.html"; //note that this says .html
    }
}