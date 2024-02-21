package com.lab7.consumer.model;


import org.springframework.data.jpa.repository.JpaRepository;

public interface ITimeRepository extends JpaRepository<Time, Integer> {
}
