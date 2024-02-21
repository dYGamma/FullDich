package com.example.lab2.service;

import java.util.ArrayList;
import java.util.List;

import com.example.lab2.model.AccessToRoom;
import org.springframework.stereotype.Service;

@Service
public class AccessToRoomService {

    static List<AccessToRoom> accessToRooms = new ArrayList<AccessToRoom>();
    static long id = 0;

    public List<AccessToRoom> findAll() {
        return accessToRooms;
    }

    public List<AccessToRoom> findByTitleContaining(String title) {
        return accessToRooms.stream().filter(accessToRoom -> accessToRoom.getUsername().contains(title)).toList();
    }

    public AccessToRoom findById(long id) {
        return accessToRooms.stream().filter(accessToRoom -> id == accessToRoom.getId()).findAny().orElse(null);
    }

    public AccessToRoom save(AccessToRoom accessToRoom) {
        // update AccessToRoom
        if (accessToRoom.getId() != 0) {
            long _id = accessToRoom.getId();

            for (int idx = 0; idx < accessToRooms.size(); idx++)
                if (_id == accessToRooms.get(idx).getId()) {
                    accessToRooms.set(idx, accessToRoom);
                    break;
                }

            return accessToRoom;
        }

        // create new AccessToRoom
        accessToRoom.setId(++id);
        accessToRooms.add(accessToRoom);
        return accessToRoom;
    }

    public void deleteById(long id) {
        accessToRooms.removeIf(accessToRoom -> id == accessToRoom.getId());
    }

    public void deleteAll() {
        accessToRooms.removeAll(accessToRooms);
    }

    public List<AccessToRoom> findByPublished(boolean isPublished) {
        return accessToRooms.stream().filter(accessToRoom -> isPublished == accessToRoom.isAccessToRoom()).toList();
    }
}
