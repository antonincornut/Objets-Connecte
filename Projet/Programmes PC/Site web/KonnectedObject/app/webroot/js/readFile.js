setInterval(function() {
  $.getJSON("/KonnectedObject/files/datas.json", function(json) {
    document.getElementById("temp").innerHTML = json.t+" °c";
    document.getElementById("wind").innerHTML = json.w+" km/h";
    document.getElementById("light").innerHTML = json.l+" intensité";
    if (json.t != 'null') {
      $( "img#indicator-temp" ).attr({
        src: "/KonnectedObject/img/green.png",
        title: "jQuery",
        alt: "Green Logo",
        width: "50px"
      });
    }
    else {
      $( "img#indicator-temp" ).attr({
        src: "/KonnectedObject/img/red.png",
        title: "jQuery",
        alt: "Red logo",
        width: "40px"
      });
    }

    if (json.w != 'null') {
      $( "img#indicator-wind" ).attr({
        src: "/KonnectedObject/img/green.png",
        title: "jQuery",
        alt: "Green Logo",
        width: "50px"
      });
    }
    else {
      $( "img#indicator-wind" ).attr({
        src: "/KonnectedObject/img/red.png",
        title: "jQuery",
        alt: "Red logo",
        width: "40px"
      });
    }

    if (json.l != 'null') {
      $( "img#indicator-light" ).attr({
        src: "/KonnectedObject/img/green.png",
        title: "jQuery",
        alt: "Green Logo",
        width: "50px"
      });
    }
    else {
      $( "img#indicator-light" ).attr({
        src: "/KonnectedObject/img/red.png",
        title: "jQuery",
        alt: "Red logo",
        width: "40px"
      });
    }
  });
}, 1000);
