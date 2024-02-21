package com.example.lab2.controller;

import java.util.ArrayList;
import java.util.List;

import com.example.lab2.model.AccessToRoom;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.example.lab2.service.AccessToRoomService;

@CrossOrigin(origins = "http://localhost:8081")
@RestController
@RequestMapping("/api")
public class AccessToRoomController {
    @Autowired
    AccessToRoomService accessToRoomService;

    @GetMapping("/access-to-room")
    public ResponseEntity<List<AccessToRoom>> getAllAccessToRooms(@RequestParam(required = false) String username) {
        try {
            List<AccessToRoom> accessToRooms = new ArrayList<AccessToRoom>();

            if (username == null)
                accessToRoomService.findAll().forEach(accessToRooms::add);
            else
                accessToRoomService.findByTitleContaining(username).forEach(accessToRooms::add);

            if (accessToRooms.isEmpty()) {
                return new ResponseEntity<>(HttpStatus.NO_CONTENT);
            }

            return new ResponseEntity<>(accessToRooms, HttpStatus.OK);
        } catch (Exception e) {
            return new ResponseEntity<>(null, HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    @GetMapping("/access-to-room/{id}")
    public ResponseEntity<AccessToRoom> getAccessToRoomById(@PathVariable("id") long id) {
        AccessToRoom accessToRoom = accessToRoomService.findById(id);

        if (accessToRoom != null) {
            return new ResponseEntity<>(accessToRoom, HttpStatus.OK);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }

    @PostMapping("/access-to-room")
    public ResponseEntity<AccessToRoom> createAccessToRoom(@RequestBody AccessToRoom accessToRoom) {
        try {
            AccessToRoom _accessToRoom = accessToRoomService
                    .save(new AccessToRoom(accessToRoom.getUsername(), accessToRoom.getRoomName(), accessToRoom.isAccessToRoom()));
            return new ResponseEntity<>(_accessToRoom, HttpStatus.CREATED);
        } catch (Exception e) {
            return new ResponseEntity<>(null, HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    @PutMapping("/access-to-room/{id}")
    public ResponseEntity<AccessToRoom> updateAccessToRoom(@PathVariable("id") long id, @RequestBody AccessToRoom accessToRoom) {
        AccessToRoom _accessToRoom = accessToRoomService.findById(id);

        if (_accessToRoom != null) {
            _accessToRoom.setUsername(accessToRoom.getUsername());
            _accessToRoom.setRoomName(accessToRoom.getRoomName());
            _accessToRoom.setAccessToRoom(accessToRoom.isAccessToRoom());
            return new ResponseEntity<>( accessToRoomService.save(_accessToRoom), HttpStatus.OK);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }

    @DeleteMapping("/access-to-room/{id}")
    public ResponseEntity<HttpStatus> deleteAccessToRoom(@PathVariable("id") long id) {
        try {
            accessToRoomService.deleteById(id);
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } catch (Exception e) {
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }
}