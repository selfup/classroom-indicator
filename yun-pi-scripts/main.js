var http = require('http');

var url = 'http://intelyzine.com/api/v1/classroom_bs';
var five = require("johnny-five");
var board = new five.Board();

var makeRequest = function(onEnd) {
  http.get(url, function(res){
    var body = '';

    res.on('data', function(chunk){
      body += chunk;
    });

    res.on('end', function(){
      var responseB = JSON.parse(body);
      console.log(responseB[0].cohort);
      console.log(responseB[0].teacher);
      onEnd(responseB[0]);
    });
  });
};

board
  .on('error', function(e){
    console.log("Error: ", e);
  })
  .on("ready", function() {
    // Create a standard `led` component instance
    var led = new five.Led(13);

    function run() {
      makeRequest(function(klass) {
        // "blink" the led in 500ms
        // on-off phase periods
        if (klass.cohort === "1507" ) {
          led.blink(6000);
        };
      })
    }
    var second = 1000;
    setInterval(run, 10*second)
  });
