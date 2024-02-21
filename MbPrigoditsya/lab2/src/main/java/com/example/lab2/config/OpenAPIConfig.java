package com.example.lab2.config;

import java.util.List;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import io.swagger.v3.oas.models.OpenAPI;
import io.swagger.v3.oas.models.info.Contact;
import io.swagger.v3.oas.models.info.Info;
import io.swagger.v3.oas.models.info.License;
import io.swagger.v3.oas.models.servers.Server;
import io.swagger.v3.oas.annotations.tags.Tag;

@Configuration
public class OpenAPIConfig {
    @Bean
    public OpenAPI myOpenAPI() {

        Contact contact = new Contact();
        contact.setEmail("dimkapolitech@mail.ru");
        contact.setName("phantom");

        License mitLicense = new License().name("MIT License").url("https://choosealicense.com/licenses/mit/");

        Info info = new Info()
                .title("Lab2")
                .version("1.0")
                .contact(contact)
                .description("This API for security sysem.")
                .license(mitLicense);

        return new OpenAPI().info(info);
    }
}