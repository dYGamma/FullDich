package com.lab7.consumer.model;

import jakarta.persistence.*;
import lombok.Data;
import lombok.Getter;



@Data
@Entity
@Table(name = "Times")
public class Time {
  public Time(Integer id, String name, Integer type){
    this.id = id;
    this.name = name;
    this.type =  type;
  }
  @Id
  @GeneratedValue (strategy = GenerationType.IDENTITY)
  @Column(name = "id")
  public Integer id;

  public Time() {

  }

  public void setId(Integer id) {
    this.id = id;
  }
  public Integer GetId(){
    return id;
  }


  @Getter
  @Column(name = "name")
  private String name;

  public void setName(String name) {
    this.name = name;
  }

  @Getter
  @Column(name = "type")
  private Integer type;

  public void setType(Integer type) {
    this.type = type;
  }
}
