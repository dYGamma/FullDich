package com.example.lab3.model;

import io.swagger.v3.oas.annotations.media.Schema;

@Schema
public class AccessToRoom {
    @Schema(
            description = "The unique id",
            name = "id",
            type = "long",
            example = "1")
    private long id = 0;
    @Schema(
            description = "The name of the user",
            name = "username",
            type = "String",
            example = "Dmitry")
    private String username;
    @Schema(
            description = "The name of the room",
            name = "roomName",
            type = "String",
            example = "Bathroom")
    private String roomName;
    @Schema(
            description = "The boolean variable to access to room",
            name = "accessToRoom",
            type = "boolean",
            example = "true")
    private boolean accessToRoom;

    public AccessToRoom() {

    }

    public AccessToRoom(String username, String roomName, boolean accessToRoom) {
        this.username = username;
        this.roomName = roomName;
        this.accessToRoom = accessToRoom;
    }

    public void setId(long id) {
        this.id = id;
    }

    public long getId() {
        return id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getRoomName() {
        return roomName;
    }

    public void setRoomName(String roomName) {
        this.roomName = roomName;
    }

    public boolean isAccessToRoom() {
        return accessToRoom;
    }

    public void setAccessToRoom(boolean isPublished) {
        this.accessToRoom = isPublished;
    }

    @Override
    public String toString() {
        return "AccessToRoom [id=" + id + ", username=" + username + ", desc=" + roomName + ", accessToRoom=" + accessToRoom + "]";
    }

}