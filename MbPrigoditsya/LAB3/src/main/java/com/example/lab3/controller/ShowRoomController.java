package com.example.lab3.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class ShowRoomController {

    @RequestMapping("/")
    public String welcome() throws Exception {
        return "show.html"; //note that this says .html
    }
}