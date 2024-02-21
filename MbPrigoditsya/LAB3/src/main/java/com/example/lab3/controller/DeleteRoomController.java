package com.example.lab3.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class DeleteRoomController {

    @RequestMapping("/delete")
    public String welcome() throws Exception {
        return "delete.html"; //note that this says .html
    }
}