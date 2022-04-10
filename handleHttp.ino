void handleRoot() {
  if (captivePortal()) {  // If caprive portal redirect instead of displaying the page.
    return;
  }
  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  server.sendHeader("Pragma", "no-cache");
  server.sendHeader("Expires", "-1");

  String Page;
  Page += F("<!DOCTYPE html>"
            "<html lang='pt-br'>"
            "<head>"
            "    <meta charset='UTF-8'>"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
            "    <meta name='viewport' content='width=device-width, initial-scale=1.0'>"
            "    <title>Laboratorio 16</title>"
            "    <style>"
            "       .bcon{ color: green };"
            "       .bcoff{ color: brown };"
            "    </style>"
            "</head>"
            "<body>"
            "    <div class='container'>"
            "        <h1>Lab 16 controle</h1>"
            "        <div class='parte-botoes'>"
            "<div class='coluna-esquerda'>");
  if(BC1_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc1'>Bancada 01</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc1'>Bancada 01</a>"));
  }
  if(BC2_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc2'>Bancada 02</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc2'>Bancada 02</a>"));
  }
  if(BC3_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc3'>Bancada 03</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc3'>Bancada 03</a>"));
  }
  if(BC4_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc4'>Bancada 04</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc4'>Bancada 04</a>"));
  }
  if(BC5_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc5'>Bancada 05</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc5'>Bancada 05</a>"));
  }
  if(BC6_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc6'>Bancada 06</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc6'>Bancada 06</a>"));
  }
  //-------------------------------------------------
  Page += F("</div>"
            "<div class='coluna-direita'>");
  if(BC7_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc7'>Bancada 07</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc7'>Bancada 07</a>"));
  }
  if(BC8_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc8'>Bancada 08</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc8'>Bancada 08</a>"));
  }
  if(BC9_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc9'>Bancada 09</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc9'>Bancada 09</a>"));
  }
  if(BC10_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc10'>Bancada 10</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc10'>Bancada 10</a>"));
  }
  if(BC11_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc11'>Bancada 11</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc11'>Bancada 11</a>"));
  }
  if(BC12_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc12'>Bancada 12</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc12'>Bancada 12</a>"));
  }
  //-------------------------------------------------
  Page += F("           </div>"
            "        </div>"
            "    </div>"
            "</body>"
            "</html>");

  server.send(200, "text/html", Page);
}

boolean captivePortal() {
  if (!isIp(server.hostHeader()) && server.hostHeader() != (String(myHostname) + ".local")) {
    Serial.println("Request redirected to captive portal");
    server.sendHeader("Location", String("http://") + toStringIp(server.client().localIP()), true);
    server.send(302, "text/plain", "");  // Empty content inhibits Content-length header so we have to close the socket ourselves.
    server.client().stop();              // Stop is needed because we sent no content length
    return true;
  }
  return false;
}

void handleNotFound() {
  if (captivePortal()) {  // If caprive portal redirect instead of displaying the error page.
    return;
  }
  String message = F("File Not Found\n\n");
  message += F("URI: ");
  message += server.uri();
  message += F("\nMethod: ");
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += F("\nArguments: ");
  message += server.args();
  message += F("\n");

  for (uint8_t i = 0; i < server.args(); i++) { message += String(F(" ")) + server.argName(i) + F(": ") + server.arg(i) + F("\n"); }
  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  server.sendHeader("Pragma", "no-cache");
  server.sendHeader("Expires", "-1");
  server.send(404, "text/plain", message);
}
