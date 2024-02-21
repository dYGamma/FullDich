package io.swagger.configuration;

import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.ViewControllerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurerAdapter;

@Configuration
public class ControllersConfig extends WebMvcConfigurerAdapter {

    @Override
    public void addViewControllers(ViewControllerRegistry registry) {
        registry.addViewController("/rooms").setViewName("rooms");
        registry.addViewController("/login").setViewName("login");
        registry.addViewController("/error").setViewName("error");
        registry.addViewController("/").setViewName("rooms");
    }

}