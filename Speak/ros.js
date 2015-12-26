var ws = null;

var recognizing = false;



var ros = new ROSLIB.Ros();

// If there is an error on the backend, an 'error' emit will be emitted.
ros.on('error', function(error) {
  document.getElementById('connecting').style.display = 'none';
  document.getElementById('connected').style.display = 'none';
  document.getElementById('closed').style.display = 'none';
  document.getElementById('error').style.display = 'inline';
  console.log(error);
});

// Find out exactly when we made a connection.
ros.on('connection', function() {
  console.log('Connection made!');
  document.getElementById('connecting').style.display = 'none';
  document.getElementById('error').style.display = 'none';
  document.getElementById('closed').style.display = 'none';
  document.getElementById('connected').style.display = 'inline';
});

ros.on('close', function() {
  console.log('Connection closed.');
  document.getElementById('connecting').style.display = 'none';
  document.getElementById('connected').style.display = 'none';
  document.getElementById('closed').style.display = 'inline';
});




// PUBLISH
var cmdVel = new ROSLIB.Topic({
    ros : ros,
    name : '/speech_data',
    messageType : 'projectx/SpeechData'
  });






        // if(e.data == "stop"){
            
        //         console.log("STOP");  
        //         recognizing = false;
        //         recognition.stop();
            

        // }else if(e.data == "start"){
          
        //   try {
        //         console.log("START");
        //         if(recognizing == false){
        //           recognition.start();
        //           recognizing = true;
        //         };
        //   }
        //   catch(err) {
        //       console.log("çakışma var");



        //       setTimeout(function () {
        //         console.log("START 2");
        //         if(recognizing == false){
        //           recognition.start();
        //           recognizing = true;
        //         };
        //       }, 1000);
              
          

$(function(){
    ros.connect('ws://localhost:9090');
})








var hata = false;



// Başlangıçta Çalıştır
$(function(){
  startButton();
})

// Uyarı
showInfo('info_start');


var final_transcript = '';
var start_timestamp;

if (!('webkitSpeechRecognition' in window)) {
  upgrade();
} else {
  var recognition = new webkitSpeechRecognition();
  
  recognition.continuous = true;
  recognition.interimResults = true;

  recognition.onstart = function() {
    tanima = true;
    recognizing = true;
    console.log("onstart");
    showInfo('info_speak_now');
  };

  recognition.onerror = function(event) {

    console.log("HATA");

    hata = true;
    recognizing = false;
    
    if (event.error == 'no-speech') {
    }
    if (event.error == 'audio-capture') {
    }
    if (event.error == 'not-allowed') {
    }

  };

  recognition.onend = function() {

      console.log("on end");

      if(recognizing == false){
        console.log("on end geçti");

        tanima = false;

        if(hata == true){
          console.log("on end -> HATA TRUE");
          startButton();
          hata = false;
        }
      }else{
        location.reload();
      }
    
  };

  recognition.onresult = function(event) {

    var interim_transcript = '';
    // if (typeof(event.results) == 'undefined') {
    //   recognition.onend = null;
    //   recognition.stop();
    //   upgrade();
    //   return;
    // }

    var deger;
    var deger_final;


    // interim_transcript -> Söylendiği anda gelen feedback
    // final_transcript -> Kelime tam olarak doğrulandığında gelen feedback

    // Sonuç -> final'i beklemek zaman alıyor. interim kullanılarak işlem yapıldı
    // interim onaylanınca feedback boş string olarak geliyor
    // Feedback boş olduğunda veri websocket üzerinden gonderiliyor

    for (var i = event.resultIndex; i < event.results.length; ++i) {
      if (event.results[i].isFinal) {
        final_transcript += event.results[i][0].transcript; 
        deger_final = event.results[i][0].confidence; 
        
        $('div#ilk').append(final_transcript+" -- ");
        $('div#ilk').append(deger_final);
        $('div#ilk').append("<br><br>");

      } else {
        interim_transcript += event.results[i][0].transcript;
        deger = event.results[i][0].confidence;
      }
    }

    // SEND

      var cumle = $.trim(linebreak(interim_transcript));

      if(interim_transcript == ""){

        ws.send("*-*");

        $('div#son').append(" -- ");
        $('div#son').append("<br>");  

      }else{

        ws.send(cumle+"-"+deger);

        $('div#son').append(cumle+" -- "+deger);
        $('div#son').append("<br>");  
      }
    
  };
}



function upgrade() {
  alert("upgrade");
  start_button.style.visibility = 'hidden';
  showInfo('info_upgrade');
}

var two_line = /\n\n/g;
var one_line = /\n/g;
function linebreak(s) {
  return s.replace(two_line, '<p></p>').replace(one_line, '<br>');
}

var first_char = /\S/;
function capitalize(s) {
  return s.replace(first_char, function(m) { return m.toUpperCase(); });
}


// BASLA
function startButton() {
  recognition.lang = 'tr-TR';
  recognition.maxAlternatives = 1;
  recognition.start();
  showInfo('info_allow');
}


function showInfo(s) {
  if (s) {
    for (var child = info.firstChild; child; child = child.nextSibling) {
      if (child.style) {
        child.style.display = child.id == s ? 'inline' : 'none';
      }
    }
    info.style.visibility = 'visible';
  } else {
    info.style.visibility = 'hidden';
  }
}