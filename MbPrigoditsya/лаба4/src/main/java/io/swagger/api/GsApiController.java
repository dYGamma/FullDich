package io.swagger.api;

import io.swagger.model.Error;
import io.swagger.model.Game;
import io.swagger.model.GameShop;
import com.fasterxml.jackson.databind.ObjectMapper;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.Parameter;
import io.swagger.v3.oas.annotations.enums.ParameterIn;
import io.swagger.v3.oas.annotations.responses.ApiResponses;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.media.ArraySchema;
import io.swagger.v3.oas.annotations.media.Content;
import io.swagger.v3.oas.annotations.media.Schema;
import io.swagger.v3.oas.annotations.security.SecurityRequirement;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.CookieValue;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RequestPart;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.Valid;
import javax.validation.constraints.*;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.security.Principal;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

@javax.annotation.Generated(value = "io.swagger.codegen.v3.generators.java.SpringCodegen", date = "2023-11-09T20:37:50.498499694Z[GMT]")
@RestController
public class GsApiController implements GsApi {

    private static final Logger log = LoggerFactory.getLogger(GsApiController.class);

    private final ObjectMapper objectMapper;

    private final HttpServletRequest request;

    @org.springframework.beans.factory.annotation.Autowired
    public GsApiController(ObjectMapper objectMapper, HttpServletRequest request) {
        this.objectMapper = objectMapper;
        this.request = request;
    }
    private AtomicInteger key = new AtomicInteger();
    public GameShop GShop = new GameShop();
    public ResponseEntity<Game> createGame(@Parameter(in = ParameterIn.DEFAULT, description = "", required=true, schema=@Schema()) @Valid @RequestBody Game body , @AuthenticationPrincipal Principal principal) {
        String accept = request.getHeader("Accept");
        if (principal == null){
            throw new ForbiddenException();
        }
        if (accept != null && accept.contains("application/json")) {
            synchronized (GShop){
                body.setId(key.incrementAndGet());
                GShop.add(body);
            }
            return new ResponseEntity<Game>(body ,HttpStatus.CREATED);
        }

        return new ResponseEntity<Game>(HttpStatus.NOT_IMPLEMENTED);
    }

    public ResponseEntity<Void> delGame(@Parameter(in = ParameterIn.PATH, description = "Id of Game", required=true, schema=@Schema()) @PathVariable("id") int id, @AuthenticationPrincipal Principal principal) {
        String accept = request.getHeader("Accept");
        if (principal == null){
            throw new ForbiddenException();
        }
        synchronized (GShop) {
            GShop.remove(id);
            return new ResponseEntity<Void>(HttpStatus.OK);
        }
    }

    public ResponseEntity<GameShop> getGs() {
        String accept = request.getHeader("Accept");
        if (accept != null && accept.contains("application/json")) {

            synchronized (GShop){
                return new ResponseEntity<GameShop>(GShop,HttpStatus.OK);
            }


        }

        return new ResponseEntity<GameShop>(HttpStatus.NOT_IMPLEMENTED);
    }

    public ResponseEntity<Game> getGameById(@Parameter(in = ParameterIn.PATH, description = "Id of game", required=true, schema=@Schema()) @PathVariable("id") Integer id) {
        String accept = request.getHeader("Accept");
        if (accept != null && accept.contains("application/json")) {
            synchronized (GShop){
                return new ResponseEntity<Game>(GShop.get(id),HttpStatus.OK);
            }
        }

        return new ResponseEntity<Game>(HttpStatus.NOT_IMPLEMENTED);
    }

}
